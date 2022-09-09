#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int lim=10000;
map<pair<ll,int> ,ll> dp;
ll Get(ll l, int q)
{
	if(q==1) return l+min(l,(ll)lim)-1;
	if(dp.count(mp(l,q))) return dp[mp(l,q)];
	if(l>lim) return dp[mp(l,q)]=l-lim+Get(lim,q);
	ll r=l;
	for(int i=0;i<=l;i++)
	{
		r=Get(r,q-1)+2;
	}
	return dp[mp(l,q)]=r-2;
}
int Ask(vector<ll> v)
{
	printf("%i ",v.size());
	for(ll i:v) printf("%lld ",i);
	printf("\n");
	fflush(stdout);
	int b;scanf("%i",&b);
	return b;
}
int main()
{
	ll l=1;
	for(int i=5;i;i--)
	{
		if(i==1)
		{
			vector<ll> u;
			for(int j=0;j<min(l,(ll)lim);j++) u.pb(l+j);
			Ask(u);
			return 0;
		}
		ll r=l;
		vector<ll> u,v;
		v.pb(l);
		for(int j=0;j<=min(l,(ll)lim);j++)
		{
			r=Get(r,i-1)+1;
			if(j<min(l,(ll)lim)) u.pb(r);
			r++;
			v.pb(r);
		}
		int b=Ask(u);
		if(b==-1) return 0;
		l=v[b];
	}
	return 0;
}