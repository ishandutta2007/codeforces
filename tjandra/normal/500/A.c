#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
int main()
{
	u N,k,n=1,i=0,j,ok=0;
	for(scanf("%u%u",&N,&k);++i<N;)
	{
		scanf("%u",&j);
		if(n==k)ok=1;
		if(i==n)n+=j;
		if(n==k)ok=1;
	}
	printf(ok?"YES\n":"NO\n");
	return 0;
}