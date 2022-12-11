#include<bits/stdc++.h>
#define ll long long
#define maxn 2005
using namespace std;
const ll inf = (ll)1e18;
int n,k;
ll p;
ll a[maxn],b[maxn];
bool check(ll x)
{
	int i=1,j=1;
	while(i<=n&&j<=k)
	{
		if(abs(a[i]-b[j])+abs(b[j]-p)<=x)i++,j++;
		else j++;
	}
	if(i!=n+1)return 0;
	return 1;
}
int main()
{
	scanf("%d%d%I64d",&n,&k,&p);
	for(int i=1;i<=n;++i)scanf("%I64d",&a[i]);
	for(int i=1;i<=k;++i)scanf("%I64d",&b[i]);
	sort(a+1,a+n+1);
	sort(b+1,b+k+1);
	ll l=0,r=(ll)4e9,ans=r;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%I64d\n",ans);
	return 0;
}