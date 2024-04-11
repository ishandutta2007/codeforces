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
#define OVER9000 1234567890
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
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
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i)) {
			node_val[i] += val;
		}
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i)) {
			ret += node_val[i];
		}
		return ret;
	}
};

struct edge {
	int u,v,c,id;

	bool operator<(const edge & e) const {
		return this->c < e.c;
	}
};

void DFS(int cur, int prev, vector< vector< pair<int,int> > > & G, vector<int> & dep, vector<int> & par, vector<int> & cost) {
	for(auto p : G[cur]) if(p.ff != prev) {
		dep[p.ff] = dep[cur]+1;
		par[p.ff] = cur;
		cost[p.ff] = p.ss;
		DFS(p.ff, cur, G, dep, par, cost);
	}
}

void merge(pair<int,int> & P, pair<int,int> & P2, vector<int> & in_comp2, vector< vector<int> > & comp2) {
	if(P.ss == -1 && P2.ff == -1) {
		P.ss = P2.ss;
		return;
	}
	if(P2.ss == -1 && P.ff == -1) {
		P.ff = P2.ff;
		return;
	}
	if(P.ff != -1 && P2.ff != -1) {
		int cG = P.ff, cs = P2.ff;
		if(comp2[cG].size() < comp2[cs].size()) swap(cG, cs);
		for(auto v : comp2[cs]) {
			in_comp2[v] = cG;
			comp2[cG].push_back(v);
		}
		P.ff = cG;
	}
	else if(P.ff == -1) P.ff = P2.ff;
	if(P.ss != -1 && P2.ss != -1) {
		int cG = P.ss, cs = P2.ss;
		if(comp2[cG].size() < comp2[cs].size()) swap(cG, cs);
		for(auto v : comp2[cs]) {
			in_comp2[v] = cG;
			comp2[cG].push_back(v);
		}
		P.ss = cG;
	}
	else if(P.ss == -1) P.ss = P2.ss;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector<edge> E(M);
		for(int i = 0; i < M; i++) {
			cin >> E[i].u >> E[i].v >> E[i].c;
			E[i].u--, E[i].v--;
			E[i].id = i;
		}
		sort(begin(E), end(E));
		vector< pair<int,int> > Ep(2*M);
		for(int i = 0; i < M; i++) {
			Ep[2*i] = {E[i].u, E[i].v};
			Ep[2*i+1] = {E[i].v, E[i].u};
		}
		sort(begin(Ep), end(Ep));
		vector<int> in_comp(N), in_comp2(N);
		vector< vector<int> > comp(N), comp2(N);
		for(int i = 0; i < N; i++) {
			in_comp[i] = in_comp2[i] = i;
			comp[i] = comp2[i] = {i};
		}
		vector< vector< pair<int,int> > > G(N); // MST of complement
		for(int i = 0; i < M; i++) {
			int cu = in_comp[in_comp2[E[i].u]], cv = in_comp[in_comp2[E[i].v]];
			if(cu == cv) continue;
			vector< pair<int,int> > R1_all(comp[cu].size());
			for(int j = 0; j < (int)comp[cu].size(); j++) R1_all[j] = {comp[cu][j], -1};
			comp[cu].clear();
			for(auto c2 : comp[cv]) {
				pair<int,int> P = {-1, c2};
				for(int j = 0; j < (int)R1_all.size(); j++) {
					bool has_edge = false;
					int eu = -1, ev = -1;
					for(auto v : comp2[P.ss]) {
						if(has_edge) break;
						for(auto u : comp2[R1_all[j].ff]) {
							pair<int,int> ec = {u,v};
							if(auto it = lower_bound(begin(Ep), end(Ep), ec); it != end(Ep) && *it == ec) continue;
							has_edge = true;
							eu = u, ev = v;
							break;
						}
					}
					if(!has_edge) continue;
					G[eu].push_back({ev, E[i].c});
					G[ev].push_back({eu, E[i].c});
					in_comp[R1_all[j].ff] = cu;
					if(R1_all[j].ss != -1) in_comp[R1_all[j].ss] = cu;
					merge(P, R1_all[j], in_comp2, comp2);
					swap(R1_all[j], R1_all.back());
					R1_all.pop_back();
					j--;
				}
				if(P.ff == -1) {
					in_comp[c2] = cu;
					comp[cu].push_back(c2);
				}
				else R1_all.push_back(P);
			}
			for(auto p : R1_all) {
				if(p.ff != -1) in_comp[p.ff] = cu;
				if(p.ss != -1) in_comp[p.ss] = cu;
				if(p.ff == -1 || p.ss == -1) {
					if(p.ff != -1) comp[cu].push_back(p.ff);
					if(p.ss != -1) comp[cu].push_back(p.ss);
					continue;
				}
				int cG = p.ff, cs = p.ss;
				if(comp2[cG].size() < comp2[cs].size()) swap(cG, cs);
				for(auto v : comp2[cs]) {
					in_comp2[v] = cG;
					comp2[cG].push_back(v);
				}
				comp[cu].push_back(cG);
			}
		}
		vector<int> dep(N, 0);
		vector< vector<int> > par(20, vector<int>(N, 0));
		vector< vector<int> > cost(20, vector<int>(N, 0));
		DFS(0, 0, G, dep, par[0], cost[0]);
		for(int i = 1; i < 18; i++) for(int j = 0; j < N; j++) par[i][j] = par[i-1][par[i-1][j]];
		for(int i = 1; i < 18; i++) for(int j = 0; j < N; j++) cost[i][j] = max(cost[i-1][j], cost[i-1][par[i-1][j]]);
		vector<int> ans(M, 0);
		for(int i = 0; i < M; i++) {
			int u = E[i].u, v = E[i].v;
			if(dep[u] > dep[v]) swap(u, v);
			for(int k = 17; k >= 0; k--) if((dep[v]-dep[u])>>k) {
				ans[E[i].id] = max(ans[E[i].id], cost[k][v]);
				v = par[k][v];
			}
			if(u == v) continue;
			for(int k = 17; k >= 0; k--) if(par[k][u] != par[k][v]) {
				ans[E[i].id] = max(ans[E[i].id], cost[k][u]);
				ans[E[i].id] = max(ans[E[i].id], cost[k][v]);
				u = par[k][u];
				v = par[k][v];
			}
			ans[E[i].id] = max(ans[E[i].id], cost[0][u]);
			ans[E[i].id] = max(ans[E[i].id], cost[0][v]);
		}
		for(int i = 0; i < M; i++) cout << ans[i] << ((i == M-1) ? "\n" : " ");
	}
}

// look at my code
// my code is amazing