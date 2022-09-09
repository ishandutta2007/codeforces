#include <stdio.h>
#include <algorithm>
using namespace std;
int a[200000];
int main()
{
	int n,i,r;
	long long najm;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%i",&a[i]);
	}
	sort(a,a+n);
	najm=a[1]-a[0];
	r=1;
	for(i=2;i<n;i++)
	{
		if(najm>a[i]-a[i-1])
		{
			najm=a[i]-a[i-1];
			r=1;
		}
		else if(najm==a[i]-a[i-1])
		{
			r++;
		}
	}
	printf("%lld %i",najm,r);
}