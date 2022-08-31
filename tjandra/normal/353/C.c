#include<stdio.h>
typedef unsigned u;
u S[100000];
char B[100000],c;
int main()
{
	u t=0,T,n,R,r;
	for(scanf("%u%u",&T,S);++t<T;)
	{
		scanf("%u",&n);S[t]=n+S[t-1];
	}
	for(t=0;t<T;t++)
	{
		while((c=getchar())<'0');
		if(c=='1')B[t]=1;
	}
	for(R=r=0;t--;)if(B[t])
	{
		if(t)
		{
			n=S[t]-S[t-1];
			if(R<r+S[t-1])R=r+S[t-1];
			r+=n;
		}
		else if(R<r+S[0])R=r+S[0];
	}
	printf("%u\n",R);
	return 0;
}