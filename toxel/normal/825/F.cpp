#include<bits/stdc++.h>

const int N = 8010;

char s[N];
int dp[N], fail[N][N], pre[N];

void makeFail(char *p, int *fail){
    int m = strlen(p);
    fail[0] = -1;
    for(int i = 1, j = -1; i <= m; ++ i){
        while(j >= 0 && p[j] != p[i - 1]) j = fail[j];
        fail[i] = ++ j;
    }
}

int calc(int n){
	int ret = 0;
	while (n){
		n /= 10;
		++ ret;
	}
	return ret;
}

int solve(int left, int right){
	int len = right - left + 1, x = fail[left][len];
	if (x < len + 1 >> 1 || len % (len - x)){
		return len + 1;
	}
	return len - x + calc(len / (len - x));
}

int main(){
	for (int i = 1; i < N; ++ i){
		pre[i] = calc(i);
	}
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; ++ i){
		makeFail(s + i, fail[i]);
	}
	memset(dp, 0x7f, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= len; ++ i){
		for (int j = 1; j <= i; ++ j){
			dp[i] = std::min(dp[i], dp[i - j] + solve(i - j, i - 1));
		}
	}
	return printf("%d\n", dp[len]), 0;
}