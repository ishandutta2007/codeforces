#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <bitset>
#include <cassert>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 220;
using LL = __int128;
using pii = pair <int, int>;
using pLL = pair <LL, int>;
#define fr first
#define se second

string out (LL x) { string ret; if (x >= 10) ret += out(x / 10); ret += char(x % 10 + '0'); return ret; }
auto ts (LL x) { return out(x).c_str(); }

int n; vector <int> E[MAXN], id[MAXN];
int ans[MAXN] = {-1};
pii e[MAXN];

LL dfs (int x, int fa) {
	LL ret = 0; vector <pLL> sav, cur;
	for (int it = 0; it < E[x].size(); it++) if (E[x][it] != fa) {
		LL tmp = dfs(E[x][it], x);
		sav.push_back({tmp, id[x][it]});
	}
	for (int i = n; i >= 0; i--) {
		cur = sav; bool fail = 0;
		ret ^= (LL(1) << i) - 1;
		for (int j = n; j >= 0; j--) {
			int cnt = 0; LL mx = 0;
			for (auto k: cur) {
				cnt += (k.fr >> j) & 1;
				mx = max(mx, ((LL(1) << (j + 1)) - 1) & k.fr);
			}
			if (cnt >= 2 - (!((ret >> j) & 1))) { fail = 1; break; }
			if (!cnt && ((ret >> j) & 1)) {
				for (auto &k: cur) if ((((LL(1) << (j + 1)) - 1) & k.fr) == mx && k.se) {
					k.fr = 0, k.se = 0;
					break;
				}
			}
		}
		for (auto k: cur) if (k.se) fail = 1;
		if (fail) ret |= LL(1) << i;
		ret ^= (LL(1) << i) - 1;
	}
	for (int j = n; j >= 0; j--) {
		int cnt = 0; LL mx = 0;
		for (auto k: sav) {
			cnt += (k.fr >> j) & 1;
			mx = max(mx, ((LL(1) << (j + 1)) - 1) & k.fr);
		}
		if (!cnt && ((ret >> j) & 1)) {
			for (auto &k: sav) if ((((LL(1) << (j + 1)) - 1) & k.fr) == mx && k.se) {
				k.fr = 0, ans[k.se] = ans[k.se ^ 1] = j; k.se = 0;
				break;
			}
		}
	}
	return ret;
}

bool vis[MAXN];
int findmax(int x, int fa) {
	int ret = 0;
	for (int i = 0; i < E[x].size(); i++) if (E[x][i] != fa && !vis[id[x][i]]) {
		if (ans[id[x][i]] > ans[ret]) ret = id[x][i];
		int tmp = findmax(E[x][i], x);
		if (ans[tmp] > ans[ret]) ret = tmp;
	}
	return ret;
}
inline int query (int u, int v) { printf("? %d %d\n", u, v); fflush(stdout); return read(); }

int main() {
	n = read(); int i, j;
	for (i = 1, j = 2; i < n; i++) {
		int u = read(), v = read();
		e[j] = {u, v}; E[u].push_back(v); id[u].push_back(j++);
		e[j] = {v, u}; E[v].push_back(u); id[v].push_back(j++);
	}
	dfs(1, 0);
	// for (i = 2; i < j; i++) printf("%d %d | %d\n", e[i].fr, e[i].se, ans[i]);
	int now = 1;
	while (1) {
		int tmp = findmax(now, 0);
		if (!tmp) break;
		vis[tmp] = vis[tmp ^ 1] = 1;
		now = query(e[tmp].fr, e[tmp].se);
	}
	printf("! %d\n", now);
	return 0;
}