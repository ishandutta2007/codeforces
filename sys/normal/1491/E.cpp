#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, a, b, cnt, head[Maxn], siz[Maxn], id[Maxn], fib[27];
bool flag;
struct edg
{
	int nxt, to;
	bool del;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u, int fa, int e, int s)
{
	siz[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa && !edge[i].del)
		{
			dfs(to, u, i, s);
			siz[u] += siz[to];
		}
	}
	if (!flag && (siz[u] == fib[s - 1] || siz[u] == fib[s - 2]))
	{
		flag = true;
		a = u, b = fa;
		edge[e].del = edge[((e - 1) ^ 1) + 1].del = true;
	}
}
bool work(int s, int root)
{
	if (s == 1) return true;
	flag = false;
	dfs(root, 0, 0, id[s]);
	int tmp1 = a, tmp2 = b, S = siz[a];
	return flag && work(S, tmp1) && work(s - S, tmp2);
}
int main()
{
	scanf("%d", &n);
	fib[0] = fib[1] = 1, id[1] = 1;
	for (int i = 2; i <= 26; i++) fib[i] = fib[i - 1] + fib[i - 2], id[fib[i]] = i;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	puts((id[n] && work(n, 1)) ? "YES" : "NO");
	return 0;
}