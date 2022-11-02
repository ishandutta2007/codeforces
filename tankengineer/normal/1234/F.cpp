#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int C = 20, L = 1000005;

int n;

char s[L];

int dp[1 << C];

int main() {
	scanf("%s", s);
	n = strlen(s);
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; ++i) {
		int mask = 0;
		for (int j = 0; i + j < n; ++j) {
			int c = s[i + j] - 'a';
			if ((mask >> c) & 1) {
				break;
			} else {
				mask |= (1 << c);
				dp[mask] = j + 1;
			}
		}
	}
	for (int i = 0; i < (1 << C); ++i) {
		for (int j = 0; j < C; ++j) {
			dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i]);
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << C); ++i) {
		ans = max(ans, dp[i] + dp[((1 << C) - 1) ^ i]);
	}
	printf("%d\n", ans);
	return 0;
}