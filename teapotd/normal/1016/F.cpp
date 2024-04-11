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

struct Vertex {
	vector<Pii> E;
	ll dist[2];

	DBP(E, dist);
};

vector<Vertex> G;
Vi path;

void dfsDist(int v, int p, int ind) {
	each(u, G[v].E) {
		if (u.x == p) continue;
		G[u.x].dist[ind] = G[v].dist[ind] + u.y;
		dfsDist(u.x, v, ind);
	}
}

bool dfsPath(int v, int p, int dst) {
	if (v == dst) {
		path.pb(v);
		return true;
	}

	each(u, G[v].E) {
		if (u.x != p && dfsPath(u.x, v, dst)) {
			path.pb(v);
			return true;
		}
	}
	return false;
}

ll dfsMax(int v, int p1, int p2, int ind, bool ignore) {
	ll ret = (ignore ? INT_MIN : G[v].dist[ind]);

	each(u, G[v].E) {
		if (u.x == p1 || u.x == p2) continue;
		ret = max(ret, dfsMax(u.x, v, -1, ind, false));
	}

	return ret;
}

ll getMax(int i, int ind) {
	int v = path[i];
	int p1 = (i > 0 ? path[i-1] : -1);
	int p2 = (i+1 < sz(path) ? path[i+1] : -1);
	return dfsMax(v, p1, p2, ind, true);
}

bool canIgnore(int i) {
	int v = path[i];
	int p1 = (i > 0 ? path[i-1] : -1);
	int p2 = (i+1 < sz(path) ? path[i+1] : -1);

	int c = 0;
	each(e, G[v].E) if (e.x != p1 && e.x != p2) {
		if (++c >= 2 || sz(G[e.x].E) >= 2) return true;
	}
	return false;
}

void run() {
	int n, m; cin >> n >> m;
	G.resize(n);

	rep(i, 1, n) {
		ll a, b, d; cin >> a >> b >> d;
		a--; b--;
		G[a].E.pb({b, d});
		G[b].E.pb({a, d});
	}

	dfsDist(0, -1, 0);
	dfsDist(n-1, -1, 1);
	dfsPath(n-1, -1, 0);

	ll limit = G[0].dist[1], gap = 0;

	rep(i, 0, sz(path)-2) {
		gap = max(gap, G[path[i]].dist[0] + G[path[i+2]].dist[1]);
	}

	vector<ll> prefs(sz(path));
	rep(i, 0, sz(path)) {
		prefs[i] = getMax(i, 0);
		if (i > 0) {
			gap = max(gap, prefs[i-1] + G[path[i]].dist[1]);
			prefs[i] = max(prefs[i], prefs[i-1]);
		}

		if (canIgnore(i)) gap = limit;
	}

	ll part = INT_MIN;
	for (int i = sz(path)-1; i > 0; i--) {
		part = max(part, getMax(i, 1));
		gap = max(gap, part + prefs[i-1]);
		gap = max(gap, part + G[path[i-1]].dist[0]);
	}

	deb(G, prefs, limit, gap);

	while (m--) {
		int x; cin >> x;
		cout << min(limit, gap+x) << '\n';
	}
}