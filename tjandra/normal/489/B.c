#include<stdio.h>
typedef unsigned u;
u A[111],B[111];
int main()
{
	u q,n;
	for(scanf("%u",&q);q--;++A[n])scanf("%u",&n);
	for(scanf("%u",&q);q--;++B[n])scanf("%u",&n);
	for(q=0,n=1;n<=100;++n)
	{
		while(A[n]&&B[n-1])++q,--A[n],--B[n-1];
		while(A[n]&&B[n])++q,--A[n],--B[n];
		while(A[n]&&B[n+1])++q,--A[n],--B[n+1];
	}
	printf("%u\n",q);
	return 0;
}