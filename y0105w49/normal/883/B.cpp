// ayy
// ' lamo
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld; //CARE
typedef complex<ld> pt;
#define fi first
#define se second
#define pb push_back
const ld eps=1e-8;
const int inf=1e9+99;
const ll linf=1e18+99;
const int P=1e9+7;


void fail() {
	printf("-1\n");
	// assert(0);
	exit(0);
}

const int N=200<<10;
int n,m,k,s[N],t[N];
int id[N],od[N],lo[N];
vector<int> adj[N];
vector<int> occ[N];








int32_t main() {
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d",s+i),t[i]=s[i];
	for(int j=1;j<=m;j++) {
		int u,v; scanf("%d%d",&u,&v);
		adj[u].pb(v);
		++id[v]; ++od[u];
	}
	set<int> ss;
	vector<int> topo;
	for(int i=1;i<=n;i++) if(!id[i]) ss.insert(i);
	for(;ss.size();) {
		int u=*ss.begin();
		ss.erase(u);
		topo.pb(u);
		// cerr<<"topo: "<<u<<endl;
		for(int v:adj[u]) if(!--id[v]) ss.insert(v);
	}
	if((int)topo.size() != n) fail();

	for(int u:topo) if(!t[u]) t[u]=k;
	for(int u:topo) {
		if(s[u] && s[u]!=t[u]) fail();
		if(!t[u]) fail();
		for(int v:adj[u]) t[v]=min(t[v],t[u]-1);
	}
	for(int u:topo) lo[u]=s[u];
	reverse(topo.begin(),topo.end());
	for(int u:topo) {
		for(int v:adj[u]) lo[u]=max(lo[u],lo[v]+1);
	}
	reverse(topo.begin(),topo.end());

	vector<pair<int,int> > vv;
	map<int,int> mm;
	for(int u:topo) vv.pb({lo[u],u});
	sort(vv.begin(),vv.end());
	for(int u:topo) mm[t[u]]++;
	int ii=0;
	set<pair<int,int> > ww;
	for(int i=1;i<=k;i++) {
		for(;ii<n && vv[ii].fi<=i;) ww.insert({t[vv[ii].se],vv[ii].se}), ++ii;
		if(!mm[i]) {
			for(;ww.size() && ww.begin()->fi<i;) ww.erase(ww.begin());
			if(!ww.size()) fail();
			assert(ww.begin()->fi>i);
			mm[ww.begin()->fi]--;
			t[ww.begin()->se]=i;
			mm[i]++;
			ww.erase(ww.begin());
		}
	}

	for(int i=1;i<=n;i++) printf("%d%c",t[i]," \n"[i==n]);
}