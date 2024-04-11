#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

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
#define	ll long long

const int MAXN = 606;
const ll inf = 1e18;

vector <pii> E[MAXN]; int n, m;
ll dis[MAXN];

struct node { int id; ll dis; node (int _i = 0, ll _d = 0) { id = _i, dis = _d; } bool operator < (const node &tmp) const { return dis > tmp.dis; } };
priority_queue <node> pq;

ll tmp[MAXN]; bool vis[MAXN];
void dij (int s) {
	int i, j;
	for (i = 0; i < n; i++) dis[i] = inf, vis[i] = 0;
	dis[s] = 0, pq.push(node(s, 0));
	while (!pq.empty()) {
		int x = pq.top().id; pq.pop();
		if (vis[x]) continue;
		vis[x] = 1;
		for (i = 0; i < n; i++) tmp[i] = inf;
		for (auto v: E[x])
			tmp[(v.fr + dis[x]) % n] = min(tmp[(v.fr + dis[x]) % n], dis[x] + v.se);
		for (i = 1; i < n; i++) tmp[i] = min(tmp[i], tmp[i - 1] + 1);
		tmp[0] = min(tmp[0], tmp[n - 1] + 1);
		for (i = 1; i < n; i++) tmp[i] = min(tmp[i], tmp[i - 1] + 1);
		for (i = 0; i < n; i++) if (dis[i] > tmp[i]) dis[i] = tmp[i], pq.push(node(i, dis[i]));
	}
}

int main () {
	n = read(), m = read(); int i, j;
	for (i = 1; i <= m; i++) {
		int u = read(), v = read(), w = read();
		E[u].push_back(make_pair(v, w));
	}
	for (i = 0; i < n; i++) {
		dij(i);
		for (j = 0; j < n; j++) printf("%lld ", dis[j]);
		puts("");
	}
	return 0;
}