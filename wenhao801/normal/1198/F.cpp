#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <random>
#include <chrono>
#include <vector>

using namespace std;

mt19937 RND (chrono::steady_clock::now().time_since_epoch().count());
// mt19937 RND(12345);

int rnd (int l, int r) { return RND() % (r - l + 1) + l; }

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

#define pii pair <short, short>
#define fr first
#define se second
#define size(v) (int(v.size()))
const int MAXN = 100100;
int n, a[MAXN]; vector <int> pru, prv;

int cntu[22], cntv[22];
pii fr[180][1 << 9][1 << 9];

bool solve (int u, int v) {
	int i, j, k;
	pru.clear(), prv.clear();
	for (j = a[u], i = 2; i * i <= j; i++) if (j % i == 0) {
		while (j % i == 0) j /= i;
		pru.push_back(i); cntu[size(pru)] = 0;
	}
	if (j != 1) pru.push_back(j);
	for (j = a[v], i = 2; i * i <= j; i++) if (j % i == 0) {
		while (j % i == 0) j /= i;
		prv.push_back(i); cntv[size(prv)] = 0;
	}
	if (j != 1) prv.push_back(j);
	vector <int> cur = {0};
	for (j = 0; j < (1 << size(pru)); j++) for (k = 0; k < (1 << size(prv)); k++) fr[0][j][k].fr = -1;
	fr[0][0][0] = make_pair(0, 0);
	for (i = 1; i <= n; i++) {
		if (i == u || i == v) continue;
		int su = 0, sv = 0, mn = 1e9;
		for (j = 0; j < size(pru); j++) if (a[i] % pru[j]) su |= 1 << j, mn = min(mn, cntu[j]);
		for (j = 0; j < size(prv); j++) if (a[i] % prv[j]) sv |= 1 << j, mn = min(mn, cntv[j]);
		if (mn >= 9) continue;
		for (j = 0; j < (1 << size(pru)); j++) for (k = 0; k < (1 << size(prv)); k++) fr[size(cur)][j][k].fr = -1;
		for (j = 0; j < size(pru); j++) if (a[i] % pru[j]) ++cntu[j];
		for (j = 0; j < size(prv); j++) if (a[i] % prv[j]) ++cntv[j];
		// printf("i = %d: %d %d\n", i, su, sv);
		for (j = 0; j < (1 << size(pru)); j++) for (k = 0; k < (1 << size(prv)); k++) if (fr[size(cur) - 1][j][k].fr != -1)
			fr[size(cur)][j][k] = fr[size(cur)][j | su][k] = fr[size(cur)][j][k | sv] = make_pair(j, k); //, printf("att %d %d\n", j, k);
		// for (j = 0; j < (1 << size(pru)); j++) for (k = 0; k < (1 << size(prv)); k++) if (fr[size(cur)][j][k].fr != -1)
		// 	printf("%d %d | %d %d\n", j, k, fr[size(cur)][j][k].fr, fr[size(cur)][j][k].se);
		cur.push_back(i);
		if (fr[size(cur) - 1][(1 << size(pru)) - 1][(1 << size(prv)) - 1].fr != -1) {
			// printf("! %d %d\n", u, v);
			puts("YES"); vector <int> ans(n + 1);
			ans[u] = 1, ans[v] = 2;
			pii now = make_pair((1 << size(pru)) - 1, (1 << size(prv)) - 1);
			for (i = size(cur) - 1; i >= 1; i--) {
				pii nex = fr[i][now.fr][now.se];
				ans[cur[i]] = (nex.se != now.se) + 1;
				now = fr[i][now.fr][now.se];
			}
			for (i = 1; i <= n; i++) printf("%d%c", max(1, ans[i]), " \n"[i == n]);
			return 1;
		}
	}
	return 0;
}

int main () {
	n = read(); int i, j = 0, k = 0;
	for (i = 1; i <= n; i++) a[i] = read(), j = __gcd(a[i], j), k += a[i] == 1;
	if (k >= 2) {
		k = 2; puts("YES");
		for (i = 1; i <= n; i++) {
			printf("%d ", k);
			if (k == 2 && a[i] == 1) --k;
		}
		return 0;
	}
	if (j != 1) { puts("NO"); return 0; }
	int T = 10;
	while (T--) {
		int u = rnd(1, n), v = u;
		while (u == v) v = rnd(1, n);
		// printf("try %d %d\n", u, v);
		if (solve(u, v)) return 0;
	}
	puts("NO");
	return 0;
}