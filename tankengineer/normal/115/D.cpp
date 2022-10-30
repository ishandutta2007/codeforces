#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2005, MOD = 1000003;
int n, dp[N][N];
char s[N];

bool isSymbol(char ch) {
	return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

bool isDigit(char ch) {
	return ch >= '0' && ch <= '9';
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	if (isSymbol(s[n - 1])) {
		printf("0\n");
		return 0;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		bool oni = ((i == 0 || isSymbol(s[i - 1])) && isSymbol(s[i]));
		if (oni && s[i] != '+' && s[i] != '-') {
			printf("0\n");
			return 0;
		}
		if (((i == 0 || isSymbol(s[i - 1])) && isDigit(s[i])) || oni) {
			s[cnt++] = s[i];
		}
	}
	s[cnt] = 0;
	n = cnt;
	int ans = 0;
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (dp[i][j] == 0) {
				continue;
			}
			(dp[i][j + 1] += dp[i][j]) %= MOD;
			if (isDigit(s[i])) {
				if (j) {
					(dp[i + 1][j - 1] += dp[i][j]) %= MOD;
				} else {
					if (i == n - 1) {
						(ans += dp[i][j]) %= MOD;
					}
				}
			} else {
				(dp[i + 1][j] += dp[i][j]) %= MOD;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}