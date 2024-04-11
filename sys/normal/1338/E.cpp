#include <bits/stdc++.h>
using namespace std;

const int Maxn = 8005;
int n, scc, cnt1, cnt2, cnt3, top, dfn_cnt, bel[Maxn], sta[Maxn], dfn[Maxn], low[Maxn], v[Maxn], siz[Maxn];
bool G[Maxn][Maxn];
void Tarjan(int u)
{
	dfn[u] = low[u] = ++dfn_cnt;
	sta[++top] = u;
	for (int i = 1; i <= n; i++)
		if (G[u][i])
		{
			if (!dfn[i]) Tarjan(i), low[u] = min(low[u], low[i]);
			else low[u] = min(low[u], dfn[i]);
		}
	if (low[u] == dfn[u])
	{
		scc++;
		int x;
		do
			x = sta[top--], bel[x] = scc, siz[scc]++;
		while (x != u);
	}
}
int change(char ch)
{
	if (isdigit(ch)) return ch - '0';
	return ch - 'A' + 10;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j += 4)
		{
			char ch = getchar();
			while (!isdigit(ch) && !isalpha(ch))
				ch = getchar();
			int x = change(ch);
			G[i][j] = (x >> 3) & 1;
			G[i][j + 1] = (x >> 2) & 1;
			G[i][j + 2] = (x >> 1) & 1;
			G[i][j + 3] = x & 1;
		}
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) Tarjan(i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (bel[i] == 1 && G[i][j] && (!v[i] || G[v[i]][j])) v[i] = j;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cnt2 += (bel[i] == 1 && bel[j] == 1 && G[j][i] && G[v[i]][j]);
	cnt1 = siz[1] * (siz[1] - 1) / 2;
	cnt3 = siz[1] * (siz[1] - 1) / 2 - cnt2;
	printf("%lld", (n - siz[1]) * (n + siz[1] - 1LL) / 2 * (1 + 614 * n) + cnt1 + 2 * cnt2 + 3 * cnt3);
	return 0;
}