#include<bits/stdc++.h>

const int N = 60;
const int INF = 0x7f7f7f7f;

char s[N][N], str[N * N];

int calc(char *s1, char *s2){
	int len1 = strlen(s1), len2 = strlen(s2), ret = 0;
	for (int i = 0; i < len1 && ret < len2; ++ i){
		if (s1[i] == s2[ret]){
			++ ret;
		}
	}
	return ret;
}

int n;
int dp[N * N];

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i){
		scanf("%s", &s[i]);
	}
	scanf("%s", str);
	int len = strlen(str);
	memset(dp, 0x7f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < len; ++ i){
		int max = 0;
		for (int j = 0; j < n; ++ j){
			max = std::max(max, calc(s[j], str + i));
		}
		for (int j = 1; j <= max; ++ j){
			dp[i + j] = std::min(dp[i + j], dp[i] + 1);
		}
	}
	return printf("%d\n", dp[len] == INF ? -1 : dp[len]), 0;
}