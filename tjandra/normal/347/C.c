#include<stdio.h>
typedef unsigned u;
u G(u a,u b){return b?G(b,a%b):a;}
int main()
{
	u t=0,T,M=0,r=0,n;
	for(scanf("%u",&T);t++<T;r=G(n,r))
	{
		scanf("%u",&n);
		if(M<n)M=n;
	}
	printf((((M/r)&1)^(T&1))?"Alice\n":"Bob\n");
	return 0;
}