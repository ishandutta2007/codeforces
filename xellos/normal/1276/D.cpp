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

cat mod = 998244353;

vector<cat> dp[3];

void DFS(int R, int par, int par_e, auto & G) {
	dp[0][R] = 1;
	vector< pair<int, int> > prev_e, next_e;
	for(auto [v, e] : G[R]) if(v != par) {
		DFS(v, R, e, G);
		dp[0][R] = dp[0][R] * ((e > par_e) ? (dp[1][v]+dp[2][v]) : (dp[1][v]+dp[0][v])) % mod;
		if(e > par_e) next_e.push_back({e, v});
		else prev_e.push_back({e, v});
	}
	sort(begin(prev_e), end(prev_e));
	sort(begin(next_e), end(next_e));
	{
		int M = prev_e.size();
		vector<cat> c_prev(M+1, 1), c_next(M+1, 1);
		for(int i = 0; i < M; i++) {
			int v = prev_e[i].ss;
			c_prev[i+1] = c_prev[i] * (dp[1][v]+dp[0][v]) % mod;
		}
		for(auto [e, v] : next_e) c_next[M] = c_next[M] * (dp[1][v]+dp[2][v]) % mod;
		for(int i = M-1; i >= 0; i--) {
			int v = prev_e[i].ss;
			c_next[i] = c_next[i+1] * (dp[1][v]+dp[2][v]) % mod;
		}
		for(int i = 0; i < M; i++) {
			int v = prev_e[i].ss;
			dp[1][R] = (dp[1][R] + c_prev[i] * c_next[i+1] % mod * dp[2][v]) % mod;
		}
	}
	{
		int M = next_e.size();
		vector<cat> c_prev(M+1, 1), c_next(M+1, 1);
		for(auto [e, v] : prev_e) c_prev[0] = c_prev[0] * (dp[1][v]+dp[0][v]) % mod;
		for(int i = 0; i < M; i++) {
			int v = next_e[i].ss;
			c_prev[i+1] = c_prev[i] * (dp[1][v]+dp[0][v]) % mod;
		}
		for(int i = M-1; i >= 0; i--) {
			int v = next_e[i].ss;
			c_next[i] = c_next[i+1] * (dp[1][v]+dp[2][v]) % mod;
		}
		dp[2][R] = c_prev[M];
		for(int i = 0; i < M; i++) {
			int v = next_e[i].ss;
			dp[2][R] = (dp[2][R] + c_prev[i] * c_next[i+1] % mod * dp[2][v]) % mod;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector< pair<int, int> > > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back({--v, i});
		G[v].push_back({u, i});
	}
	N++;
	G[0].push_back({N-1, N-1});
	G.push_back({{0, N-1}});
	dp[0].resize(N, 0);
	dp[1].resize(N, 0);
	dp[2].resize(N, 0);
	DFS(0, N-1, N-1, G);
	cout << (dp[0][0]+dp[1][0])%mod << "\n";
	return 0;
}

// look at my code
// my code is amazing