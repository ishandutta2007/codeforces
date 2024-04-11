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

#define pii pair<int, int>
#define fr first
#define se second

const int MAXN = 300300;
bool valid[MAXN], vis[MAXN], ban[MAXN]; int n, siz[MAXN];
vector <pii> E[MAXN];
vector <int> cur;

bool chk () { for (int i = 1; i < n; i++) if (!ban[i]) return 0; return 1; }

int fa[MAXN];
void pre (int x, int f) {
	vis[x] = 1; siz[x] = 1; cur.push_back(x);
	for (auto i: E[x]) if (i.fr != f && !ban[i.se]) {
		fa[i.fr] = i.se; pre(i.fr, x);
		siz[x] += siz[i.fr];
	}
}

int main () {
	n = read(); int i,j ;
	for (int p = 1, q = 1; max(p, q) <= n; swap(p, q), q += p) valid[q] = 1;
	if (!valid[n]) { puts("NO"); return 0; }
	for (i = 1; i < n; i++) {
		int u = read(), v = read();
		E[u].push_back(make_pair(v, i)); E[v].push_back(make_pair(u, i));
	}
	while (!chk()) {
		for (i = 1; i <= n; i++) vis[i] = 0;
		for (i = 1; i <= n; i++) if (!vis[i]) {
			cur.clear(); pre(i, 0); bool fin = 0;
			if (cur.size() == 1) continue;
			for (auto x: cur) if (valid[siz[x]] && valid[siz[i] - siz[x]]) {
				ban[fa[x]] = 1; fin = 1;
			}
			if (!fin) { puts("NO"); return 0; }
		}
	}
	puts("YES");
	return 0;
}