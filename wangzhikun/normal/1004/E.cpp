#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Edge;

#define MAXN 100001
#define MAXD 17
#define INF 0x3f3f3f3f

int n, s, p[MAXN], f[MAXN], tot, que[MAXN], dis[MAXN], pre[MAXN], suf[MAXN], Log[MAXN], st[MAXD][MAXN];
vector<Edge> e[MAXN];
bool inq[MAXN];

int rmq(int l, int r) {
	if(l > r)
		return 0;
	int d = Log[r - l + 1];
	return max(st[d][l], st[d][r - (1 << d) + 1]);
}

void dfs(int u, int fa) {
	f[u] = 0;
	for(auto it : e[u]) {
		int v = it.first, w = it.second;
		if(v == fa || inq[v])
			continue;
		dfs(v, u);
		if(f[u] < f[v] + w) {
			f[u] = f[v] + w;
			p[u] = v;
		}
	}
}

int main() {
	Log[1] = 0;
	for(int i = 2; i < MAXN; ++i)
		Log[i] = Log[i >> 1] + 1;
	scanf("%d%d", &n, &s);
	for(int i = 1; i < n; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].push_back(make_pair(v, w));
		e[v].push_back(make_pair(u, w));
	}
	dfs(1, -1);
	for(que[tot++] = 1; f[que[0]]; que[0] = p[que[0]]);
	dfs(que[0], -1);
	inq[que[0]] = 1;
	dis[0] = f[que[0]];
	for(int u = que[0]; f[u]; u = p[u]) {
		inq[p[u]] = 1;
		dis[tot] = f[p[u]];
		que[tot++] = p[u];
	}
	for(int i = 0; i < tot; ++i) {
		dfs(que[i], -1);
		pre[i] = suf[i] = st[0][i] = f[que[i]];
	}
	for(int i = 1; i < tot; ++i)
		if(pre[i] < pre[i - 1] + dis[i - 1] - dis[i])
			pre[i] = pre[i - 1] + dis[i - 1] - dis[i];
	for(int i = tot - 2; i >= 0; --i)
		if(suf[i] < suf[i + 1] + dis[i] - dis[i + 1])
			suf[i] = suf[i + 1] + dis[i] - dis[i + 1];
	for(int d = 1; d < MAXD; ++d)
		for(int i = 0; i < tot && i + (1 << d - 1) < tot; ++i)
			st[d][i] = max(st[d - 1][i], st[d - 1][i + (1 << d - 1)]);
	int ans = INF;
	for(int i = 0, j = 0; i < tot; ++i)
		for(j = j < i ? i : j; j < tot && j - i + 1 <= s; ++j) {
			int tmp = max(max(pre[i], suf[j]), rmq(i + 1, j - 1));
			if(ans > tmp)
				ans = tmp;
			else
				break;
		}
	printf("%d\n", ans);
	return 0;
}