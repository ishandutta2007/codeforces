#include <bits/stdc++.h>
using namespace std;
 
const int Outxn = 100005;
int n, cnt, now, root, head[Outxn], siz[Outxn], mini[Outxn], son[Outxn], ans[Outxn];
pair <int, int> maxi[Outxn];
bool flag;
map <int, int> Out, Heavy, Path;
struct edg
{
	int nxt, to;
} edge[2 * Outxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void chk(int u, int w)
{
	if (w > maxi[u].first) maxi[u].second = maxi[u].first, maxi[u].first = w;
	else maxi[u].second = max(maxi[u].second, w);
	mini[u] = min(mini[u], w);
}
void init_dfs(int u, int fa)
{
	siz[u] = 1;
	mini[u] = 0x3f3f3f3f;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			init_dfs(to, u);
			if (siz[to] > siz[son[u]]) son[u] = to;
			siz[u] += siz[to];
			chk(u, siz[to]);
		}
	}
	if (n != siz[u]) chk(u, n - siz[u]);
	Out[siz[u]]++;
}
void inc(int x, int w)
{
	Out[x] += w;
	if (!Out[x]) Out.erase(x);
}
void insert1(int u, int fa)
{
	inc(siz[u], -1);
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa) insert1(to, u);
	}
}
void insert2(int u, int fa)
{
	Heavy[siz[u]]++;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa) insert2(to, u);
	}
}
void clear(int u, int fa)
{
	inc(siz[u], 1);
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa) clear(to, u);
	}
}
void dfs(int u, int fa)
{
	Path[siz[u]]++;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != son[u] && to != fa)
		{
			inc(siz[to], -1);
			dfs(to, u);
			inc(siz[to], 1);
			clear(to, u), Heavy.clear();
		}
	}
	if (son[u])
	{
		inc(siz[son[u]], -1);
		dfs(son[u], u);
		inc(siz[son[u]], 1);
	}
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != son[u] && to != fa)
			insert1(to, u);
	}
	Heavy[0] = 1;
	int lt = maxi[u].second, rt = n;
	if (n - siz[u] < siz[son[u]])
		while (lt + 1 <= rt)
		{
			int mid = (lt + rt) >> 1;
			auto it = Heavy.lower_bound(maxi[u].first - mid);
			if (it != Heavy.end() && it -> first <= mid - mini[u]) rt = mid;
			else lt = mid + 1;
		}
	else
		while (lt + 1 <= rt)
		{
			bool f = false;
			int mid = (lt + rt) >> 1;
			auto it = Out.lower_bound(maxi[u].first - mid);
			if (it != Out.end() && it -> first <= mid - mini[u]) f = true;
			it = Path.lower_bound(maxi[u].first + siz[u] - mid);
			if (it != Path.end() && it -> first - siz[u] <= mid - mini[u]) f = true;
			if (f) rt = mid;
			else lt = mid + 1;
		}
	ans[u] = lt;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != son[u] && to != fa)
			insert2(to, u);
	}
	Heavy[siz[u]]++;
	inc(siz[u], -1);
	Path[siz[u]]--;
}
int main()
{
	scanf("%d", &n);
	if (n == 1)
	{
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (!x) root = y;
		else add(x, y), add(y, x);
	}
	init_dfs(root, 0);
	dfs(root, 0);
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
	return 0;
}