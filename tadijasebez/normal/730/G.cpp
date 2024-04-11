#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
int main(){
	int n;scanf("%i",&n);
	ll a[n],b[n],c[n];
	set<pll> s;
	for(int i=0;i<n;i++)scanf("%lld%lld",&a[i],&b[i]),c[i]=a[i]+b[i]-1;
	bool ok=true;
	vector<pair<ll,ll>> ans;
	for(int i=0;i<n;i++){
		ok=true;
		for(pll x:s)if(x.first<=c[i]&&x.second>=a[i])ok=false;
		if(ok){ans.pb({a[i],c[i]});s.insert(make_pair(a[i],c[i]));}
		else{
			ll tmp=0LL;
			for(pll x:s){
				if(x.first<(b[i]+1+tmp))tmp=x.second;
				else break;
			}
			tmp++;
			ans.pb({tmp,tmp+b[i]-1});
			s.insert({tmp,tmp+b[i]-1});
		}
	}
	for(auto x:ans)printf("%lld %lld\n",x.first,x.second);
	return 0;
}