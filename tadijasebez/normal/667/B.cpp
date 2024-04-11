#include <stdio.h>
long long sum;
long long naj;
long long max(long long a, long long b)
{
	if(a>b) return a;
	else return b;
}
long long a[100000];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%lld",&a[i]),sum+=a[i],naj=max(naj,a[i]);
	long long sol=naj-(sum-naj)+1;
	printf("%lld\n",sol);
	return 0;
}