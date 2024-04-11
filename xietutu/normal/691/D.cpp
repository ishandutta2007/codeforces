#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1000100;
int n, m, EC, cnt, a[maxn], c[maxn], b[maxn], p[maxn];
bool visit[maxn];
struct edge {
	int v; edge* next;
} ES[maxn * 2], *tot[maxn];
void add(int u, int v) {
	ES[++EC].v = v; ES[EC].next = tot[u]; tot[u] = ES + EC;
}
void read(int& x) {
	x = 0;
	char ch = getchar();
	while (!(ch >= '0' && ch <= '9')) ch = getchar();
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
}
void dfs(int x) {
	visit[x] = true;
	b[++cnt] = x;
	a[cnt] = p[x];
	for (edge* e = tot[x]; e; e = e->next)
		if (!visit[e->v])
			dfs(e->v);
}
int main() {
	read(n); read(m);
	for (int i = 1; i <= n; ++i)
		read(p[i]);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		read(u); read(v);
		add(u, v); add(v, u);
	}
	for (int i = 1; i <= n; ++i)
		if (!visit[i]) {
			cnt = 0;
			dfs(i);
			sort(b + 1, b + cnt + 1);
			sort(a + 1, a + cnt + 1); reverse(a + 1, a + cnt + 1);
			for (int j = 1; j <= cnt; ++j)
				c[b[j]] = a[j];
		}
	for (int i = 1; i <= n; ++i)
		printf("%d ", c[i]);
}