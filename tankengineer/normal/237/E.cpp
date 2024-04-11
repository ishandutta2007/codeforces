#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 105, L = 105;

int n, lt, cnt[26], cnti[N][26], a[N];
char t[L], s[N][L];

const int NN = 1 + 26 + N + 1, M = (26 + 27 * N) << 1;
int st, ed, top, to[M], head[NN], next[M], l[M], c[M];

void addEdge(int u, int v, int tc, int tl) {
	to[top] = v, next[top] = head[u], head[u] = top, l[top] = tl, c[top] = tc, ++top;
	to[top] = u, next[top] = head[v], head[v] = top, l[top] = -tl, c[top] = 0, ++top;
}

void buildGraph() {
	memset(head, -1, sizeof(head));
	st = 0, ed = st + 26 + n + 1;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i]) {
			addEdge(st, 1 + i, cnt[i], 0);
		}
	}
	for (int i = 0; i < n; ++i) {
		addEdge(1 + 26 + i, ed, a[i], i + 1);
		for (int j = 0; j < 26; ++j) {
			if (cnti[i][j]) {
				addEdge(1 + j, 1 + 26 + i, cnti[i][j], 0);
			}
		}
	}
}

const int INF = 200000000;

int dis[NN], fa[NN];
bool inque[NN];

int SPFA(int &cost) {
	int n = ed + 1;
	for (int i = 0; i < n; ++i) {
		dis[i] = INF;
		inque[i] = false;
	}
	queue<int> q;
	dis[st] = 0;
	inque[st] = true;
	q.push(st);
	while (q.size()) {
		int u = q.front();
		q.pop();
		inque[u] = false;
		for (int j = head[u]; ~j; j = next[j]) {
			int v = to[j];
			if (c[j] && dis[v] > dis[u] + l[j]) {
				dis[v] = dis[u] + l[j];
				fa[v] = j;
				if (!inque[v]) {
					inque[v] = true;
					q.push(v);
				}
			}
		}
	}
	if (dis[ed] == INF) {
		return 0;
	}
	int ret = INF, p = ed;
	while (p != st) {
		ret = min(ret, c[fa[p]]);
		p = to[fa[p] ^ 1];
	}
	p = ed;
	while (p != st) {
		c[fa[p]] -= ret;
		c[fa[p] ^ 1] += ret;
		p = to[fa[p] ^ 1];
	}
	cost = ret * dis[ed];
	return ret;
}

int flow(int &cost) {
	int ret = 0, t1, t2;
	while (t1 = SPFA(t2)) {
		ret += t1;
		cost += t2;
	}
	return ret;
}

int main() {
	scanf("%s", t);	
	lt = strlen(t);
	for (int i = 0; i < lt; ++i) {
		++cnt[t[i] - 'a'];
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s%d", s[i], &a[i]);
		int ll = strlen(s[i]);
		a[i] = min(a[i], ll);
		for (int j = 0; j < ll; ++j) {
			++cnti[i][s[i][j] - 'a'];
		}
	}
	buildGraph();	
	int ans = 0, f;
	f = flow(ans);
	if (f != lt) {
		ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}