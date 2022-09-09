#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
	int n,i;
	scanf("%i",&n);
	vector<int> a(n+1),b(n+1);
	vector<int> d;
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&a[i],&b[i]);
		d.pb(a[i]-b[i]);
		ans+=(ll)n*b[i]-a[i];
	}
	sort(d.begin(),d.end());
	reverse(d.begin(),d.end());
	for(i=1;i<=n;i++) ans+=(ll)d[i-1]*i;
	printf("%lld\n",ans);
	return 0;
}