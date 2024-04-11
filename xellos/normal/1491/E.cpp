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

vector<int> vis_v;

void DFS(int v, int prev, auto & G, auto & bl, auto & sz_cur, auto & par_cur) {
	vis_v.push_back(v);
	sz_cur[v] = 1;
	for(auto s : G[v]) if(s != prev && !bl[s]) {
		DFS(s, v, G, bl, sz_cur, par_cur);
		par_cur[s] = v;
		sz_cur[v] += sz_cur[s];
	}
}

vector<int> sz[30], par[30];
int F[30];

bool solve(int R, vector< vector<int> > & G, vector<char> & bl, int f_id, int rdep = 0) {
	DFS(R, R, G, bl, sz[rdep], par[rdep]);
	if(sz[rdep][R] <= 3) {
		vis_v.clear();
		return true;
	}
	int cand[2] = {-1, -1};
	for(auto v : vis_v) if(sz[rdep][v] == F[f_id-1] || sz[rdep][v] == F[f_id-2]) {
		if(cand[0] == -1) cand[0] = v;
		else cand[1] = v;
	}
	vis_v.clear();
	bool t = false;
	for(int k = 0; k < 2; k++) if(cand[k] != -1) {
		int a = cand[k], b = par[rdep][cand[k]];
		if(sz[rdep][a] == F[f_id-2]) swap(a, b);
		bl[a] = 1;
		bool ok = solve(b, G, bl, f_id-2, rdep+1);
		bl[a] = 0;
		if(!ok) continue;
		if(k == 0) t = true;
		if(k == 1 && t) return false;
		bl[b] = 1;
		ok = solve(a, G, bl, f_id-1, rdep+1);
		bl[b] = 0;
		if(ok) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	F[0] = F[1] = 1;
	for(int i = 2; i < 30; i++) F[i] = F[i-1] + F[i-2];
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<char> bl(N, 0);
	for(int i = 0; i < 30; i++) sz[i].resize(N);
	for(int i = 0; i < 30; i++) par[i].resize(N);
	int f_id = 0;
	while(F[f_id] < N) f_id++;
	cout << ((F[f_id] == N && solve(0, G, bl, f_id)) ? "YES\n" : "NO\n");
}

// look at my code
// my code is amazing