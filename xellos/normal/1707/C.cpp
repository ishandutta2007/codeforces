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

void DFS(int v, auto & G, auto & par, auto & dep) {
	for(auto s : G[v]) if(par[s] == -1) {
		par[s] = v;
		dep[s] = dep[v]+1;
		DFS(s, G, par, dep);
	}
}

void DFS2(int v, auto & G, auto & par, auto & cov) {
	for(auto s : G[v]) if(par[v] != s) {
		cov[s] += cov[v];
		DFS2(s, G, par, cov);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M;
	cin >> N >> M;
	vector< vector<int> > G(N), comp(N);
	vector<int> in_comp(N);
	for(int i = 0; i < N; i++) in_comp[i] = i, comp[i] = {i};
	vector< pair<int,int> > bad;
	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		int cu = in_comp[u], cv = in_comp[v];
		if(cu == cv) {
			bad.push_back({u, v});
			continue;
		}
		G[u].push_back(v);
		G[v].push_back(u);
		if(comp[cu].size() > comp[cv].size()) swap(cu, cv);
		for(auto w : comp[cu]) {
			in_comp[w] = cv;
			comp[cv].push_back(w);
		}
	}
	vector< vector<int> > par(20, vector<int>(N, -1));
	vector<int> dep(N, -1);
	par[0][0] = 0;
	DFS(0, G, par[0], dep);
	for(int k = 1; k < 18; k++) for(int i = 0; i < N; i++)
		par[k][i] = par[k-1][par[k-1][i]];
	vector<int> cov(N, 0);
	for(auto p : bad) {
		int u = p.ff, v = p.ss;
		if(dep[u] > dep[v]) {
			swap(u, v);
			swap(p.ff, p.ss);
		}
		int d = dep[v]-dep[u];
		for(int k = 0; k < 18; k++) if((d>>k)&1) v = par[k][v];
		if(u != v) {
			cov[p.ff]++;
			cov[p.ss]++;
		}
		else {
			cov[p.ss]++;
			cov[0]++;
			v = p.ss;
			d--;
			for(int k = 0; k < 18; k++) if((d>>k)&1) v = par[k][v];
			cov[v]--;
		}
	}
	DFS2(0, G, par[0], cov);
	string ans;
	for(int i = 0; i < N; i++) ans += (cov[i] == M-N+1) ? '1' : '0';
	cout << ans << "\n";
}

// look at my code
// my code is amazing