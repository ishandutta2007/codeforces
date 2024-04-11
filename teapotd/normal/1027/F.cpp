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

struct Edge {
	int i, dst;
};

struct Vert {
	vector<Edge> E;
	bool visited, disabled;
};

int n;
vector<Vert> G;
vector<bool> satisfied;

bool disable(int i) {
	if (G[i].disabled) return false;
	G[i].disabled = true;

	each(e, G[i].E) if (!satisfied[e.i]) {
		satisfied[e.i] = true;
		if (!disable(e.dst)) return false;
	}
	return true;
}

Pii dfs(int i) {
	G[i].visited = true;
	Pii ret = {1, 0};

	each(e, G[i].E) if (!G[e.dst].disabled) {
		ret.y++;
		if (!G[e.dst].visited) {
			Pii tmp = dfs(e.dst);
			ret.x += tmp.x;
			ret.y += tmp.y;
		}
	}
	return ret;
}

bool possible(int maxDay) {
	satisfied.assign(n, false);
	rep(i, 0, sz(G)) {
		G[i].visited = G[i].disabled = false;
	}

	rep(i, maxDay+1, sz(G)) {
		if (!disable(i)) return false;
	}

	rep(i, 0, sz(G)) if (!G[i].disabled && !G[i].visited) {
		Pii tmp = dfs(i);
		if (tmp.y/2 > tmp.x) return false;
	}
	return true;
}

void run() {
	cin >> n;
	vector<Pii> exams(n);
	Vi days;

	each(e, exams) {
		cin >> e.x >> e.y;
		days.pb(e.x);
		days.pb(e.y);
	}

	sort(all(days));
	days.resize(unique(all(days)) - days.begin());
	G.resize(sz(days));

	rep(i, 0, n) {
		auto& e = exams[i];
		e.x = int(lower_bound(all(days), e.x) - days.begin());
		e.y = int(lower_bound(all(days), e.y) - days.begin());
		G[e.x].E.pb({i, e.y});
		G[e.y].E.pb({i, e.x});
	}

	if (!possible(sz(days)-1)) {
		cout << "-1\n";
		return;
	}

	int begin = 0, end = sz(days)+1;
	each(e, exams) begin = max(begin, e.x);

	rep(i, begin, end) deb(i, possible(i));

	while (begin+1 < end) {
		int mid = (begin+end-1) / 2;
		if (possible(mid)) {
			end = mid+1;
		} else {
			begin = mid+1;
		}
	}

	cout << days[begin] << endl;
}