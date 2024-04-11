#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 3000;
int dp[N + 1][2], a[N], b[N], c[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", b + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", c + i);
	}
	if (n == 1) {
		printf("%d\n", a[0]);
		return 0;
	}
	dp[1][0] = a[0];
	dp[1][1] = b[0];	
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) {
				int val = 0;
				if (1 - j + k == 0) {
					val = a[i];
				} else if (1 - j + k == 1) {
					val = b[i];
				} else if (1 - j + k == 2) {
					val = c[i];
				}
				dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + val);
			}
		}
	}
	int ans = max(dp[n - 1][0] + b[n - 1], dp[n - 1][1] + a[n - 1]);
	printf("%d\n", ans);	
	return 0;
}