#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
const int N=300050;
ll a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);reverse(a+1,a+1+n);
	for(i=1;i<=n;i++) a[i]+=a[i-1];
	ll sol=a[n];
	for(i=2;i<=n;i++) sol+=a[i];
	printf("%lld\n",sol);
	return 0;
}