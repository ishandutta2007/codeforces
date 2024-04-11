#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int M = 1e9+7;
const int maxn = 2005;
int ans, minv, n, d, EC;
int a[maxn], siz[maxn], f[maxn][3], v[maxn]; 
long long tmp[2];
bool visit[maxn], can[maxn];
struct edge {
	int v; edge* next;
} ES[maxn * 2], *tot[maxn];
vector<int> g[maxn];
void dfs(int x) {
	visit[x] = true;
	g[x].clear();
	for (edge* e = tot[x]; e; e = e->next)
		if (!visit[e->v] && can[e->v]) {
			g[x].push_back(e->v);
			dfs(e->v);
		}
	tmp[0] = tmp[1] = 1;
	for (unsigned int i = 0; i < g[x].size(); ++i) {
		int son = g[x][i];
		tmp[0] = 1LL * tmp[0] * (f[son][0] + 1) % M;
		tmp[1] = 1LL * tmp[1] * (f[son][2] + 1) % M;
	}
	
	if (a[x] == minv) {
		f[x][0] = 0;
		f[x][1] = tmp[1];
	}
	else {
		f[x][0] = tmp[0];
		f[x][1] = (tmp[1] - tmp[0]) % M;
	}
	f[x][2] = (f[x][1] + f[x][0]) % M;
	ans = (ans + f[x][1]) % M;
}
void add(int u, int v) {
	ES[++EC].v = v; ES[EC].next = tot[u]; tot[u] = ES + EC;
}
void solve(int x) {
	memset(visit, 0, sizeof(visit));
	minv = x;
	for (int i = 1; i <= n; ++i)
		if (a[i] >= minv && a[i] <= minv + d)
			can[i] = true;
		else can[i] = false;
	for (int i = 1; i <= n; ++i)
		if (!visit[i] && can[i]) 
			dfs(i);
}
int main() {
	scanf("%d%d", &d, &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		v[i] = a[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	sort(v + 1, v + n + 1);
	for (int i = 1; i <= n; ++i)
		if (v[i] != v[i - 1]) 
			solve(v[i]);
	ans = (ans + M) % M;
	printf("%d\n", ans);
}