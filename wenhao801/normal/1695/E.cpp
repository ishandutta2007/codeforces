#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 600600;
int n; vector <int> E[MAXN], id[MAXN];

vector <int> ans[2];
vector <char> ans1[2], ans2[2];
void add(int u1, int v1, int u2, int v2) {
	if (u1 == u2 || v1 == v2) swap(u1, v1);
	ans[0].push_back(u1), ans[0].push_back(v1);
	ans[1].push_back(u2), ans[1].push_back(v2);
	ans1[0].push_back('L'), ans1[0].push_back('R'), ans1[1].push_back('L'), ans1[1].push_back('R');
	ans2[0].push_back('U'), ans2[0].push_back('U'), ans2[1].push_back('D'), ans2[1].push_back('D');
}
void add (int u1, int v1, int u2, int v2, int u3, int v3) {
	if (u1 == u2 || v1 == v2) swap(u1, v1);
	if (u2 == u3 || v2 == v3) swap(u3, v3);
	ans[0].push_back(u1), ans[0].push_back(u2), ans[0].push_back(u3);
	ans[1].push_back(v1), ans[1].push_back(v2), ans[1].push_back(v3);
	ans1[0].push_back('L'), ans1[0].push_back('R'), ans1[0].push_back('U');
	ans1[1].push_back('L'), ans1[1].push_back('R'), ans1[1].push_back('D');
	ans2[0].push_back('U'), ans2[0].push_back('L'), ans2[0].push_back('R');
	ans2[1].push_back('D'), ans2[1].push_back('L'), ans2[1].push_back('R');
}

int cnt, vis[MAXN];
void pre(int x) {
	if (!vis[x]) {
		vis[x] = 1; 
		for (auto i: E[x]) ++cnt, pre(i);
	}
}

int fa[MAXN]; bool visE[MAXN];
bool dfs(int x) {
	++vis[x];
	vector <int> cur;
	for (int it = 0; it < E[x].size(); it++) if (!visE[id[x][it]]) {
		visE[id[x][it]] = 1;
		const int i = E[x][it];
		if (vis[i] < 2) {
			fa[i] = x;
			if (dfs(i)) cur.push_back(i);
		}
		else cur.push_back(i);
	}
	while (cur.size() >= 4) {
		const int s = cur.size() - 1;
		add(cur[s], x, cur[s - 1], x);
		cur.pop_back(), cur.pop_back();
	}
	if (cnt & 1) {
		if (cur.size() >= 3) {
			const int s = cur.size() - 1;
			--cnt; add(cur[s], x, cur[s - 1], x, cur[s - 2], x);
			cur.pop_back(), cur.pop_back(), cur.pop_back();
		}
		if (cur.size() == 2 && fa[x]) {
			const int s = cur.size() - 1;
			--cnt; add(cur[s], x, cur[s - 1], x, fa[x], x);
			return 0;
		}
	}
	if (!fa[x] && (cnt & 1)) {
		ans1[0].pop_back(), ans1[0].pop_back(), ans1[1].pop_back(), ans1[1].pop_back();
		ans2[0].pop_back(), ans2[0].pop_back(), ans2[1].pop_back(), ans2[1].pop_back();
		const int s = ans[0].size() - 1;
		int u1 = ans[0][s - 1], v1 = ans[0][s], u2 = ans[1][s - 1], v2 = ans[1][s];
		ans[0].pop_back(), ans[0].pop_back(), ans[1].pop_back(), ans[1].pop_back();
		add(x, cur[0], u1, v1, u2, v2); --cnt;
	}
	while (cur.size() >= 2) {
		const int s = cur.size() - 1;
		add(cur[s], x, cur[s - 1], x);
		cur.pop_back(), cur.pop_back();
	}
	if (!cur.empty() && fa[x]) { add(fa[x], x, x, cur[0]); return 0; }
	return 1;
}

int main() {
	n = read(); int i, j;
	for (i = 1; i <= n; i++) {
		int u = read(), v = read();
		E[u].push_back(v), E[v].push_back(u);
		id[u].push_back(i), id[v].push_back(i);
	}
	for (i = 1; i <= n * 2; i++) if (!vis[i]) {
		cnt = 0; pre(i); cnt >>= 1;
		if (cnt == 1) { puts("-1"); return 0; }
		dfs(i);
	}
	printf("%d %d\n", 2, n);
	for (i = 0; i < n; i++) printf("%d ", ans[0][i]); putchar('\n');
	for (i = 0; i < n; i++) printf("%d ", ans[1][i]); putchar('\n');
	for (i = 0; i < n; i++) putchar(ans1[0][i]); putchar('\n');
	for (i = 0; i < n; i++) putchar(ans1[1][i]); putchar('\n');
	for (i = 0; i < n; i++) putchar(ans2[0][i]); putchar('\n');
	for (i = 0; i < n; i++) putchar(ans2[1][i]); putchar('\n');
	return 0;
}