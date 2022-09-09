#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
const int N=200050;
const ll inf=2e9+7;
vector<pair<ll,ll> > seg;
int sum[N];
ll Get(ll l, ll r)
{
	int L=upper_bound(seg.begin(),seg.end(),mp(l,inf))-seg.begin();
	int R=upper_bound(seg.begin(),seg.end(),mp(r,inf))-seg.begin();
	//printf("(%i %i) (%i %i) (%i %i)\n",l,r,seg[L].first,seg[L].second,seg[R].first,seg[R].second);
	ll ans=r-l-sum[R];
	if(L>0) ans+=sum[L];
	if(R>0 && seg[R-1].second>r) ans+=seg[R-1].second-r;//,printf("R:(%i %i)\n",seg[R-1].first,seg[R-1].second);
	if(L>0 && seg[L-1].second>l) ans-=seg[L-1].second-l;//,printf("L:(%i %i)\n",seg[L-1].first,seg[L-1].second);
	//if(r<50) printf("(%i %i)=%i\n",l,r,ans);
	return ans;
}
int main()
{
	int n,i,l,r,h;
	scanf("%i %i",&n,&h);
	for(i=1;i<=n;i++) scanf("%i %i",&l,&r),seg.pb(mp((ll)l,(ll)r));
    sort(seg.begin(),seg.end());
    for(i=1;i<=n;i++) sum[i]=sum[i-1]+seg[i-1].second-seg[i-1].first;
    ll sol=0;
	for(i=0;i<n;i++)
	{
		ll st=seg[i].first,top=2e9+5,bot=0,mid,ans;
		while(top>=bot)
		{
			mid=top+bot>>1;
			if(Get(st,st+mid)>=h) ans=mid,top=mid-1;
			else bot=mid+1;
		}
		sol=max(sol,ans);
		//printf("%lld %lld\n",st,ans);
	}
	printf("%lld\n",sol);
	return 0;
}