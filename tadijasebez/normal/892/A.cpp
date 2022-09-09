#include <stdio.h>
#define ll long long
const int N=100050;
ll max(ll a, ll b){ return a>b?a:b;}
ll sol,best,sum;
int a[N],b[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i ",&a[i]);
	for(i=1;i<=n;i++) scanf("%i ",&b[i]);
	for(i=1;i<=n;i++)
	{
		sum+=a[i];
		sol=max(sol,best+b[i]);
		best=max(best,b[i]);
	}
	if(sum<=sol) printf("YES\n");
	else printf("NO\n");
	return 0;
}