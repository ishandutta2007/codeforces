#include<bits/stdc++.h>

const int N = 20;
typedef long long ll;

ll dp[N << 1][N];
char ans[N << 1][N], s[N << 1];
ll power[N];

int main(){
	power[0] = 1;
	for (int i = 1; i < N; ++ i){
		power[i] = power[i - 1] * 10;
	}
	int n;
	scanf("%d%s", &n, s);
	for (int i = n << 1; i >= 0; -- i){
		for (int j = 0; j <= std::min(n, 2 * n - i); ++ j){
			int k = 2 * n - i - j;
			if (k > n) continue;
			if (j < n){
				ll x = dp[i][j] + (s[i - 1] - '0') * power[j];
				if (x >= dp[i - 1][j + 1]){
					dp[i - 1][j + 1] = x;
					ans[i - 1][j + 1] = 'H';
				}
			}
			if (k < n){
				ll x = dp[i][j] + (s[i - 1] - '0') * power[k];
				if (x >= dp[i - 1][j]){
					dp[i - 1][j] = x;
					ans[i - 1][j] = 'M';
				}
			}
		}
	}
	int now = n;
	for (int i = 0; i < n << 1; ++ i){
		putchar(ans[i][now]);
		now -= ans[i][now] == 'H';
	}
	putchar('\n');
	return 0;
}