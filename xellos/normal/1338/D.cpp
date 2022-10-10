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

void DFS(int R, auto & G, auto & par, vector<int> * dp, int & ans) {
	dp[0][R] = G[R].size();
	int mx[5] = {0, 0, 0, 0, 0};
	for(auto v : G[R]) if(par[v] == -1) {
		par[v] = R;
		DFS(v, G, par, dp, ans);
		static const int d[5] = {2, 1, 1, 0, 0};
		ans = max(ans, mx[3]+dp[0][v]);
		ans = max(ans, mx[1]+dp[2][v]);
		ans = max(ans, dp[0][v]+mx[1]-1);
		for(int k = 0; k < 5; k++) for(int i = 0; i < 4; i++)
			ans = max(ans, (int)G[R].size()+mx[i+1]-d[i]+dp[k][v]-d[k]);
		for(int k = 1; k < 5; k++) mx[k] = max(mx[k], dp[k-1][v]);
		for(int k = 0; k < 5; k++) mx[0] = max(mx[0], dp[k][v]-d[k]);
	}
	for(int k = 0; k < 5; k++) dp[k][R] += mx[k];
	for(int k = 3; k >= 0; k--) dp[k][R] = max(dp[k][R], dp[k+1][R]);
	ans = max(ans, dp[0][R]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector< vector<int> > G(N);
	for(int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		G[--u].push_back(--v);
		G[v].push_back(u);
	}
	vector<int> dp[5];
	for(int k = 0; k < 5; k++) dp[k].resize(N, 0);
	vector<int> par(N, -1);
	par[0] = 0;
	int ans = 0;
	DFS(0, G, par, dp, ans);
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing