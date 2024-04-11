#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 305;

int tl, tr, tc, n, m, k;
long long dp1[N][N], dp2[N][N], INF;

int main() {
	INF = 1ll << 61;
	cin >> n >> m >> k;
	for (int i = 0; i < N; ++i) {
	  for (int j = 0; j < N; ++j) {
	    dp1[i][j] = dp2[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; ++i) {
	  cin >> tl >> tr >> tc;
	  dp1[tl][tr] = min(dp1[tl][tr], (long long)tc);
	}
	for (int l = n - 1; l >= 1; --l) {
	  for (int i = 1; i + l <= n; ++i) {
	    tl = i; tr = i + l;
	    dp1[tl + 1][tr] = min(dp1[tl + 1][tr], dp1[tl][tr]);
	    dp1[tl][tr - 1] = min(dp1[tl][tr - 1], dp1[tl][tr]);
		}
	}
	for (int l = 1; l <= n - 1; ++l) {
	  for (int i = 1; i + l <= n; ++i) {
	    tl = i; tr = i + l;
			for (int k = tl; k <= tr; ++k) {
			  dp1[tl][tr] = min(dp1[tl][tr], dp1[tl][k] + dp1[k][tr]);
			}
	  	//cout << l << ' ' << i << ' ' << dp1[tl][tr] << endl;			
		}
	}
	dp2[1][0] = 0;
	for (int i = 1; i <= n; ++i) {
	  for (int j = 0; j <= k; ++j) {
	    if (dp2[i][j] == INF) continue;
	    dp2[i + 1][j] = min(dp2[i + 1][j], dp2[i][j]);
			for (int l = 1; j + l <= k; ++l) {
				dp2[i + l][j + l] = min(dp2[i + l][j + l], dp2[i][j] + dp1[i][i + l - 1]);
	    }
		}
	}
	if (dp2[n + 1][k] == INF) cout << -1 << endl; else cout << dp2[n + 1][k] << endl;
	return 0;
}