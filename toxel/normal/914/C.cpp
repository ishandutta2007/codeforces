#include<bits/stdc++.h>

const int N = 1010;
inline int lowbit(int n){return n & -n;}
const int moder = 1e9 + 7;

int dp[N];
int bitcnt[N];
char s[N];
int a[N];
int comb[N][N];

int main(){
	for (int i = 0; i < N; ++ i){
		comb[i][0] = 1;
		for (int j = 1; j <= i; ++ j){
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % moder;
		}
	}
	for (int i = 1; i < N; ++ i){
		bitcnt[i] = bitcnt[i ^ lowbit(i)] + 1;
		if (i == 1){
			dp[i] = 0;
			continue;
		}
		dp[i] = dp[bitcnt[i]] + 1;
	}
	int k;
	scanf("%s%d", s, &k);
	int n = strlen(s);
	for (int i = 0; i < n; ++ i){
		a[i] = s[i] - '0';
	}
	std::reverse(a, a + n);
	++ a[0];
	for (int i = 0; i < n; ++ i){
		if (a[i] >= 2){
			a[i] -= 2;
			++ a[i + 1];
		}
	}
	if (a[n]){
		++ n;
	}
	std::reverse(a, a + n);
	int now = 0;
	int ans = 0;
	for (int i = 0; i < n; ++ i){
		if (a[i]){
			for (int j = 1; j < N; ++ j){
				if (dp[j] == k - 1 && j >= now){
					ans = (ans + comb[n - i - 1][j - now]) % moder;
				}
			}
			++ now;
		}
	}
	if (k == 0){
		printf("1\n");
		return 0;
	}
	if (k == 1){
		-- ans;
		ans += ans < 0 ? moder : 0;
	}
	printf("%d\n", ans);
	return 0;
}