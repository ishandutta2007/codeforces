#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ld eps=1e-11;
typedef complex<int> pt;
const int inf=1e9+99;
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200<<10;
vector<int> adj[N];
int n;
vector<pair<int,int> > vv;
pair<int,int> FAIL={-2,-2};

pair<int,int> dfs(int u,int p=-1) {
	vector<int> rec_norm;
	bool seen_weird=0;
	int len_weird=-1;
	for(int v:adj[u]) if(v!=p) {
		pair<int,int> P=dfs(v,u);
		if(P.fi==-1) {
			rec_norm.pb(P.se+1);
			continue;
		}
		if(P.fi==-2 || seen_weird) return FAIL;
		seen_weird=1;
		len_weird=P.se+1;
	}
	sort(rec_norm.begin(),rec_norm.end());
	rec_norm.resize(unique(rec_norm.begin(),rec_norm.end())-rec_norm.begin());

	if(seen_weird) {
		if(rec_norm.size()>1u) return FAIL;
		if(rec_norm.size()==0u) return mp(-3,len_weird);
		vv.pb(mp(len_weird,rec_norm[0]));
		return mp(-3,0);
	} else {
		if(rec_norm.size()>2u) return FAIL;
		if(rec_norm.size()==2u) {
			vv.clear();
			vv.pb(mp(rec_norm[0],rec_norm[1]));
			return mp(-3,0);
		}
		if(rec_norm.size()==1u) return mp(-1,rec_norm[0]);
		return mp(-1,0);
	}
}

int fail() {
	printf("-1\n");
	return 0;
}
int reduce(int x) {
	for(;x%2==0;) x/=2;
	printf("%d\n",x);
	return 0;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		int a,b; scanf("%d%d",&a,&b);
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int rt=-1;
	for(int i=1;i<=n;i++) if(adj[i].size()==1u) rt=i;
	assert(~rt);

	pair<int,int> P=dfs(rt);
	if(P.fi==-2) return fail();
	if(P.fi==-1) return reduce(P.se);
	assert(P.fi==-3);

	assert(vv[0].fi!=vv[0].se);
	int ABO=P.se;
	for(;vv.size() && ABO==vv.back().se;) {
		ABO+=vv.back().fi;
		vv.pop_back();
	}
	if(vv.size()>1u) return fail();
	if(vv.size()==1u) {
		int x,y,z;
		x=ABO;
		y=vv[0].fi;
		z=vv[0].se;
		if(x==y) return reduce(x+z);
		if(x==z) return reduce(y+z);
		if(y==z) return reduce(x+z);
		return fail();
	}
	return reduce(ABO);
}