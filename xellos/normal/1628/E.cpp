// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456789LL
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat gcd(cat a, cat b) {
	if(a > b) swap(a, b);
	while(a) {
		cat c = b%a;
		b = a;
		a = c;
	}
	return b;
}

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += val;
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += node_val[i];
		return ret;
	}
};

void DFS(int cur, int prev, auto & G, auto & par, auto & dep) {
	for(auto p : G[cur]) if(p.ff != prev) {
		par[p.ff] = cur;
		dep[p.ff] = dep[cur]+1;
		DFS(p.ff, cur, G, par, dep);
	}
}

int path(int u, int v, auto & dep, auto * par, auto * mx) {
	int ret = 0;
	if(dep[u] < dep[v]) swap(u, v);
	for(int k = 0; k < 20; k++) if(((dep[u]-dep[v])>>k)&1) {
		ret = max(ret, mx[k][u]);
		u = par[k][u];
	}
	for(int k = 19; k >= 0; k--) if(par[k][u] != par[k][v]) {
		ret = max(ret, mx[k][u]);
		ret = max(ret, mx[k][v]);
		u = par[k][u], v = par[k][v];
	}
	if(u != v) {
		ret = max(ret, mx[0][u]);
		ret = max(ret, mx[0][v]);
		u = par[0][u], v = par[0][v];
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N,Q;
	cin >> N >> Q;
	vector< vector< pair<int,int> > > G(N);
	for(int i = 0; i < N-1; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		G[--u].push_back({--v, w});
		G[v].push_back({u, w});
	}
	vector<int> dep(N, 0);
	vector<int> par[20];
	for(int k = 0; k < 20; k++) par[k].resize(N, 0);
	DFS(0, 0, G, par[0], dep);
	for(int k = 1; k < 20; k++) for(int i = 0; i < N; i++)
		par[k][i] = par[k-1][par[k-1][i]];
	vector<int> mx[20];
	for(int k = 0; k < 20; k++) mx[k].resize(N, 0);
	for(int i = 1; i < N; i++) for(auto p : G[i]) if(p.ff == par[0][i]) mx[0][i] = p.ss;
	for(int k = 1; k < 20; k++) for(int i = 0; i < N; i++)
		if(dep[i] >= (1<<k)) mx[k][i] = max(mx[k-1][par[k-1][i]], mx[k-1][i]);
	vector<int> cost_adj(N-1, 0);
	for(int i = 0; i < N-1; i++) cost_adj[i] = path(i, i+1, dep, par, mx);
	vector<int> cost[20];
	cost[0] = cost_adj;
	for(int k = 1; k < 20; k++) {
		cost[k].resize(N, 0);
		for(int i = 0; i < N; i++)
			if(i+(1<<k) < N) cost[k][i] = max(cost[k-1][i], cost[k-1][i+(1<<(k-1))]);
	}
	set< pair<int,int> > I;
	multiset<int> val;
	for(int q = 0; q < Q; q++) {
		int tp;
		cin >> tp;
		if(tp == 3) {
			int v;
			cin >> v;
			v--;
			if(I.empty()) {
				cout << "-1\n";
				continue;
			}
			int u = begin(I)->ff;
			int ans = 0;
			if(!val.empty()) ans = *rbegin(val);
			ans = max(ans, path(u, v, dep, par, mx));
			if(ans == 0) ans = -1;
			cout << ans << "\n";
			continue;
		}
		int l,r;
		cin >> l >> r;
		l--;
		vector< pair<int,int> > old, nw;
		nw = {{l,r}};
		auto it = I.lower_bound({l, -1});
		if(it != begin(I)) {
			it--;
			if(it->ss >= l) {
				old.insert(begin(old), *it);
				nw[0].ff = it->ff;
				nw[0].ss = max(nw[0].ss, it->ss);
			}
			it++;
		}
		while(it != end(I) && it->ff <= r) {
			old.push_back(*it);
			nw[0].ss = max(nw[0].ss, it->ss);
			it++;
		}
		if(tp == 2) {
			nw.clear();
			if(!old.empty() && old[0].ff < l) nw.push_back({old[0].ff, l});
			if(!old.empty() && old.back().ss > r) nw.push_back({r, old.back().ss});
		}
		for(auto p : old) {
			it = I.find(p);
			int m = 0;
			l = p.ff, r = p.ss-1;;
			for(int k = 19; k >= 0; k--) if(((r-l)>>k)&1) {
				m = max(m, cost[k][l]);
				l += 1<<k;
			}
			val.erase(val.find(m));
			auto jt = it;
			if(it != begin(I)) {
				jt--;
				val.erase(val.find(path(jt->ss-1, it->ff, dep, par, mx)));
			}
			auto kt = it;
			kt++;
			if(kt != end(I)) {
				val.erase(val.find(path(it->ss-1, kt->ff, dep, par, mx)));
			}
			if(it != begin(I) && kt != end(I)) {
				val.insert(path(jt->ss-1, kt->ff, dep, par, mx));
			}
			I.erase(it);
		}
		for(auto p : nw) {
			I.insert(p);
			int m = 0;
			l = p.ff, r = p.ss-1;;
			for(int k = 19; k >= 0; k--) if(((r-l)>>k)&1) {
				m = max(m, cost[k][l]);
				l += 1<<k;
			}
			val.insert(m);
			it = I.find(p);
			auto jt = it;
			if(it != begin(I)) jt--;
			auto kt = it;
			kt++;
			if(it != begin(I) && kt != end(I)) {
				val.erase(val.find(path(jt->ss-1, kt->ff, dep, par, mx)));
			}
			if(it != begin(I)) {
				val.insert(path(jt->ss-1, it->ff, dep, par, mx));
			}
			if(kt != end(I)) {
				val.insert(path(it->ss-1, kt->ff, dep, par, mx));
			}
		}
	}
}

// look at my code
// my code is amazing