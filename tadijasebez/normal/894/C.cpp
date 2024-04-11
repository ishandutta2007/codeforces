#include <stdio.h>
int gcd(int x, int y)
{
	if(y==0) return x;
	return gcd(y,x%y);
}
const int N=1050;
int a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	int g=a[1];
	for(i=2;i<=n;i++) g=gcd(g,a[i]);
	if(g!=a[1]) return printf("-1\n"),0;
	printf("%i\n",n*2);
	for(i=1;i<=n;i++) printf("%i %i ",a[i],a[1]);
	return 0;
}