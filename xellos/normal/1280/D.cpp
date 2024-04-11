// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
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

int dp[3010][2][3010];
cat dp_sum[3010][3010];

void DFS(int R, int par, auto & G, auto & cnt, auto & sz) {
	for(auto v : G[R]) if(v != par) {
		DFS(v, R, G, cnt, sz);
		sz[R] += sz[v];
	}
	memset(&(dp[R][0][0]), 0, sizeof(int)*(sz[R]+1));
	memset(&(dp[R][1][0]), 0, sizeof(int)*(sz[R]+1));
	memset(&(dp_sum[R][0]), -1, sizeof(cat)*(sz[R]+1));
	dp_sum[R][0] = cnt[R];
	int sz_cur = 1;
	for(auto v : G[R]) if(v != par) {
		for(int i = sz_cur-1; i >= 0; i--) {
			int dp_init = dp[R][0][i];
			dp[R][0][i] = dp_init + dp[v][0][0];
			for(int j = 1; j <= sz[v]; j++)
				dp[R][0][i+j] = max(dp[R][0][i+j], dp_init + dp[v][0][j]);
		}
		for(int i = sz_cur-1; i >= 0; i--) {
			int dp_init = dp[R][1][i];
			cat dp_sum_init = dp_sum[R][i];
			dp[R][1][i] = dp_init + dp[v][1][0];
			dp_sum[R][i] = dp_sum_init + dp_sum[v][0];
			for(int j = 1; j <= sz[v]; j++) {
				if(dp[R][1][i+j] < dp_init+dp[v][1][j]) {
					dp[R][1][i+j] = dp_init + dp[v][1][j];
					dp_sum[R][i+j] = dp_sum_init + dp_sum[v][j];
				}
				else if(dp[R][1][i+j] == dp_init+dp[v][1][j])
					dp_sum[R][i+j] = max(dp_sum[R][i+j], dp_sum_init + dp_sum[v][j]);
			}
		}
		sz_cur += sz[v];
	}
	for(int i = sz_cur-1; i >= 0; i--) {
		int m = max(dp[R][0][i], dp[R][1][i] + (dp_sum[R][i] > 0));
		dp[R][0][i+1] = max(dp[R][0][i+1], m);
		if(dp[R][1][i+1] < m) {
			dp[R][1][i+1] = m;
			dp_sum[R][i+1] = 0LL;
		}
		else if(dp[R][1][i+1] == m)
			dp_sum[R][i+1] = max(dp_sum[R][i+1], 0LL);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N, M;
		cin >> N >> M;
		vector<cat> cnt(N, 0);
		for(int k = 0; k < 2; k++) for(int i = 0; i < N; i++) {
			int a;
			cin >> a;
			cnt[i] += k ? a : -a;
		}
		vector< vector<int> > G(N);
		for(int i = 0; i < N-1; i++) {
			int u, v;
			cin >> u >> v;
			G[--u].push_back(--v);
			G[v].push_back(u);
		}
		vector<int> sz(N, 1);
		DFS(0, 0, G, cnt, sz);
		cout << max(dp[0][0][M-1], dp[0][1][M-1]+(dp_sum[0][M-1]>0)) << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing