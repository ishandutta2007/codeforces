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

void DFS(int R, auto & G, auto & par, auto & dep, bool & ok) {
	static char in_st[100010];
	in_st[R] = 1;
	for(auto s : G[R]) if(par[s] == -1) {
		par[s] = R;
		dep[s] = dep[R]+1;
		DFS(s, G, par, dep, ok);
		if(!ok) break;
	}
	if(ok)
		for(auto s : G[R]) if(par[s] != R && !in_st[s]) ok = false;
	in_st[R] = 0;
}

void DFS_solve_up(int R, auto & G, auto & Gi, auto & par, auto & dep, auto & up, auto & up_cnt) {
	for(auto s : G[R]) if(par[s] == R) {
		DFS_solve_up(s, G, Gi, par, dep, up, up_cnt);
		up_cnt[R] += up_cnt[s];
		if(up[s] == -1 || up[s] == R) continue;
		if(up[R] == -1) up[R] = up[s];
		if(dep[up[R]] > dep[up[s]]) up[R] = up[s];
	}
	for(auto s : G[R]) if(par[s] != R) {
		if(up[R] == -1) up[R] = s;
		if(dep[up[R]] > dep[s]) up[R] = s;
		up_cnt[R]++;
	}
	for(auto s : Gi[R]) if(s != par[R]) up_cnt[R]--;
}

void DFS_solve(int R, auto & G, auto & par, auto & up, auto & up_cnt, auto & good) {
	if(up_cnt[R] == 1 && good[up[R]]) good[R] = 1;
	for(auto s : G[R]) if(par[s] == R) DFS_solve(s, G, par, up, up_cnt, good);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector< vector<int> > G(N), Gi(N);
		for(int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			G[--u].push_back(--v);
			Gi[v].push_back(u);
		}
		mt19937 rng(N+(M^12345));
		vector<char> tried(N, 0), good(N, 0);
		for(int rep = 0; rep < min(N, 100); rep++) {
			int R = rng()%N;
			while(R < N && tried[R]) R++;
			if(R == N) {
				R--;
				while(tried[R]) R--;
			}
			tried[R] = 1;
			vector<int> par(N, -1), dep(N, 0);
			par[R] = R;
			bool ok = true;
			DFS(R, G, par, dep, ok);
			for(int i = 0; i < N; i++) if(par[i] == -1) ok = false;
			if(!ok) continue;
			vector<int> up(N, -1), up_cnt(N, 0);
			DFS_solve_up(R, G, Gi, par, dep, up, up_cnt);
			good[R] = 1;
			DFS_solve(R, G, par, up, up_cnt, good);
			break;
		}
		int cnt = 0;
		for(int i = 0; i < N; i++) cnt += good[i];
		if(cnt*5 < N) cout << "-1\n";
		else for(int i = 0; i < N; i++) if(good[i]) cout << i+1 << ((--cnt) ? " " : "\n");
	}
}

// look at my code
// my code is amazing