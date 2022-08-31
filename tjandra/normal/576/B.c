#include<stdio.h>
typedef unsigned u;
u P[111111],C[111111],V[111111];
int main()
{
	u n,i=0,j,k,e=0,f=0;
	for(scanf("%u",&n);++i<=n;P[i]=k)
	{
		scanf("%u",&k);
		if(k==i)e=i;
	}
	if(e)
	{
		printf("YES\n");
		for(i=0;++i<=n;)if(i!=e)printf("%u %u\n",e,i);
		return 0;
	}
	for(i=0;++i<=n;)if(!C[i])
	{
		for(j=i,k=0;;j=P[j])
		{
			++k;
			if(P[j]==i)break;
		}
		for(j=i;;j=P[j])
		{
			C[j]=k;
			if(P[j]==i)break;
		}
		if(k&1){printf("NO\n");return 0;}
		if(k==2){e=i;f=P[i];}
	}
	if(!e){printf("NO\n");return 0;}
	V[e]=V[f]=1;
	printf("YES\n%u %u\n",e,f);
	for(i=0;++i<=n;)if(!V[i])
	{
		for(j=e,k=i;;j=P[j],k=P[k])
		{
			printf("%u %u\n",j,k);
			V[k]=1;
			if(P[k]==i)break;
		}
	}
	return 0;
}