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

constexpr ll INF = 2e18;

// MAX of linear functions online; space: O(n)
struct Hull {
	static bool modeQ; // Toggles operator< mode

	struct Line {
		mutable ll a, b, end;

		ll intersect(const Line& r) const {
			if (a==r.a) return b > r.b ? INF : -INF;
			ll u = b-r.b, d = r.a-a;
			return u/d + ((u^d) >= 0 || !(u%d));
		}
		
		bool operator<(const Line& r) const {
			return modeQ ? end < r.end : a < r.a;
		}
	};

	multiset<Line> S;
	Hull() { S.insert({ 0, -INF, INF }); }

	// Updates segment end
	bool update(multiset<Line>::iterator it) {
		auto cur = it++; cur->end = INF;
		if (it == S.end()) return false;
		cur->end = cur->intersect(*it);
		return cur->end >= it->end;
	}

	// Insert f(x) = ax+b; time: O(lg n)
	void insert(ll a, ll b) {
		auto it = S.insert({ a, b, INF });
		while (update(it)) it = --S.erase(++it);
		rep(i, 0, 2)
			while (it != S.begin() && update(--it))
				update(it = --S.erase(++it));
	}

	// Query max(f(x) for each f): time: O(lg n)
	ll query(ll x) {
		modeQ = 1;
		auto l = *S.upper_bound({ 0, 0, x });
		modeQ = 0;
		return l.a*x + l.b;
	}
};

bool Hull::modeQ = false;

// ---

struct Vert {
	vector<pair<int, Pii>> E;
	int size{0};
};

int n, m;
vector<Vert> G;
Hull answer;

bool can(int e, int p) {
	return e != p && G[e].size != -2;
}

int computeSize(int i, int p) {
	int& s = G[i].size = 1;
	each(e, G[i].E) if (can(e.x, p)) s += computeSize(e.x, i);
	return s;
}

int getCentroid(int i) {
	int p = -1, size = computeSize(i, -1);
	bool ok = true;
	while (ok) {
		ok = false;
		each(e, G[i].E) if (can(e.x, p) && G[e.x].size > size/2) {
			p = i; i = e.x; ok = true;
			break;
		}
	}
	return i;
}

void downHull(int i, int p, Hull& hull, ll a, ll b) {
	hull.insert(a, b);
	each(e, G[i].E) if (can(e.x, p)) {
		downHull(e.x, i, hull, a+e.y.x, b+e.y.y);
	}
}

void mergeHulls(Hull& dst, Hull& src) {
	if (sz(dst.S) < sz(src.S)) swap(dst.S, src.S);
	each(l, src.S) dst.insert(l.a, l.b);
	src.S.clear();
}

void addAnswer(Hull& one, Hull& two) {
	auto a = one.S.begin(), b = two.S.begin();
	while (a != one.S.end() && b != two.S.end()) {
		answer.insert(a->a+b->a, a->b+b->b);
		if (a->end < b->end) a++;
		else b++;
	}
}

void pairSum(vector<Hull>& hulls, int begin, int end) {
	if (begin >= end) return;
	if (begin+1 == end) {
		auto& cur = hulls[begin];
		each(l, cur.S) answer.insert(l.a, l.b);
		return;
	}

	int mid = (begin+end) / 2;
	pairSum(hulls, begin, mid);
	pairSum(hulls, mid, end);

	auto& one = hulls[begin], two = hulls[mid];
	addAnswer(one, two);
	mergeHulls(one, two);
}

void solve(int v) {
	v = getCentroid(v);
	G[v].size = -2;

	vector<Hull> hulls;
	hulls.reserve(sz(G[v].E));
	
	each(e, G[v].E) if (can(e.x, -1)) {
		hulls.emplace_back();
		downHull(e.x, v, hulls.back(), e.y.x, e.y.y);
	}

	pairSum(hulls, 0, sz(hulls));
	hulls.clear();

	each(e, G[v].E) if (can(e.x, -1)) solve(e.x);
}

void run() {
	cin >> n >> m;
	G.resize(n);

	rep(i, 1, n) {
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		u--; v--;
		G[u].E.pb({ v, {a,b} });
		G[v].E.pb({ u, {a,b} });
	}

	answer.insert(0, 0);
	solve(0);

	ll i = 0;
	each(l, answer.S) {
		while (i < l.end) {
			if (i >= m) break;
			cout << l.a*i + l.b << ' ';
			i++;
		}
	}
	cout << endl;
}