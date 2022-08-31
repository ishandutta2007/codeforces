#include<stdio.h>
typedef unsigned u;
u A[1111],Ai,P[1111],Pi;
u isprime(u n)
{
	if(n==2)return 1;u i;
	for(i=0;P[i]*P[i]<=n;++i)if(n%P[i]==0)return 0;
	P[Pi++]=n;
	return 1;
}
int main()
{
	u n,i,j;
	P[Pi++]=2;
	scanf("%u",&n);
	for(i=1;++i<=n;)
	{
		if(isprime(i))
		for(j=1;(j*=i)<=n;)A[Ai++]=j;
	}
	for(printf("%u\n",Ai),i=-1;++i<Ai;printf("%u%c",A[i],i+1==Ai?'\n':' '));
	return 0;
}