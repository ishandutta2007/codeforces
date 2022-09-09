#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=300050;
const int M=2*N;
ll a[N],sum[N],suf[N],l[N],r[N];
int main()
{
	int n,x,i;
	scanf("%i %i",&n,&x);
	ll ans=0,mn=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
		mn=min(mn,sum[i]);
		ans=max(ans,sum[i]-mn);
		l[i]=sum[i]-mn;
	}
	mn=0;
	for(i=n;i>=1;i--)
	{
		suf[i]=suf[i+1]+a[i];
		mn=min(mn,suf[i]);
		r[i]=suf[i]-mn;
	}
	ll best=0;
    for(i=1;i<=n;i++)
	{
		best=max(best,-sum[i]*x+l[i]);
		ans=max(ans,best+sum[i]*x+r[i+1]);
	}
	printf("%lld\n",ans);
	return 0;
}