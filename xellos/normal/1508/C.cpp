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

template <typename T>
class minfin {
	vector<T> node_val;
	T init_val_;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	minfin(int N, T init_val) {
		init_val_ = init_val;
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] = min(node_val[i], val);
	}

	T get(int pos) {
		T ret = init_val_;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret = min(ret, node_val[i]);
		return ret;
	}
};

void DFS(int v, int prev, auto & G, auto & dep, auto & par) {
	for(auto s : G[v]) if(s != prev) {
		dep[s] = dep[v]+1;
		par[s] = v;
		DFS(s, v, G, dep, par);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N, M;
	cin >> N >> M;
	vector< vector< pair<int, int> > > G(N);
	vector<int> W(M);
	cat x = 0;
	for(int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		G[--u].push_back({--v,i});
		G[v].push_back({u,i});
		W[i] = w;
		x ^= w;
	}
	vector<int> in_ucomp(N, -1);
	int nc = 0;
	vector<int> fr(N);
	for(int i = 0; i < N; i++) fr.push_back(i);
	vector<char> bl(N, 0);
	for(int r = 0; r < N; r++) if(in_ucomp[r] == -1) {
		in_ucomp[r] = nc;
		static queue<int> q;
		q.push(r);
		while(!q.empty()) {
			for(auto p : G[q.front()]) bl[p.ff] = 1;
			for(int i = 0; i < (int)fr.size(); i++) {
				if(bl[fr[i]]) continue;
				if(in_ucomp[fr[i]] == -1) {
					in_ucomp[fr[i]] = nc;
					q.push(fr[i]);
				}
				swap(fr.back(), fr[i]);
				fr.pop_back();
				i--;
			}
			for(auto p : G[q.front()]) bl[p.ff] = 0;
			q.pop();
		}
		nc++;
	}
	vector< vector< pair<int, int> > > Gc(nc);
	for(int i = 0; i < N; i++) for(auto p : G[i]) if(in_ucomp[i] != in_ucomp[p.ff]) {
		Gc[in_ucomp[i]].push_back({in_ucomp[p.ff], p.ss});
		Gc[in_ucomp[p.ff]].push_back({in_ucomp[i], p.ss});
	}
	priority_queue< pair<int,cat>, vector< pair<int,cat> >, greater< pair<int,cat> > > q;
	vector<char> used(nc, 0);
	used[0] = 1;
	for(auto p : Gc[0]) q.push({W[p.ss], 1LL*N*p.ss+p.ff});
	cat ans0 = 0;
	vector<char> MST(M, 0);
	while(!q.empty()) {
		auto p = q.top();
		q.pop();
		int v = p.ss%N;
		if(used[v]) continue;
		used[v] = 1;
		ans0 += p.ff;
		MST[p.ss/N] = 1;
		for(auto r : Gc[v]) if(!used[r.ff]) q.push({W[r.ss], 1LL*N*r.ss+r.ff});
	}
	if(nc != N-(1LL*N*(N-1)/2-M)) {
		cout << ans0 << "\n";
		return 0;
	}
	vector< vector<int> > tp(N, vector<int>(N, 0));
	vector< vector<int> > WM(N, vector<int>(N, x));
	vector< vector<int> > Gt(N);
	for(int i = 0; i < N; i++) for(auto p : G[i]) {
		if(MST[p.ss]) tp[i][p.ff] = 1, Gt[i].push_back(p.ff);
		else tp[i][p.ff] = 2, WM[i][p.ff] = min((int)x, W[p.ss]);
	}
	for(int i = 0; i < N; i++) for(int j = 0; j < i; j++) if(tp[i][j] == 0) {
		Gt[i].push_back(j);
		Gt[j].push_back(i);
	}
	vector< vector<int> > par(N, vector<int>(N));
	vector< vector<int> > dep(N, vector<int>(N, 0));
	for(int i = 0; i < N; i++) {
		par[i][i] = i;
		DFS(i, i, Gt, dep[i], par[i]);
	}
	vector< vector< pair<int,int> > > by_dep(N+1);
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) by_dep[dep[i][j]].push_back({i,j});
	for(int d = N; d > 0; d--) for(auto p : by_dep[d]) {
		int pp = par[p.ff][p.ss];
		WM[pp][p.ff] = min(WM[pp][p.ff], WM[p.ff][p.ss]);
		WM[p.ff][pp] = min(WM[p.ff][pp], WM[p.ff][p.ss]);
	}
	cat max_dif = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < i; j++) if(tp[i][j] == 0) {
		max_dif = max(max_dif, x-WM[i][j]);
	}
	cout << ans0+x-max_dif << "\n";
}

// look at my code
// my code is amazing