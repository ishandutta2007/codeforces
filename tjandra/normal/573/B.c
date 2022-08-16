#include<stdio.h>
typedef unsigned u;
u min(u a,u b){return a>b?b:a;}
u max(u a,u b){return a>b?a:b;}
u N[111111],L[111111],R[111111];
int main()
{
	u n,i=-1,r=0,m;
	for(scanf("%u",&n);++i<n;scanf("%u",N+i));
	for(i=-1,m=0;++i<n;L[i]=m)if(++m>N[i])m=N[i];
	for(i= n,m=0;i--;R[i]=m)if(++m>N[i])m=N[i];
	for(i=-1;++i<n;)r=max(r,min(L[i],R[i]));
	printf("%u\n",r);
	return 0;
}