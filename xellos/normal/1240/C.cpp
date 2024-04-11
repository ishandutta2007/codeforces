#include <bits/stdc++.h>
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

void DFS(int R, int par, auto & G, auto & dp, int K) {
	dp[R] = {0, 0};
	vector<cat> dif;
	dif.reserve(G[R].size());
	for(auto p : G[R]) if(p.ff != par) {
		DFS(p.ff, R, G, dp, K);
		dp[R].ff += dp[p.ff].ff;
		dp[R].ss += dp[p.ff].ff;
		dif.push_back(dp[p.ff].ss+p.ss-dp[p.ff].ff);
	}
	sort(begin(dif), end(dif));
	reverse(begin(dif), end(dif));
	for(int i = 0; i < min(K, (int)dif.size()); i++)
		if(dif[i] > 0) dp[R].ff += dif[i];
	for(int i = 0; i < min(K-1, (int)dif.size()); i++)
		if(dif[i] > 0) dp[R].ss += dif[i];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int N, K;
		cin >> N >> K;
		vector< vector< pair<int, int> > > G(N);
		for(int i = 0; i < N-1; i++) {
			int u, v;
			cat w;
			cin >> u >> v >> w;
			G[--u].push_back({--v, w});
			G[v].push_back({u, w});
		}
		vector< pair<cat, cat> > dp(N);
		DFS(0, 0, G, dp, K);
		cout << dp[0].ff << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing