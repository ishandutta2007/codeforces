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

struct query {
	int cap, st, id;

	bool operator<(const query & q) const {
		return cap < q.cap;
	}
};

void DFS(int v, auto & G, auto & par, auto & dep, auto & val) {
	for(int i = 1; i <= 18; i++) par[i][v] = par[i-1][par[i-1][v]];
	for(int i = 1; i <= 18; i++) val[i][v] = max(val[i-1][par[i-1][v]], val[i-1][v]);
	for(auto [s,t] : G[v]) if(s != par[0][v]) {
		par[0][s] = v;
		dep[s] = dep[v]+1;
		val[0][s] = t;
		DFS(s, G, par, dep, val);
	}
}

int get_val(int u, int v, auto & par, auto & dep, auto & val) {
	int ret = 0;
	if(dep[u] > dep[v]) swap(u, v);
	for(int i = 18; i >= 0; i--) if(dep[par[i][v]] >= dep[u]) {
		ret = max(ret, val[i][v]);
		v = par[i][v];
	}
	if(v == u) return ret;
	for(int i = 18; i >= 0; i--) if(par[i][v] != par[i][u]) {
		ret = max(ret, max(val[i][u], val[i][v]));
		u = par[i][u];
		v = par[i][v];
	}
	ret = max(ret, max(val[0][u], val[0][v]));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N,Q;
	cin >> N >> Q;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector< vector< pair<int,int> > > G(N);
	vector< pair<int, pair<int,int> > > E(N-1);
	for(int i = 0; i < N-1; i++) {
		int a,b,c,t;
		cin >> a >> b >> c >> t;
		G[--a].push_back({--b, t});
		G[b].push_back({a, t});
		E[i] = {c, {a,b}};
	}
	sort(begin(E), end(E));
	vector<query> qs(Q);
	for(int i = 0; i < Q; i++) {
		cin >> qs[i].cap >> qs[i].st;
		qs[i].st--;
		qs[i].id = i;
	}
	sort(begin(qs), end(qs));
	vector< pair<int,int> > ans(Q);

	vector< vector<int> > par(20, vector<int>(N, -1)), val(20, vector<int>(N, 0));
	par[0][0] = 0;
	vector<int> dep(N, 0);
	DFS(0, G, par, dep, val);

	vector< vector<int> > comp(N);
	vector<int> in_comp(N), mx_comp(N), toll(N, 0);
	for(int i = 0; i < N; i++) in_comp[i] = mx_comp[i] = i, comp[i] = {i};
	for(int i = Q-1, a = N-2; i >= 0; i--) {
		while(a >= 0 && E[a].ff >= qs[i].cap) {
			auto [u,v] = E[a].ss;
			a--;
			// merge components of u,v
			u = in_comp[u], v = in_comp[v];
			if(comp[u].size() > comp[v].size()) swap(u,v);
			if(A[mx_comp[u]] > A[mx_comp[v]]) {
				mx_comp[v] = mx_comp[u];
				toll[v] = toll[u];
			}
			else if(A[mx_comp[u]] == A[mx_comp[v]])
				toll[v] = max(toll[v], max(toll[u], get_val(mx_comp[u], mx_comp[v], par, dep, val)));
			for(auto w : comp[u]) {
				in_comp[w] = v;
				comp[v].push_back(w);
			}
		}
		int c = in_comp[qs[i].st];
		ans[qs[i].id].ff = A[mx_comp[c]];
		ans[qs[i].id].ss = max(toll[c], get_val(qs[i].st, mx_comp[c], par, dep, val));
	}

	for(int i = 0; i < Q; i++) cout << ans[i].ff << " " << ans[i].ss << "\n";
}

// look at my code
// my code is amazing