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

struct Vert {
	set<int> E;
	bool off{0};
};

vector<Vert> G;
int n, m, k, active;

void reduce(int v) {
	if (G[v].off || sz(G[v].E) >= k) return;

	set<int> tmp;
	tmp.swap(G[v].E);
	G[v].off = 1;
	active--;

	each(e, tmp) {
		G[e].E.erase(v);
		reduce(e);
	}
}

void run() {
	cin >> n >> m >> k;
	G.resize(n);
	vector<Pii> E(m);

	each(e, E) {
		cin >> e.x >> e.y;
		e.x--; e.y--;
		G[e.x].E.insert(e.y);
		G[e.y].E.insert(e.x);
	}

	Vi ans(m);
	active = n;
	rep(i, 0, n) reduce(i);

	for (int i = m-1; i >= 0; i--) {
		ans[i] = active;
		
		Pii e = E[i];
		G[e.x].E.erase(e.y);
		G[e.y].E.erase(e.x);
		reduce(e.x);
		reduce(e.y);
	}

	each(x, ans) cout << x << '\n';
}