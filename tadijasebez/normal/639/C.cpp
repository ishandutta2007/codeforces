#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18;
int main()
{
	int n,k;
	scanf("%i %i",&n,&k);
	vector<ll> a(n+1),b(n+1);
	for(ll &i:a) scanf("%lld",&i);
	ll sum=0;
	int ok=0;
	for(int i=0;i<=n;i++)
	{
		b[i]=sum;
		sum+=a[i];
		if(sum%2==1 || sum%2==-1) break;
		sum/=2;
		ok++;
	}
	sum=0;
	int ans=0;
	for(int i=n;i>=0;i--)
	{
		sum=sum*2+a[i];
		if(sum<=-inf || sum>=inf) break;
		if(i<=ok)
		{
			ll need=a[i]-sum-b[i];
			if(need<=k && need>=-k && (need!=0 || i!=n)) ans++;
		}
	}
	printf("%i\n",ans);
	return 0;
}