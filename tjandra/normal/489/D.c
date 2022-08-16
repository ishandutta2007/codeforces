#include<stdio.h>
#include<stdlib.h>
#define bfr 128
typedef long long unsigned u64;
typedef unsigned u;
u *E[3333],Ei[3333],Ea[3333],S[3333],F[3333];
int main()
{
	u n,e,i,j,k,l;u64 r;
	scanf("%u%u",&n,&e);
	for(i=0;i<n;Ea[i++]=bfr)E[i]=(u*)calloc(bfr,sizeof(u));
	for(i=1;i<n;++i)F[i+1]=F[i]+i;
	while(e--)
	{
		scanf("%u%u",&i,&j);--i;--j;
		E[i][Ei[i]]=j;if(++Ei[i]==Ea[i])
		{Ea[i]+=bfr;E[i]=(u*)realloc(E[i],Ea[i]*sizeof(u));}
	}
	for(i=r=0Lu;i<n;++i)
	{
		for(j=0;j<Ei[i];++j)
		for(l=E[i][j],k=0;k<Ei[l];++k)++S[E[l][k]];
		for(j=0;j<n;S[j++]=0)if(j!=i)r+=F[S[j]];
	}
	printf("%I64u\n",r);
	return 0;
}