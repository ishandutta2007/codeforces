#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define PB push_back
#define MP make_pair
#define F first
#define S second
typedef pair<int, int> pii;
const int maxn = 5010;
pii E[maxn];
VI G[maxn];
int n, m, stamp, cnt, top, ans;
int siz[maxn], sta[maxn], scc[maxn], c[maxn], dis[maxn], dfn[maxn], low[maxn];
bool ins[maxn];
void tarjan(int u) {
	dfn[u] = low[u] = ++stamp;
	sta[top++] = u; ins[u] = true; 
	for (int& v : G[u]) 
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (ins[v]) 
			low[u] = min(low[u], dfn[v]);
	if (dfn[u] == low[u]) {
		int v;
		do {
			v = sta[--top];
			ins[v] = false;
			scc[v] = cnt;
			++siz[cnt];
		} while (v != u);
		++cnt;
	}
}
queue<int> Q;
int BFS(int x, int color) {
	memset(dis, 0, sizeof dis);
	Q.push(x);
	dis[x] = 1;
	int minv = n;
	while (Q.size()) {
		int x = Q.front(); Q.pop();
		for (int& v : G[x]) 
			if (scc[v] == color) {
				if (dis[v]) minv = min(minv, dis[v] + dis[x] - 1);
				else {
					dis[v] = dis[x] + 1;
					Q.push(v);
				}
			}
	}
	return minv;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &E[i].F, &E[i].S);
		G[E[i].F].push_back(E[i].S);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) tarjan(i); 
	for (int i = 1; i <= m; ++i) {
		int u = E[i].F, v = E[i].S;
		if (scc[u] != scc[v]) ++c[scc[u]];
	}
	
	ans = n;
	for (int i = 0; i < cnt; ++i)
		if (!c[i] && siz[i] > 1) {
			int minv = n;
			for(int j = 1; j <= n; ++j)
				if (scc[j] == i) minv = min(minv, BFS(j, i));
			ans += 998 * minv + 1;
		}
	printf("%d\n", ans);
}