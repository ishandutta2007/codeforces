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

const int MAXN = 300300;
vector <int> E[MAXN], T[MAXN]; int n;

int dep[MAXN], fa[MAXN], siz[MAXN], wson[MAXN], top[MAXN], dfn[MAXN], idfn[MAXN], cnt, num[MAXN];
void clear () {
	for (int i = 1; i <= n; i++)
		dep[i] = fa[i] = siz[i] = wson[i] = top[i] = dfn[i] = idfn[i] = num[i] = 0, E[i].clear(), T[i].clear();
	cnt = 0;
}
void dfs1 (int x, int f) {
	dep[x] = dep[f] + 1, fa[x] = f, siz[x] = 1;
	for (auto i: E[x]) {
		dfs1(i, x); siz[x] += siz[i];
		if (siz[i] > siz[wson[x]]) wson[x] = i;
	}
}
void dfs2 (int x, int f) {
	dfn[x] = ++cnt; idfn[cnt] = x;
	if (wson[x]) top[wson[x]] = top[x], dfs2(wson[x], x);
	for (auto i: E[x]) if (i != wson[x]) {
		top[i] = i; dfs2(i, x);
	}
}

namespace BIT {
	int t[MAXN];
	inline int lowbit (int x) { return x & -x; }
	inline int sum (int x) { int ret = 0; while (x) ret += t[x], x -= lowbit(x); return ret; }
	inline void add (int x, int k) { while (x <= n) t[x] += k, x += lowbit(x); }
	inline int query (int x) { return sum(dfn[x] + siz[x] - 1) - sum(dfn[x] - 1); }
}

int ans = 0;
void solve (int x) {
	bool use = 0; int las = 0;
	if (!BIT::query(x)) {
		use = 1; int tmp = dep[x];
		for (int i = top[x]; i; i = top[fa[i]]) {
			// printf("(i = %d, num[i] = %d, %d %d)\n", i, num[i], dep[num[i]], tmp);
			if (num[i] && dep[num[i]] < tmp) {
				las = num[i];
				BIT::add(dfn[las], -1);
				num[i] = 0;
				break;
			}
			tmp = dep[i];
		}
		BIT::add(dfn[x], 1);
		num[top[x]] = x;
	}
	// printf("middle!! %d\n", x);
	if (!T[x].size()) { ans = max(ans, BIT::sum(n)); }
	for (auto i: T[x]) solve(i);
	if (use) {
		num[top[x]] = 0; BIT::add(dfn[x], -1);
		if (las) {
			BIT::add(dfn[las], 1); 
			num[top[las]] = las;
		}
	}
}

int main () {
	// freopen("test.out", "w", stdout);
	int Tid = read();
	while (Tid--) {
		n = read(); int i, j; ans = cnt = 0;
		for (i = 2; i <= n; i++) j = read(), T[j].push_back(i);
		for (i = 2; i <= n; i++) j = read(), E[j].push_back(i);
		dfs1(1, 0); top[1] = 1; dfs2(1, 0);
		// for (i = 1; i <= n; i++) printf("%d: fa = %d, dep = %d, dfn= %d,siz= %d,wson= %d,top= %d\n", i, fa[i], dep[i], dfn[i], siz[i], wson[i], top[i]);
		for (i = 1; i <= n; i++) BIT::t[i] = 0;
		solve(1); cout << ans << endl;
		clear();
	}
	return 0;
}