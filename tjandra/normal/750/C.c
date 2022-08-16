#include<stdio.h>
#include<stdlib.h>
#define m 1000000007
typedef unsigned u;
u Nd[222222],Sd[222222],Si;
int Smax[222222],Smin[222222],L[222222],H[222222],Nr[222222],Sr[222222];
int main()
{
	u n,i=-1;
	int lo=-m,hi=m;
	for(scanf("%u",&n);++i<n;)
	scanf("%d%u",Nr+i,Nd+i);
	*Sr=*Nr;*Sd=*Nd;
	for(i=0;++i<n;)
	if(Nd[i]==Nd[i-1])
	{
		if(Smax[Si]<Sr[Si])Smax[Si]=Sr[Si];
		if(Smin[Si]>Sr[Si])Smin[Si]=Sr[Si];
		Sr[Si]+=Nr[i];
	}
	else
	{
		if(Sd[Si]==2&&Sr[Si]<=Smax[Si])goto NO;
		if(Sd[Si]==1&&Sr[Si]>=Smin[Si])goto NO;
		Sr[++Si]=Nr[i];
		Sd[Si]=Nd[i];
	}
	if(!Si++)
	{
		if(*Sd==1)printf("Infinity\n");
		if(*Sd==2)printf("%d\n",*Sr-*Smax+1899);
		return 0;
	}
	for(i=-1;++i<Si;)
	{
		if(Sd[i]==2)
		{
			L[i]=1900-Sr[i];
			H[i]=1899-Smax[i];
		}
		if(Sd[i]==1)
		{
			L[i]=1900-Smin[i];
			H[i]=1899-Sr[i];
		}
	}
	for(i=-1;++i<Si-1;)
	{
		if(lo<L[i])lo=L[i];
		if(hi>H[i])hi=H[i];
		if(lo>hi)goto NO;
		lo+=Sr[i];
		hi+=Sr[i];
	}
	if(Sd[i]==1&&lo<L[i])lo=L[i];
	if(Sd[i]==2&&hi>H[i])hi=H[i];
	if(lo>hi)goto NO;
	lo+=Sr[i];
	hi+=Sr[i];
	printf("%d\n",hi);
	return 0;
	NO:;printf("Impossible\n");
	return 0;
}