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
#define abs(x) (((x) < 0)?-(x):(x))
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

void DFS(int R, auto & G, auto & par, auto & sz, auto & dep) {
	sz[R] = 1;
	for(auto v : G[R]) if(par[v] == -1) {
		par[v] = R;
		dep[v] = dep[R]+1;
		DFS(v, G, par, sz, dep);
		sz[R] += sz[v];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N, K;
	cin >> N >> K;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<int> sz(N, 0), dep(N, 0), par(N, -1);
	par[0] = 0;
	DFS(0, G, par, sz, dep);
	// value(i) == dep[i]-sz[i]+1
	priority_queue< pair<int, int> > q;
	for(int i = 1; i < N; i++) if(G[i].size() == 1U) q.push({dep[i]-sz[i]+1, i});
	vector<int> sons(N, 0);
	for(int i = 1; i < N; i++) sons[par[i]]++;
	cat ans = 0;
	for(int k = 0; k < K; k++) {
		pair<int, int> p = q.top();
		q.pop();
		ans += p.ff;
		if(--sons[par[p.ss]] == 0)
			q.push({dep[par[p.ss]]-sz[par[p.ss]]+1, par[p.ss]});
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing