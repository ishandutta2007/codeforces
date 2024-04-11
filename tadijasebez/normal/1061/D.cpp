#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
const int mod=1e9+7;
pair<int,int> seg[N];
void ck(ll &x){ if(x>=mod) x-=mod;if(x<0) x+=mod;}
int main()
{
	int n,x,y,i;
	scanf("%i %i %i",&n,&x,&y);
	for(i=1;i<=n;i++) scanf("%i %i",&seg[i].first,&seg[i].second);
	sort(seg+1,seg+1+n);
	multiset<int> rs;
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		ans+=((ll)(seg[i].second-seg[i].first)*y+x)%mod;
		ck(ans);
		auto it=rs.lower_bound(seg[i].first);
		if(it!=rs.begin())
		{
			it--;
			ll add=(ll)(seg[i].first-*it)*y-x;
			if(add<0) ans+=add%mod,ck(ans),rs.erase(it);
		}
		rs.insert(seg[i].second);
	}
	printf("%lld\n",ans);
	return 0;
}