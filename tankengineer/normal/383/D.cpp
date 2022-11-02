#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000, S = 10000, SS = S >> 1, MOD = 1000000007;
int n, a[N], sum[N + 1];

int ans, f[2][S + 1], now[2 * S + 1], next[2 * S + 1];

void cal(int l, int r, int delta, int f[], int fs) {
	now[0] = 1;
	int nows = 0, nexts = 0;
	for (int i = l; i != r + delta; i += delta) {
		nexts += a[i];
		memset(next, 0, sizeof(int) * (2 * nexts + 1));
		for (int j = 0; j <= nows * 2; ++j) {
			if ((next[j] += now[j]) >= MOD) {
				next[j] -= MOD;
			}
			if ((next[j + 2 * a[i]] += now[j]) >= MOD) {
				next[j + 2 * a[i]] -= MOD;
			}
		}
		for (int j = 0; j <= nexts * 2; ++j) {
			now[j] = next[j];
			int p = j - nexts + fs;
			if (p >= 0 && p <= 2 * fs) {
				if ((f[p] += now[j]) >= MOD) {
					f[p] -= MOD;
				}
			}
		}
		nows = nexts;
	}
}

void solve(int l, int r) {
	if (l == r) {
		return;
	}
	int m = l + r >> 1;
	solve(l, m);
	solve(m + 1, r);
	int s = min(sum[m + 1] - sum[l], sum[r + 1] - sum[m + 1]);
	memset(f[0], 0, sizeof(int) * (2 * s + 1)); 
	cal(m, l, -1, f[0], s);
	memset(f[1], 0, sizeof(int) * (2 * s + 1));
	cal(m + 1, r, 1, f[1], s);
	for (int i = 0; i <= s * 2; ++i) {
		(ans += (long long)f[0][i] * f[1][s * 2 - i] % MOD) %= MOD;
	}
}

int main() {
	scanf("%d", &n);
	sum[0] = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		sum[i + 1] = sum[i] + a[i];
	}
	ans = 0;
	solve(0, n - 1);
	printf("%d\n", ans);
	return 0;
}