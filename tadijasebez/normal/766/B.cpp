#include <stdio.h>
#include <algorithm>
using namespace std;
long long a[100000];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%lld",&a[i]);
	sort(a,a+n);
	bool ok=false;
	for(i=2;i<n;i++)
	{
		if(a[i-1]+a[i-2]>a[i]) ok=true;
	}
	if(ok) printf("YES\n");
	else printf("NO\n");
	return 0;
}