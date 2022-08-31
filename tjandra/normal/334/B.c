#include<stdio.h>
#include<stdlib.h>
typedef unsigned u;
int F(const void*x,const void*y){return(*(u*)x>=*(u*)y)+(*(u*)x>*(u*)y)-1;}
int main()
{
	u A[8],B[8],a[8],b[8],i,j,k,l;
	for(i=0;i<8;i++)
	{
		scanf("%u%u",&A[i],&B[i]);
		a[i]=A[i];b[i]=B[i];
	}
	qsort(a,8,sizeof(u),F);
	qsort(b,8,sizeof(u),F);
	for(i=j=1;i<8;i++)if(a[i]!=a[i-1]){a[j++]=a[i];}
	if(j!=3)goto die;
	for(i=j=1;i<8;i++)if(b[i]!=b[i-1]){b[j++]=b[i];}
	if(j!=3)goto die;
	for(i=j=0;i<8;i++)
	{
		for(k=0;k<3;k++)if(a[k]==A[i])break;
		l=3*k;
		for(k=0;k<3;k++)if(b[k]==B[i])break;
		l+=k;
		j|=1u<<l;
	}
	if(j!=495){die:;printf("ugly\n");}
	else printf("respectable\n");
	return 0;
}