#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }


struct FAU {
	Vi G;
	FAU(int n = 0) { init(n); }
	void init(int n) { G.assign(n, -1); }
	int size(int i) { return -G[find(i)]; }

	int find(int i) {
		return G[i] < 0 ? i : G[i] = find(G[i]);
	}

	bool join(int i, int j) {
		i = find(i); j = find(j);
		if (i == j) return false;
		if (G[i] > G[j]) swap(i, j);
		G[i] += G[j]; G[j] = i;
		return true;
	}
};

struct Vert {
	vector<Pii> E;
	int parent{-1}, depth{0};
	bool set{0};
};

vector<Vert> G;
vector<Pii> our;
vector<pair<int, Pii>> their;
ll ans;

void dfs(int i) {
	each(e, G[i].E) if (e.x != G[i].parent) {
		G[e.x].parent = i;
		G[e.x].set = (e.y != 0);
		G[e.x].depth = G[i].depth+1;
		dfs(e.x);
	}
}

int setPath(int i, int j, int w) {
	if (i == j) return i;
	if (G[i].depth < G[j].depth) swap(i, j);

	if (!G[i].set) {
		ans += w;
		G[i].set = 1;
	}

	return G[i].parent = setPath(G[i].parent, j, w);
}

void run() {
	int n, k, m; cin >> n >> k >> m;
	G.resize(n);
	our.resize(k);
	their.resize(m);

	each(e, our) {
		cin >> e.x >> e.y;
		e.x--; e.y--;
	}

	each(e, their) {
		cin >> e.y.x >> e.y.y >> e.x;
		e.y.x--; e.y.y--;
	}

	FAU fau(n);
	each(e, our) if (fau.join(e.x, e.y)) {
		G[e.x].E.pb({e.y, 0});
		G[e.y].E.pb({e.x, 0});
	}
	each(e, their) if (fau.join(e.y.x, e.y.y)) {
		G[e.y.x].E.pb({e.y.y, e.x});
		G[e.y.y].E.pb({e.y.x, e.x});
	}

	dfs(0);
	fau.init(n);
	each(e, our) fau.join(e.x, e.y);

	each(e, their) if (!fau.join(e.y.x, e.y.y)) {
		setPath(e.y.x, e.y.y, e.x);
	}

	each(v, G) if (!v.set && v.parent >= 0) {
		cout << "-1\n";
		return;
	}

	cout << ans << endl;
}