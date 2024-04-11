#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll inf=9e18;
vector<ll> Make(vector<int> p)
{
	vector<ll> ans;
    ans.pb(1);
    for(int i:p) for(int k=0;k<ans.size();k++){ ll j=ans[k];if(j<inf/i) ans.pb(j*i);}
    sort(ans.begin(),ans.end());
    return ans;
}
int main()
{
	int n,i,j;ll k;
	scanf("%i",&n);
	vector<int> p,v[2];
	p.resize(n);
	for(i=0;i<n;i++) scanf("%i",&p[i]);
	sort(p.begin(),p.end());
	for(i=0;i<n;i++) v[i&1].pb(p[i]);
	vector<ll> x=Make(v[0]),y=Make(v[1]);
	//for(ll h:x) printf("%lld ",h);printf("\n");
	//for(ll h:y) printf("%lld ",h);printf("\n");
	scanf("%lld",&k);
	ll l=0,r=1e18+5,mid,ans=-1;
	while(l<=r)
	{
		mid=l+r>>1;
		j=y.size()-1;
		ll tmp=0;
		for(i=0;i<x.size();i++)
		{
            while(j>=0 && mid/y[j]<x[i]) j--;
			tmp+=j+1;
		}
		//printf("mid:%lld tmp:%lld\n",mid,tmp);
		if(tmp>=k) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}