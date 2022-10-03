#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
const int inf=1e9+99;

const int N=2.1e5;
int n;
int a[N];
ll w[N];
int p[N];
int ans[N];
vector<int> cs[N];
multiset<ll> ss[N];
int sn=0;

pair<int,ll> dfs(int u) { //ret set pointer
	if(!cs[u].size()) {
		ans[u]=0;
		ss[sn]={a[u]};
		return {sn++,w[u]};
	}

	vector<pair<int,ll> > sns;
	for(int v:cs[u]) sns.pb(dfs(v));
	int be=-1;
	ll pn=-1;
	for(auto &sp:sns) if(be==-1 || ss[sp.fi].size()>ss[be].size()) be=sp.fi, pn=sp.se;

	for(auto &sp:sns) if(sp.fi!=be) for(ll x:ss[sp.fi]) ss[be].insert(x-sp.se+pn);

	for(;ss[be].size() && *ss[be].begin()-pn<0;) ss[be].erase(ss[be].begin());

	ans[u]=ss[be].size();
	ss[be].insert(a[u]+pn);
	return {be,pn+w[u]};
}

int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	p[0]=-1;
	for(int i=1;i<n;i++) {
		int ww;
		scanf("%d%d",p+i,&ww);
		w[i]=ww;
		--p[i];
		cs[p[i]].pb(i);
	}

	dfs(0);

	for(int i=0;i<n;i++) printf("%d%c",ans[i]," \n"[i==n-1]);
}