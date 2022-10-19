#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;

int dp[N][N][2], n, m, x, y, A[N];

int calc(int x, int y) {
	int L, R;
	L = min(A[x - 2] - 1, A[x - 1]), R = A[x + 1];
	if(!y) L = A[x - 1];
	return max(0, L - A[x] + 1) + max(0, R - A[x] + 1);
}

vector <int> cxt;

main(void) {
	cin >> n;
	for(int i = 1; i <= n; ++ i) scanf("%d", &A[i]);
	memset(dp, 127, sizeof(dp));
	dp[1][0][0] = 0;
	int MAX = (n + 1) / 2;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 0; j <= MAX; ++ j) {
			for(int k = 0; k < 2; ++ k) if(dp[i][j][k] <= 1e9){
				if(i <= n) {
					dp[min(i + 2, n + 1)][j + 1][1] = min(dp[min(i + 2, n + 1)][j + 1][1], calc(i, k) + dp[i][j][k]);
				}
				dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k]);
			}
		}
	}
	int ans = 2e9;
	for(int i = MAX; i >= 1; -- i) {
		ans = min(ans, min(dp[n + 1][i][0], dp[n + 1][i][1]));
		cxt.push_back(ans);
	}
	reverse(cxt.begin(), cxt.end());
	for(int i = 0; i < (int) cxt.size(); ++ i) cout << cxt[i] << " ";
	puts("");
}