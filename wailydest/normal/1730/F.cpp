#include <cstdio>
#include <algorithm>
#include <cstring>

const int INF = 0x3f3f3f3f;

const int N = 5005;
const int K = 10;
int n, k, d[N][K][1 << K], p[N], inv[N];

void mnm(int &a, int b) {
	a = std::min(a, b);
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", p + i);
		--p[i];
		inv[p[i]] = i;
	}
	k = std::min(k, n - 1);
	memset(d, 0x3f, sizeof d);
	for (int i = 0; i <= k; ++i) d[0][i][(1 << i) - 1] = 0;
	for (int i = 0; i + 1 < n; ++i) for (int j = 0; j <= k; ++j) for (int mask = 0; mask < 1 << k; ++mask) {
		int mx = i + j, cur = d[i][j][mask];
		if (cur < INF) {
			for (int x = 0; x < k; ++x) if (mask >> x & 1) {
				int put = mx - 1 - x, next = 0;
				for (int l = std::max(0, put - k); l < put; ++l) 
					if (l < mx - k || mask >> (mx - l - 1) & 1 ^ 1) next += inv[put] < inv[l];
				mnm(d[i + 1][j - 1][mask ^ 1 << x], cur + next);
			}
			int lim = mask ? mx - 1 - (31 - __builtin_clz(mask)) : mx + 1;
			lim += k;
			lim = std::min(lim, n - 1);
			for (int put = mx + 1; put <= lim; ++put) {
				int mask1 = mask << (put - mx) | (1 << put - mx - 1) - 1, next = 0;
				for (int l = std::max(0, put - k); l < put; ++l) 
					if (mask1 >> put - l - 1 & 1 ^ 1) next += inv[put] < inv[l];
				mnm(d[i + 1][put - (i + 1)][mask1], cur + next);
			}
		}
	}
	int ans = d[n - 1][0][0];
	for (int i = 0; i < n; ++i) for (int j = 0; j + k < i; ++j) ans += inv[i] < inv[j];
	printf("%d\n", ans);
	return 0;
}