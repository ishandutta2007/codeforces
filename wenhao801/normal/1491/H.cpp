#pragma GCC optimize(3)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

#define ll long long
const int MAXN = 100100, B = 400;
int n, q, cnt[MAXN], o[MAXN];

ll t[MAXN], f[MAXN];
inline int lowbit (int x) { return x & -x; }
inline ll ask (int x) { ll ret = 0; while (x) ret += t[x], x -= lowbit(x); return max(ret, 0ll); }
inline void add (int x, int k) { while (x <= n) t[x] += k, x += lowbit(x); }
inline void modify (int l, int r, int k) { add(l, k), add(r + 1, -k); }

int id[MAXN], L[MAXN], R[MAXN]; ll tag[MAXN];
void rebuild (int k) {
	int i, j; tag[k] = 0;
	for (i = L[k]; i <= R[k]; i++) {
		f[i] = ask(i);
		if (id[f[i]] == k) f[i] = f[f[i]];
	}
}
ll getf (int x) { return max(0ll, f[x] + tag[id[x]]); }

bool vis[MAXN];
vector <int> v1, v2;

int main () {
	n = read(), q = read(); int i, j;
	for (i = 2; i <= n; i++) o[i] = read(), add(i, o[i] - o[i - 1]);
	for (i = 1; i <= n; i++) id[i] = (i - 1) / B + 1;
	for (i = 1; i <= id[n]; i++) L[i] = (i - 1) * B + 1, R[i] = min(n, i * B);
	for (i = 1; i <= n; i++) {
		f[i] = o[i];
		if (id[f[i]] == id[i]) f[i] = f[f[i]];
	}
	while (q--) {
		int op = read();
		if (op == 1) {
			int l = read(), r = read(), x = read();
			modify(l, r, -x);
			if (id[l] == id[r]) { rebuild(id[l]); continue; }
			rebuild(id[l]), rebuild(id[r]);
			for (i = id[l] + 1; i <= id[r] - 1; i++) {
				if (cnt[i] >= B) tag[i] -= x;
				else cnt[i] += x, rebuild(i);
			}
		}
		else {
			int u = read(), v = read();
			for (i = u; i; i = getf(i)) vis[i] = 1, v1.push_back(i);
			v1.push_back(0);
			for (i = v; i; i = getf(i)) { v2.push_back(i); if (vis[i]) break; }
			if (!vis[v2.back()]) v2.push_back(0);
			if (i == v || v2.back() == v1[0]) {
				if (i == v) printf("%d\n", max(v, 1)); else printf("%d\n", max(u, 1));
				for (i = u; i; i = getf(i)) vis[i] = 0;
				v1.clear(), v2.clear(); continue;
			}
			for (j = 0; v1[j] != i; j++);
			int x = v1[j - 1], y = v2[v2.size() - 2]; v1.clear(), v2.clear();
			for (j = u; j; j = getf(j)) vis[j] = 0;
			vis[i] = 1;
			for (j = x; j != i; j = ask(j)) vis[j] = 1;
			for (j = y; !vis[j]; j = ask(j));
			printf("%d\n", max(j, 1));
			vis[i] = 0; for (j = x; j != i; j = ask(j)) vis[j] = 0;
			v1.clear(), v2.clear();
		}
	}
	return 0;
}