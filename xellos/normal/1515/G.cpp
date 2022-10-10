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

int cur_idx;
vector<int> idx, st, up;
vector<char> in_st;
int n_scc;
vector<int> id_scc;

void DFS_SCC(int v, auto & G) {
	idx[v] = cur_idx++;
	up[v] = idx[v];
	in_st[v] = 1;
	st.push_back(v);
	for(auto p : G[v]) {
		if(idx[p.ff] == -1) {
			DFS_SCC(p.ff, G);
			up[v] = min(up[v], up[p.ff]);
		}
		else if(in_st[p.ff]) up[v] = min(up[v], idx[p.ff]);
	}
	if(up[v] == idx[v]) {
		while(true) {
			int u = st.back();
			st.pop_back();
			in_st[u] = 0;
			id_scc[u] = n_scc;
			if(u == v) break;
		}
		n_scc++;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M, Q;
	cin >> N >> M;
	vector< vector< pair<int, cat> > > G(N);
	for(int i = 0; i < M; i++) {
		int a, b;
		cat c;
		cin >> a >> b >> c;
		G[a-1].push_back({b-1, c});
	}
	cur_idx = 0;
	idx.resize(N, -1);
	up.resize(N, N+1);
	in_st.resize(N, 0);
	id_scc.resize(N);
	n_scc = 0;
	for(int i = 0; i < N; i++) if(idx[i] == -1) DFS_SCC(i, G);
	vector<int> r_scc(n_scc);
	for(int i = 0; i < N; i++) {
		vector< pair<int, cat> > V;
		for(auto p : G[i]) if(id_scc[p.ff] == id_scc[i]) V.push_back(p);
		G[i] = V;
		r_scc[id_scc[i]] = i;
	}
	vector<cat> gcd_cyc(n_scc, 0);
	vector<cat> dist(N, 0);
	for(int i = 0; i < n_scc; i++) {
		int r = r_scc[i];
		vector<int> comp;
		static queue<int> q;
		q.push(r);
		while(!q.empty()) {
			comp.push_back(q.front());
			for(auto p : G[q.front()]) if(dist[p.ff] == 0) {
				dist[p.ff] = dist[q.front()] + p.ss;
				q.push(p.ff);
			}
			q.pop();
		}
		gcd_cyc[i] = dist[r];
		while(true) {
			cat g = gcd_cyc[i];
			for(auto v : comp) for(auto p : G[v]) {
				cat D = (dist[p.ff]-dist[v] - p.ss) % g;
				if(D == 0) continue;
				if(D < 0) D += g;
				gcd_cyc[i] = gcd(gcd_cyc[i], D);
			}
			if(g == gcd_cyc[i]) break;
		}
	}
	cin >> Q;
	for(int q = 0; q < Q; q++) {
		int qv;
		cat qs, qt;
		cin >> qv >> qs >> qt;
		cat gcd_cur = gcd(gcd_cyc[id_scc[qv-1]], qt);
		cout << ((qs%gcd_cur == 0) ? "YES\n" : "NO\n");
	}
}

// look at my code
// my code is amazing