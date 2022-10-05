#include<bits/stdc++.h>

const int N = 1010;
const int M = 60;
const int moder = 1e9 + 7;

std::bitset <M> set[N];

int dp[N];
char s[N][N];
int cnt[N];
int comb[N][N];

int main(){
	for (int i = 0; i < N; ++ i){
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++ j){
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % moder;
		}
	}
	dp[0] = 1;
	for (int i = 1; i < N; ++ i){
		for (int j = 1; j <= i; ++ j){
			dp[i] = (dp[i] + 1ll * dp[i - j] * comb[i - 1][j - 1]) % moder;
		}
	}
	int m, n;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; ++ i){
		scanf("%s", s[i]);
	}
	for (int i = 0; i < m; ++ i){
		for (int j = 0; j < n; ++ j){
			if (s[j][i] == '1'){
				set[i].set(j);
			}
		}
	}
	for (int i = 0; i < m; ++ i){
		for (int j = 0; j <= i; ++ j){
			if (set[i] == set[j]){
				++ cnt[j];
				break;
			}
		}
	}
	int ans = 1;
	for (int i = 0; i < m; ++ i){
		ans = 1ll * ans * dp[cnt[i]] % moder;
	}
	return printf("%d\n", ans), 0;
}