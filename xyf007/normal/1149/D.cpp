#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define per(i, a, b) for (int i = (a); i >= int(b); i--)
#define fir first
#define sec second
using namespace std;

typedef pair<int, int> P;

const int maxn = 70, maxm = 200;
int n, m, a, b, m1, m2, fa[maxn + 5], id[maxn + 5], sz[maxn + 5];
int cc, c[maxn + 5], dp[1 << 17][maxn + 5], ans[maxn + 5];
P e1[maxm + 5], e2[maxm + 5];
vector<P> G[maxn + 5];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void dijkstra(int dis[]) {
	priority_queue<P> H;
	rep(i, 1, n) {
		H.push({ -dis[i], i });
	}
	for (P p; !H.empty(); ) {
		static int u, v, w;
		p = H.top(), H.pop();
		u = p.sec;
		if (-p.fir != dis[u]) {
			continue;
		}
		for (P q: G[u]) {
			v = q.fir, w = q.sec;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				H.push({ -dis[v], v });
			}
		}
	}
}

inline void cmin(int &x, int y) {
	x > y ? x = y : 0;
}

int main() {
	scanf("%d %d %d %d", &n, &m, &a, &b);
	rep(i, 1, m) {
		static int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		if (w == a) {
			e1[++m1] = P(u, v);
		} else {
			e2[++m2] = P(u, v);
		}
	}
	rep(i, 1, n) {
		fa[i] = i;
	}
	rep(i, 1, m1) {
		fa[find(e1[i].fir)] = find(e1[i].sec);
	}
	rep(i, 1, n) {
		id[i] = -i, sz[find(i)]++;
	}
	rep(i, 1, n) if (find(i) == i && sz[i] >= 4) {
		id[i] = cc++;
	}
	rep(i, 1, n) {
		c[i] = id[find(i)];
	}
	rep(msk, 0, (1 << cc) - 1) rep(i, 1, n) {
		dp[msk][i] = 1e9;
	}
	rep(i, 1, m1) {
		int u = e1[i].fir, v = e1[i].sec;
		G[u].emplace_back(v, a);
		G[v].emplace_back(u, a);
	}
	rep(i, 1, m2) {
		int u = e2[i].fir, v = e2[i].sec;
		if (c[u] != c[v] && c[v] < 0) {
			G[u].emplace_back(v, b);
		}
		if (c[u] != c[v] && c[u] < 0) {
			G[v].emplace_back(u, b);
		}
	}
	dp[c[1] < 0 ? 0 : 1 << c[1]][1] = 0;
	rep(i, 1, n) {
		ans[i] = 1e9;
	}
	rep(msk, 0, (1 << cc) - 1) {
		dijkstra(dp[msk]);
		rep(i, 1, n) {
			cmin(ans[i], dp[msk][i]);
		}
		rep(i, 1, m2) {
			int u = e2[i].fir, v = e2[i].sec;
			if (c[u] != c[v] && c[v] >= 0 && ~msk >> c[v] & 1) {
				cmin(dp[msk | (1 << c[v])][v], dp[msk][u] + b);
			}
			if (c[u] != c[v] && c[u] >= 0 && ~msk >> c[u] & 1) {
				cmin(dp[msk | (1 << c[u])][u], dp[msk][v] + b);
			}
		}
	}
	rep(i, 1, n) {
		printf("%d%c", ans[i], " \n"[i == n]);
	}
	return 0;
}