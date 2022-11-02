#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 150000;
int n, m, d;
long long dp[N];

int qhead, qtail;
long long qval[N + 1], qpos[N + 1];

int main() {
	scanf("%d%d%d", &n, &m, &d);
	int now = 0;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < m; ++i) {
		int pos, val, t;
		scanf("%d%d%d", &pos, &val, &t);
		--pos;
		long long l = (long long)d * (t - now);
		qhead = qtail = 0;
		for (int i = 0; i < n; ++i) {
			while (qhead < qtail && qval[qtail] < dp[i]) {
				--qtail;
			}
			++qtail;
			qval[qtail] = dp[i];
			qpos[qtail] = i;
			while (qhead < qtail && qpos[qhead + 1] + l < i) {
				++qhead;
			}
			dp[i] = max(dp[i], qval[qhead + 1]);
		}
		qhead = qtail = 0;
		for (int i = n - 1; i >= 0; --i) {
			while (qhead < qtail && qval[qtail] < dp[i]) {
				--qtail;
			}
			++qtail;
			qval[qtail] = dp[i];
			qpos[qtail] = i;
			while (qhead < qtail && qpos[qhead + 1] - l > i) {
				++qhead;
			}
			dp[i] = max(dp[i], qval[qhead + 1]);
		}
		now = t;
		for (int i = 0; i < n; ++i) {
			dp[i] += val - abs(i - pos);
		}
	}
	long long ans = -(1ll << 62);
	for (int i = 0; i < n; ++i) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}