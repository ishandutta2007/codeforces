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

constexpr ll MOD = 1e9+7;

struct Vert {
	ll key;
	int par{-1}, size{0}, ver{0};
};

vector<Vert> G;
map<ll, vector<Pii>> edges;
int ver;

int find(int v) {
	if (G[v].ver != ver) {
		G[v].ver = ver;
		G[v].par = -1;
		G[v].size = 1;
	}

	if (G[v].par == -1) return v;
	return G[v].par = find(G[v].par);
}

bool join(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return false;

	if (G[u].size < G[v].size) swap(u, v);
	G[v].par = u;
	G[u].size += G[v].size;
	return true;
}

void run() {
	int n, m, k;
	cin >> n >> m >> k;

	G.resize(n);
	each(v, G) cin >> v.key;

	rep(i, 0, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;

		ll x = G[a].key ^ G[b].key;
		edges[x].pb({ a, b });
	}

	vector<ll> two;
	two.pb(1);
	rep(i, 0, n) two.pb(two.back()*2 % MOD);

	ll ans = (((1ll<<k) - sz(edges)) % MOD) * two[n];
	ans %= MOD;

	each(kv, edges) {
		auto& vec = kv.second;
		ver++;

		int count = n;
		each(e, vec) count -= join(e.x, e.y);
		ans += two[count];
		if (ans >= MOD) ans -= MOD;
	}

	cout << ans << endl;
}