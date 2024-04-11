#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 1001000, mod = 1e9 + 7;
char s[MAXN]; int f[MAXN], pref[MAXN], pre1f[MAXN];
int a[MAXN][22], n;

int lg2[MAXN];
int qry (int l, int r) { int len = lg2[r - l + 1]; return max(a[l][len], a[r - (1 << len) + 1][len]); }
int calc (int x, int k) {
	int L = 1, R = x - 1, res = 1;
	while (L <= R) {
		int mid = (L + R) >> 1;
		if (qry(mid, x - 1) >= k) L = mid + 1;
		else R = mid - 1, res = mid;
	}
	return res;
}

int main () {
	scanf("%s", s + 1); n = strlen(s + 1);
	int i, j;
	for (i = 1, j = 0; i <= n; i++) {
		if (s[i] == '1') j = 0; else ++j;
		a[i][0] = j;
	}
	for (i = 1; i <= 20; i++) for (j = 1; j + (1 << i) - 1 <= n; j++)
		a[j][i] = max(a[j][i - 1], a[j + (1 << (i - 1))][i - 1]);
	lg2[0] = -1; for (i = 1; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
	f[0] = pref[0] = 1; int ans = 0, las = 0;
	for (i = 1; i <= n; i++) {
		if (s[i] == '0') {
			int tmp = calc(i, a[i][0]);
			f[i] = (pre1f[i - 1] - pre1f[tmp - 1]) % mod;
			if (a[i][0] == i) ++f[i];
		}
		else {
			f[i] = (pref[i - 1] - (las ? pref[las - 1] : 0)) % mod;
			las = i;
		}
		pref[i] = (pref[i - 1] + f[i]) % mod;
		pre1f[i] = (pre1f[i - 1] + (s[i] == '1') * f[i]) % mod;
	}
	for (i = n; i >= 1; i--) {
		if (s[i] == '1') break;
		int tmp = calc(i, a[i][0]) - 1;
		ans = (ans + pre1f[tmp]) % mod;
	}
	for (i = n, j = 1; i >= 1; i--) {
		if (s[i] == '1' || (s[i] == '0' && j)) ans = (ans + f[i]) % mod;
		j &= s[i] == '0';
	}
	printf("%d\n", (ans + mod) % mod);
	return 0;
}