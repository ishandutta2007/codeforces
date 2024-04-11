#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
#define INF 0x7fffffff
///////////////////////////
int main()
{
	ll m;
	cin>>m;
	for(ll i=1;i<=m*2;i++)
	{
		scanf("%I64d",&a[i]);
	}
	sort(a+1,a+m*2+1);
	ll ans=(a[m]-a[1])*(a[2*m]-a[m+1]);
	for(ll i=2;i<=m;i++)
	{
		ans=min(ans,(a[i+m-1]-a[i])*(a[m*2]-a[1]));
	}
	cout<<ans<<endl;;
	return 0;
}