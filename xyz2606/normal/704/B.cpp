#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iostream>
#include<set>
#include<map>
#include<queue>
using namespace std;
const int N(5005);
int x[N], a[N], b[N], c[N], d[N];
long long dp[N][N];
long long inf((long long)1e9 * (long long)1e9);
int main() {
	int n, s, e;
	scanf("%d%d%d", &n, &s, &e);
	for(int i(1); i <= n; i++) {
		scanf("%d", &x[i]);
	}
	for(int i(1); i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i(1); i <= n; i++) {
		scanf("%d", &b[i]);
	}
	for(int i(1); i <= n; i++) {
		scanf("%d", &c[i]);
	}
	for(int i(1); i <= n; i++) {
		scanf("%d", &d[i]);
	}
	for(int i(1); i <= n; i++) {
		for(int j(0); j <= i; j++) {
			dp[i][j] = inf;
		}
	}
	if(s == 1) {
		dp[1][1] = d[1];
	}else if(e == 1) {
		dp[1][0] = b[1];
	}else {
		dp[1][1] = b[1] + d[1];
	}
	for(int i(1); i < n; i++) {
		for(int j(0); j <= i; j++) {
			int cnt(j);
			int cnt1(cnt - (s <= i) + (e <= i));
			if(cnt + cnt1 <= 0) {
				continue;
			}
			long long tmp((long long)(cnt + cnt1) * (x[i + 1] - x[i]));
			if(s == i + 1) {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + tmp + d[i + 1]);
				if(cnt1 >= 1) {
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + tmp + c[i + 1]);
				}
			}else if(e == i + 1) {
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + tmp + b[i + 1]);
				if(j >= 1) {
					dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + tmp + a[i + 1]);
				}
			}else {
				dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + tmp + b[i + 1] + d[i + 1]);
				if(j >= 1) {
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + tmp + a[i + 1] + d[i + 1]);
				}
				if(cnt1 >= 1) {
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + tmp + b[i + 1] + c[i + 1]);
				}
				if(j >= 1) {
					dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + tmp + a[i + 1] + c[i + 1]);
				}
			}
		}
	}
	cout << dp[n][0] << endl;
}