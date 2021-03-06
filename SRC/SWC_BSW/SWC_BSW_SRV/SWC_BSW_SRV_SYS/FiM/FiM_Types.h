/**
 * \file
 *
 * \brief AUTOSAR FiM
 *
 * This file contains the implementation of the AUTOSAR
 * module FiM.
 *
 * \author Elektrobit Automotive GmbH, 91058 Erlangen, Germany
 *
 * Copyright 2005 - 2013 Elektrobit Automotive GmbH
 * All rights exclusively reserved for Elektrobit Automotive GmbH,
 * unless expressly agreed to otherwise.
 */
#if (!defined FIM_TYPES_H)
#define FIM_TYPES_H

/*==================[inclusions]============================================*/
/* !LINKSTO dsn.FiM.IncludeStr,1 */

#include <Std_Types.h>                            /* AUTOSAR standard types */
#include <TSAutosar.h>                        /* EB specific standard types */

#include <FiM_Cfg.h>                     /* Module public generated symbols */

#if (FIM_INCLUDE_RTE == STD_ON)
#include <Rte_FiM_Type.h>
#endif

/*==================[type definitions]=======================================*/

/*------------------[FiM_ConfigType]-----------------------------------------*/

/* For post-build variant this type might be defined in FiM_Cfg.h
   This is to support the post-build time multiple configuration data
   structure. Configuration structure of type pointer to FiM_ConfigType is
   passed to FiM_Init(). Although this is not used during pre-compile
   configuration, EcuM always calls FiM_Init() with the name of a referenced
   FiMConfigSet (as per R4.0 configuration schema) container.
*/

#if (FIM_INCLUDE_RTE == STD_OFF)

/*------------------[FiM_FunctionIdType]-------------------------------------*/
#ifndef RTE_TYPE_FiM_FunctionIdType
#define RTE_TYPE_FiM_FunctionIdType

/** \brief Identification of a function by assigned FunctionId. The FunctionId
 ** is configured in the FiM.
 **
 ** Small and encapsulated systems will only use uint8 for FunctionId
 ** definition due to resource optimization. Systems with enough resources shall
 ** use uint16. For Functions using uint8, adaptions may be required to
 ** ensure compatibility between different data types. */
#if (FIM_FID_NUM <= 256U)
typedef uint8  FiM_FunctionIdType;
#else
typedef uint16 FiM_FunctionIdType;
#endif
#endif

#else /* FIM_INCLUDE_RTE == STD_ON */
/* Autosar FiM  ASR 4.0.3 specification wrongly defines the RTE generated type
   as FunctionIdType. To be inline with specification following typedef is
   required which shall be removed once rfc#52203 is implemented.
*/
typedef FunctionIdType FiM_FunctionIdType;
#endif

#endif /* if !defined( FIM_TYPES_H ) */
/*==================[end of file]===========================================*/
