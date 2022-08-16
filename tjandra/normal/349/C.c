#include<stdio.h>
typedef long long unsigned llu;
typedef unsigned u;
llu S;
int main()
{
	u m=0xffffffffu,M=0,n,t=0,T;
	for(scanf("%u",&T);t++<T;S+=n)
	{
		scanf("%u",&n);
		if(M<n)M=n;
		if(m>n)m=n;
	}
	T--;
	S=S/T+(S%T>0);
	printf("%u\n",S>M?S:M);
	return 0;
}