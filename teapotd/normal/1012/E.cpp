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

vector<vector<Pii>> G;
vector<Vi> cycles;

void dfs(int v) {
	while (!G[v].empty()) {
		Pii e = G[v].back();
		G[v].pop_back();
		dfs(e.x);
		cycles.back().pb(e.y);
	}
}

void run() {
	int n, upper;
	cin >> n >> upper;
	Vi elems(n);
	each(e, elems) cin >> e;

	Vi sorted(n);
	iota(all(sorted), 0);
	sort(all(sorted), [&](int l, int r) { return elems[l] < elems[r]; });

	int last = elems[sorted[0]], k = 0;
	rep(i, 0, n) {
		int e = sorted[i];
		if (elems[e] != last) k++;
		last = elems[e]; elems[e] = k;
	}
	k++;

	G.resize(k);
	rep(i, 0, n) if (elems[i] != elems[sorted[i]]) {
		G[elems[i]].pb({elems[sorted[i]], i});
	}

	int len = 0;
	rep(i, 0, k) if (!G[i].empty()) {
		cycles.emplace_back();
		dfs(i);
		len += sz(cycles.back());
	}

	if (len > upper) {
		cout << "-1\n";
		return;
	}

	int toMerge = min(sz(cycles), upper-len);

	if (toMerge > 2) {
		Vi one, two;
		rep(i, 0, toMerge) {
			one.insert(one.end(), all(cycles.back()));
			two.pb(cycles.back()[0]);
			cycles.pop_back();
		}

		reverse(all(two));
		cycles.pb(move(one));
		cycles.pb(move(two));
	}

	cout << sz(cycles) << '\n';
	each(c, cycles) {
		cout << sz(c) << '\n';
		each(x, c) cout << x+1 << ' ';
		cout << '\n';
	}
}