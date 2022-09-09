#include <stdio.h>
#include <map>
using namespace std;
#define ll long long
map<ll,int> cnt;
int a[200050];
ll max(ll a, ll b){ return a>b?a:b;}
int main()
{
	int n,i;
	ll sum=0,sol=0,tmp=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=n;i>=1;i--) sum+=a[i],cnt[sum]++;
	for(i=1;i<=n;i++)
	{
		tmp+=a[i];
		cnt[sum]--;
		sum-=a[i];
		if(cnt[tmp]) sol=max(sol,tmp);
	}
	printf("%lld\n",sol);
	return 0;
}