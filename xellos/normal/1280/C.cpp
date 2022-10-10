// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

void DFS_min(int R, int par, auto & G, auto & sz, cat & ret) {
	sz[R] = 1;
	for(auto [v, l] : G[R]) if(par != v) {
		DFS_min(v, R, G, sz, ret);
		if(sz[v]&1) ret += l;
		sz[R] += sz[v];
	}
}

cat solve_min(auto & G) {
	int N = G.size();
	cat ret = 0;
	vector<cat> sz(N);
	DFS_min(0, 0, G, sz, ret);
	return ret;
}

void DFS_max(int R, int par, auto & G, auto & sz, cat & ret) {
	sz[R] = 1;
	for(auto [v, l] : G[R]) if(par != v) {
		DFS_max(v, R, G, sz, ret);
		ret += sz[v] * l;
		sz[R] += sz[v];
	}
}

cat solve_max(auto & G) {
	int N = G.size();
	cat ret = 0;
	vector<cat> sz(N);
	DFS_min(0, 0, G, sz, ret);
	int C = 0;
	for(int i = 0; i < N; i++) {
		bool is_C = (2*(N-sz[i]) <= N);
		for(auto p : G[i])
			if(sz[p.ff] < sz[i] && 2*sz[p.ff] > N) is_C = false;
		if(is_C) C = i;
	}
	ret = 0;
	DFS_max(C, C, G, sz, ret);
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		N *= 2;
		vector< vector< pair<int, cat> > > G(N);
		for(int i = 0; i < N-1; i++) {
			int u, v, l;
			cin >> u >> v >> l;
			G[--u].push_back({--v, l});
			G[v].push_back({u, l});
		}
		cout << solve_min(G) << " ";
		cout << solve_max(G) << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing