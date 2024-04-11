#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	vector<int> a;
	int n,i;
	scanf("%i",&n);
	a.resize(n+1);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		if(i==1) ans+=(ll)a[i]*(n-a[i]+1);
		else
		{
			if(a[i-1]<a[i]) ans+=(ll)(a[i]-a[i-1])*(n-a[i]+1);
			else ans+=(ll)a[i]*(a[i-1]-a[i]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}