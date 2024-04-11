#include <stdio.h>
#include <queue>
using namespace std;

int par[200005];
int root[200005];
int up[200005];
bool visit[200005];
bool now[200005];

int getparent(int n)
{
	if (up[n] == n) return n;
	return up[n] = getparent(up[n]);
}

void merge(int a, int b)
{
	up[getparent(b)] = getparent(a);
}

void dfs(int v)
{
	int next = par[v];
	if (visit[next])
	{
		if (now[next])
		{
			root[getparent(next)] = next;
			return;
		}
		return;
	}

	visit[next] = true;
	now[next] = true;
	dfs(next);
	now[next] = false;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) up[i] = i;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &par[i]);
		merge(i, par[i]);
	}

	int realroot = 0;
	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == false)
		{
			visit[i] = true;
			now[i] = true;
			dfs(i);
			now[i] = false;
		}

		if (par[i] == i)
		{
			realroot = i;
		}
	}

	if (realroot == 0)
	{
		realroot = root[getparent(1)];
		par[realroot] = realroot;
		ans = 1;
	}

	for (int j = 1; j <= n; j++)
	{
		if (getparent(realroot) == getparent(j)) continue;
		int oldroot = root[getparent(j)];

		merge(realroot, j);

		par[oldroot] = realroot;

		ans++;
	}

	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", par[i]);
	}
}