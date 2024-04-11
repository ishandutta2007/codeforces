#include <stdio.h>
#define ll long long
const int N=100050;
int a[N];
int main()
{
	int n,i;ll sol=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++) sol+=(ll)i*(a[i]-1);
	sol+=n;
	printf("%lld\n",sol);
	return 0;
}