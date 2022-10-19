#include <bits/stdc++.h>
using namespace std;

const int N = 14;

int dp[(1 << N) + 5][105], n, m, W[N], S[(1 << N) + 5], q, who[(1 << N) + 5];

char s[N];

main(void) {
	cin >> n >> m >> q;
	for(int i = 0; i < n; ++ i) cin >> W[i];
	for(int i = 0; i < (1 << n); ++ i) {
		for(int j = 0; j < n; ++ j) if(!((1 << j) & i)) S[i] += W[j];
	}
	for(int i = 1; i <= m; ++ i) {
		scanf("%s", s);
		int now = 0;
		for(int j = 0; j < n; ++ j) {
			now += (1 << j) * (s[j] - '0');
		}
		++ who[now];
	}
	for(int i = 0; i < (1 << n); ++ i) {
		for(int j = 0; j < (1 << n); ++ j) if(S[i ^ j] <= 100) dp[i][S[i ^ j]] += who[j];
		for(int j = 1; j <= 100; ++ j) dp[i][j] += dp[i][j - 1];
	}
	for(int i = 1; i <= q; ++ i) {
		scanf("%s", s);
		int t;
		scanf("%d", &t);
		int now = 0;
		for(int j = 0; j < n; ++ j) now += (1 << j) * (s[j] - '0');
		printf("%d\n", dp[now][t]);
	}
}