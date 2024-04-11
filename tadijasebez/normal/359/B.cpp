#include <stdio.h>
const int N=100050;
int a[N];
int main()
{
	int n,k,i;
	scanf("%i %i",&n,&k);
	for(i=1;i<=k;i++) a[i*2-1]=i*2,a[i*2]=i*2-1;
	for(i=k*2+1;i<=n*2;i++) a[i]=i;
	for(i=1;i<=n*2;i++) printf("%i ",a[i]);printf("\n");
	return 0;
}