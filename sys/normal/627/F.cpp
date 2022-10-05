#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 200005;
int n, s, t, p, cnt, a[Maxn], b[Maxn], deg[Maxn], head[Maxn];
vector <int> A, B, Ve1, Ve, spec;
pair <int, int> mini = make_pair(0x3f3f3f3f, 0);
bool vis[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
bool dfs1(int u, int fa)
{
	Ve1.push_back(u);
	if (u == t) return true;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa && dfs1(to, u)) return true;
	}
	Ve1.pop_back();
	return false;
}
void dfs2(int u, int fa, int dep)
{
	if (a[u] != b[u])
	{
		Ve.push_back(u);
		if (dep == mini.first && fa != mini.second)
		{
			puts("-1");
			exit(0);
		}
		if (dep < mini.first) mini = make_pair(dep, fa);
	}
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
			dfs2(to, u, dep + 1);
	}
}
void dfs3(int u, int fa)
{
	if (u != p)
		A.push_back(a[u]), B.push_back(b[u]);
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa && vis[to]) dfs3(to, u);
	}
}
int dfs4(int u, int fa, int dep, int goal)
{
	if (u == goal) return dep;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			int result = dfs4(to, u, dep + 1, goal);
			if (result) return result;
		}
	}
	return 0;
}
int get_shift(void)
{
	int pos = 0;
	for (int i = 0; i < (int) B.size(); i++)
		if (A[0] == B[i]) pos = i;
	if (!pos) return 0;
	for (int i = 0; i < (int) B.size(); i++)
		if (A[i] != B[(i + pos) % (int) B.size()]) return 0;
	return pos;
}
int get_dis(int x, int y)
{
	return dfs4(x, 0, 0, y);
}
long long work(int x, int y)
{
	int c = get_shift();
	return (c - 1LL) * (A.size() + 1) + 1 + get_dis(s, x) + get_dis(y, t);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), s = (a[i] == 0 ? i : s);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]), t = (b[i] == 0 ? i : t);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs1(s, 0);
	for (int i = 1; i < (int) Ve1.size(); i++)
		swap(a[Ve1[i]], a[Ve1[i - 1]]);
	bool flag = true;
	for (int i = 1; i <= n; i++)
		if (a[i] != b[i]) flag = false;
	if (flag)
	{
		printf("%d %d\n", 0, (int) Ve1.size() - 1);
		return 0;
	}
	dfs2(t, 0, 0);
	p = mini.second, Ve.push_back(p);
	for (auto u : Ve) vis[u] = true;
	for (auto u : Ve)
		for (int i = head[u]; i; i = edge[i].nxt)
			deg[edge[i].to]++;
	for (auto u : Ve)
		if (deg[u] == 1) spec.push_back(u);
		else if (deg[u] != 2)
		{
			puts("-1");
			return 0;
		}
	if (spec.size() != 2)
	{
		puts("-1");
		return 0;
	}
	int u = spec[0], v = spec[1];
	if (u > v) swap(u, v);
	dfs3(u, 0);
	if (!get_shift())
	{
		puts("-1");
		return 0;
	}
	printf("%d %d ", u, v);
	long long result = work(u, v);
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	printf("%lld", min(result, work(v, u)));
	return 0;
}