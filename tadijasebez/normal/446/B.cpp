#include <stdio.h>
#include <queue>
using namespace std;
#define ll long long
const int N=1050;
const ll inf=9e18;
ll r[N],c[N],a[N][N],dp1[N*N],dp2[N*N];
ll max(ll a, ll b){ return a>b?a:b;}
int main()
{
	int n,m,k,i,j,p;
	scanf("%i %i %i %i",&n,&m,&k,&p);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%i",&a[i][j]),r[i]+=a[i][j],c[j]+=a[i][j];
	priority_queue<ll> pq;
	for(i=1;i<=n;i++) pq.push(r[i]);
	for(i=1;i<=k;i++)
	{
		ll x=pq.top();
		dp1[i]=dp1[i-1]+x;
		pq.pop();
		pq.push(x-(ll)p*m);
	}
	while(pq.size()) pq.pop();
	for(i=1;i<=m;i++) pq.push(c[i]);
	for(i=1;i<=k;i++)
	{
		ll x=pq.top();
		dp2[i]=dp2[i-1]+x;
		pq.pop();
		pq.push(x-(ll)p*n);
	}
	ll ans=-inf;
	for(i=0;i<=k;i++)
	{
		ans=max(ans,dp1[i]+dp2[k-i]-(ll)i*(k-i)*p);
	}
	printf("%lld\n",ans);
	return 0;
}