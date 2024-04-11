#include <cstdio>
#include <algorithm>
#include <list>
#include <cstring>
#include <map>
#include <set>
using namespace std;
const int maxn = 100010;
struct edge {
	int v; edge* next;
} ES[maxn * 2], *tot[maxn];
int EC, n, m, ans, s[maxn], a[maxn];
bool can[maxn];
void add(int u, int v) {
	ES[++EC].v = v; ES[EC].next = tot[u]; tot[u] = ES + EC;
}
void dfs(int x, int fa) {
	bool son = false;
	if (a[x] == 1)
		s[x] = s[fa] + 1;
	else s[x] = 0;
	if (s[x] > m || !can[fa])
		can[x] = false;
	else can[x] = true;
	for (edge* e = tot[x]; e; e = e->next)
		if (e->v != fa) {
			son = true;
			dfs(e->v, x);
		}
	if (!son && can[x]) ++ans;
}
int main() {

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) 
		scanf("%d", a + i);
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	can[0] = true;
	dfs(1, 0);
	printf("%d\n", ans);
}