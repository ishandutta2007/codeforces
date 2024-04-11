// Author : WangZhikun
// Date   : 2018-10-18
// ????????????????

#include <map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mp make_pair
using namespace std;
typedef long long ll;

ll n,k,m,l,r,c,p,ans = 0,evn = 0,cev = 0;
pair<ll,pair<ll,ll>> ev[400040];
ll szsz[2][1100020];
inline void add(ll x,ll c,ll p){
	while(x<=1<<20){
		szsz[c][x]+=p;
		x+= x&(-x);
	}
}
inline ll sum(ll x,ll c){
	ll ret = 0;
	while(x>0){
		ret+=szsz[c][x];
		x-= x&(-x);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k>>m;
	for(ll i=0;i<m;i++){
		cin>>l>>r>>c>>p;
		ev[evn++] = mp(l,mp(c,p));
		ev[evn++] = mp(r+1,mp(-c,p));
	}
	sort(ev,ev+evn);
	for(ll i=1;i<=n;i++){
		while(cev<evn && ev[cev].first<=i){
			add(ev[cev].second.second,0,ev[cev].second.first);
			add(ev[cev].second.second,1,ev[cev].second.first*ev[cev].second.second);
			cev++;
		}
		ll cid = 0,cn = 0;
		ll cm = 0;
		for(ll i=1<<19;i>0;i/=2){
			if(cn+szsz[0][cid+i]<=k){
				cn+=szsz[0][cid+i];
				cid+=i;
			}
		}
		if(cn<k)cid++;
		cn = sum(cid,0);
		cm = sum(cid,1)-max(cid*(cn-k),0LL);
		ans+=cm;
	}
	cout<<ans<<endl;
	return 0;
}