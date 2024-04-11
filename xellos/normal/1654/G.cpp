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

constexpr int MX = 200000;
char bl[MX];
int sz[MX];
int H[MX];
int max_d[MX];
int tmp2[MX];
int n,c;
int ans[MX];

void DFS(int v, int prev, auto & G, auto & comp) {
	sz[v] = 1;
	comp.push_back(v);
	for(auto s : G[v]) if(s != prev && !bl[s]) {
		DFS(s, v, G, comp);
		sz[v] += sz[s];
	}
}

void DFS2(int v, int prev, auto & G, int d = 0, int cur = 0, int mi = 0) {
	bool has_eq = false;
	for(auto s : G[v]) if(H[s] == H[v]) has_eq = true;
	if(!has_eq) max_d[-mi] = max(max_d[-mi], d);
	else {
		max_d[-mi] = max(max_d[-mi], d+H[v]+(cur-mi)/2*2);
		int k0 = (cur-mi)/2+1;
		if(2*k0-cur < n) tmp2[2*k0-cur] = max(tmp2[2*k0-cur], d+H[v]+2*k0);
	}
	for(auto s : G[v]) if(s != prev && !bl[s]) {
		if(H[s] > H[v]) continue;
		int nxt = (H[s] == H[v]) ? (cur-1) : (cur+1);
		DFS2(s, v, G, d+1, nxt, min(nxt,mi));
	}
}

void DFS3(int v, int prev, auto & G, int d = 0, int cur = 0, int mi = 0, int id_eq = -1) {
	if(id_eq == -1) for(auto s : G[v]) if(H[s] == H[v]) id_eq = v;
	if(mi == cur) ans[v] = max(ans[v], d+max_d[-cur]);
	if(id_eq != -1) {
		if(mi == cur && H[c]-H[id_eq]-cur >= 0)
			ans[v] = max(ans[v], d+H[c]+(H[c]-H[id_eq]-cur)/2*2);
	}
	for(auto s : G[v]) if(s != prev && !bl[s]) {
		if(H[s] < H[v]) continue;
		int nxt = (H[s] == H[v]) ? (cur+1) : (cur-1);
		DFS3(s, v, G, d+1, nxt, min(nxt,mi), id_eq);
	}
}

void solve(int r, auto & G) {
	static vector<int> comp;
	comp.clear();
	DFS(r, r, G, comp);
	n = comp.size();
	c = r;
	for(auto v : comp) if(2*sz[v] >= n) {
		bool ok = true;
		for(auto s : G[v]) ok &= (bl[s] || sz[s] >= sz[v] || 2*sz[s] <= n);
		if(ok) c = v;
	}
	comp.clear();
	r = c;
	for(int i = 0; i < n; i++) max_d[i] = 0, tmp2[i] = -2*n;
	DFS2(r, r, G);
	for(int i = 0; i < n; i++) {
		max_d[i] = max(max_d[i], tmp2[i]);
		if(i+2 < n) tmp2[i+2] = max(tmp2[i+2], tmp2[i]+2);
	}
	for(int i = 1; i < n; i++) max_d[i] = max(max_d[i], max_d[i-1]);
	DFS3(r, r, G);
	bl[r] = true;
	for(auto s : G[r]) if(!bl[s]) solve(s, G);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int N;
	cin >> N;
	vector<int> L(N);
	for(int i = 0; i < N; i++) cin >> L[i];
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u,v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	queue<int> q;
	for(int i = 0; i < N; i++) {
		if(L[i]) q.push(i);
		H[i] = (L[i] ? 0 : N);
	}
	while(!q.empty()) {
		for(auto v : G[q.front()]) if(H[v] == N) {
			H[v] = H[q.front()]+1;
			q.push(v);
		}
		q.pop();
	}
	memset(bl, 0, sizeof(bl));
	memset(ans, 0, sizeof(ans));
	solve(0, G);
	for(int i = 0; i < N; i++) cout << ans[i] << ((i == N-1) ? "\n" : " ");
}

// look at my code
// my code is amazing