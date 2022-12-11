#include<bits/stdc++.h>
#define ll long long
#define maxn 300005
using namespace std;
int n;
ll a[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)scanf("%I64d",&a[i]);
	ll ans=0,has=0;
	for(int i=0;i<n;++i)
	{
		ll t=a[i]/2;
		ans+=min(t,has);
		a[i]-=min(t,has)*2;
		has-=min(has,t);
		ans+=a[i]/3;
		a[i]%=3;
		has+=a[i];
	}
	printf("%I64d\n",ans);
	return 0;
}