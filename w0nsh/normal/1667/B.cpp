#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

constexpr int INF = 1000000666;
struct Tree{
	VI t;
	int BOTTOM;

	void build(int sz){
		BOTTOM = 1;
		while(BOTTOM < sz) BOTTOM *= 2;
		t = VI(BOTTOM*2, -INF);
	}

	void setmax(int v, int val){
		v += BOTTOM;
		while(v >= 1){
			t[v] = std::max(t[v], val);
			v >>= 1;
		}
	}

	int query(int a, int b){
		a += BOTTOM;
		b += BOTTOM+1;
		int ret = -INF;
		while(a < b){
			if(a&1) ret = std::max(ret, t[a++]);
			if(b&1) ret = std::max(ret, t[--b]);
			a>>=1;b>>=1;
		}
		return ret;
	}
};

void solve(){
	int n;
	std::cin >> n;
	VI A(n);
	FOR(i, n) std::cin >> A[i];

	std::vector<ll> pref(n+1);
	std::vector<ll> vals;
	vals.push_back(0);
	REP(i, 1, n+1) pref[i] = pref[i-1] + A[i-1], vals.push_back(pref[i]);
	std::sort(vals.begin(), vals.end());
	vals.resize(std::distance(vals.begin(), std::unique(vals.begin(), vals.end())));
	auto kto = [&](ll a){
		return std::distance(vals.begin(), std::lower_bound(vals.begin(), vals.end(), a));
	};
	TRAV(i, pref) i = kto(i);

	int V = SZ(vals)+2;
	VI exact(V, -INF);
	Tree tree_minus;
	Tree tree_plus;
	tree_minus.build(V);
	tree_plus.build(V);
	tree_minus.setmax(pref[0], 0);
	tree_plus.setmax(pref[0], 0);
	exact[pref[0]] = 0;

	int last = -1;
	REP(i, 1, n+1){
		auto v = pref[i];
		int best = -INF;
		best = std::max(best, exact[v]);
		best = std::max(best, i + tree_minus.query(0, v-1));
		best = std::max(best, -i + tree_plus.query(v+1, V-1));

		exact[v] = std::max(exact[v], best);
		tree_minus.setmax(v, best - i);
		tree_plus.setmax(v, best + i);
		last = best;
	}

	std::cout << last << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while(t--) solve();

	return 0;
}