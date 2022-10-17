#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

#define int long long

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 300300, inf = 2e9;
int n, s1, s2, a[MAXN], b[MAXN], id[MAXN];
int cost[MAXN], rem[MAXN], tag[MAXN << 2];

void hit (int l, int r, int k, int L, int R, int x) {
	if (l <= L && R <= r) { tag[x] = max(tag[x], k); return; }
	int mid = (L + R) >> 1; 
	if (l <= mid) hit(l, r, k, L, mid, x << 1);
	if (mid < r) hit(l, r, k, mid + 1, R, x << 1 | 1);
}
void claim (int l, int r, int x, int p) {
	if (l == r) { rem[l] = max(rem[l], p); return; }
	int mid = (l + r) >> 1; p = max(p, tag[x]);
	claim(l, mid, x << 1, p); claim(mid + 1, r, x << 1 | 1, p);
}
int o[MAXN]; map <int, int> fir;
bool cmp (int x, int y) { return a[x] < a[y]; }
signed main () {
	n = read(); int i, j;
	s1 = read(), s2 = read();
	for (i = 1; i <= n; i++) a[i] = o[i] = read(), id[i] = i, cost[i] = inf;
	sort(id + 1, id + n + 1, cmp);
	sort(a + 1, a + n + 1); a[n + 1] = inf;
	for (i = 1; i < n; i++) {
		int lim = s1 / i + (s1 % i == 0 ? 0 : 1);
		int pos = lower_bound(a + 1, a + n + 1 + 1, lim) - a;
		if (pos + i - 1 <= n) {
			// printf("%lld %lld\n", i, pos);
			cost[pos] = min(cost[pos], i);
			// printf("hit %lld %lld with %lld\n", pos, pos + i - 1, n - pos + 1 - i);
			hit(pos, n, n - pos + 1 - i, 1, n, 1);
		}
	}
	rem[n] = 1 - cost[n];
	for (i = n - 1; i >= 1; i--) rem[i] = max(rem[i + 1] + 1, n - i + 1 - cost[i]);
	claim(1, n, 1, 0);
	for (i = 1; i <= n; i++) rem[i] = min(rem[i], n - i + 1);
	// for (i = 1; i <= n; i++) cout << rem[i] << ' '; cout << endl;
	for (i = 1; i < n; i++) {
		int lim = s2 / i + (s2 % i == 0 ? 0 : 1);
		int pos = lower_bound(a + 1, a + n + 1 + 1, lim) - a;
		// printf("%lld %lld\n", pos, i);
		if (rem[pos] >= i) {
			puts("Yes");
			int banl = pos, banr = pos + i - 1, top = 0;
			for (i = 1; i < banl; i++) b[++top] = a[i];
			int qmid = top;
			for (i = banr + 1; i <= n; i++) b[++top] = a[i];
			b[top + 1] = inf;
			for (i = 1; i <= top; i++) {
				int lim = s1 / i + (s1 % i == 0 ? 0 : 1);
				int pos = lower_bound(b + 1, b + top + 1 + 1, lim) - b;
				if (pos + i - 1 <= top) {
					printf("%lld %lld\n", i, banr - banl + 1);
					for (j = pos; j <= pos + i - 1; j++) printf("%lld ", id[j > qmid ? (j + banr - banl + 1) : j]);
					puts("");
					for (j = banl; j <= banr; j++) cout << id[j] << ' '; 
					cout << endl;
					return 0;
				}
			}
		}
	}
	puts("No");
	return 0;
}