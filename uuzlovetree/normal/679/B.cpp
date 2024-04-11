#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans1,ans2;
ll cho[30];
ll get(ll x)
{
	ll l=1,r=100000,ans=1;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(mid*mid*mid<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
void dfs(ll m,ll n,ll x)
{
	if(!m)
	{
		if(n>ans1)ans1=n,ans2=x;
		if(n==ans1)ans2=max(ans2,x);
		return;
	}
	ll a=get(m);
	dfs(m-a*a*a,n+1,x+a*a*a);
	if(a*a*a-1-(a-1)*(a-1)*(a-1)>m-a*a*a)dfs(a*a*a-1-(a-1)*(a-1)*(a-1),n+1,x+(a-1)*(a-1)*(a-1));
}
int main()
{
	ll m;
	scanf("%I64d",&m);
	dfs(m,0,0);
	printf("%I64d %I64d\n",ans1,ans2);
	return 0;
}