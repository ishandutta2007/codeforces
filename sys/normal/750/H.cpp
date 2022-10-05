#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005, Maxc = 2000005;
const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1, 0}, dy[] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
int h, w, q, ct, dsu_ct, u[15], v[15], id[Maxn][Maxn], fa[Maxc], siz[Maxc], tmp_fa[Maxc], tmp_siz[Maxc];
char G[Maxn][Maxn];
set <int> Se[Maxc];
pair <int, int> D[Maxc];
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	fa[a] = b;
	if (a != b) siz[b] += siz[a];
}
int tmp_get_fa(int x)
{
	return x == tmp_fa[x] ? x : tmp_get_fa(tmp_fa[x]);
}
void tmp_merge(int x, int y)
{
	int a = tmp_get_fa(x), b = tmp_get_fa(y);
	if (a == b) return ;
	if (tmp_siz[a] > tmp_siz[b]) swap(a, b);
	D[++dsu_ct] = make_pair(a, b);
	tmp_fa[a] = b;
	tmp_siz[b] += tmp_siz[a];
}
void dfs(int x, int y, int c, set <int> &S)
{
	if (x == 2 && y == 2) return ;
	if (x == h - 1 && y == w - 1) return ;
	if (G[x][y] == '#') S.insert(get_fa(id[x][y]));
	if (!c) return ;
	for (int d = 1; d <= 8; d++)
		if (id[x + dx[d]][y + dy[d]]) dfs(x + dx[d], y + dy[d], c - 1, S);
}
int main()
{
	scanf("%d%d%d", &h, &w, &q);
	h += 2, w += 2;
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			id[i][j] = ++ct, fa[ct] = ct, siz[ct] = 1;
	for (int i = 3; i <= h; i++)
		G[i][1] = '#';
	for (int i = 1; i <= h - 3; i++)
		G[i][w] = '#';
	for (int i = 3; i <= w; i++)
		G[1][i] = '#';
	for (int i = 1; i <= w - 3; i++)
		G[h][i] = '#';
	for (int i = 2; i <= h - 1; i++)
		for (int j = 2; j <= w - 1; j++)
		{
			G[i][j] = getchar();
			while (G[i][j] != '.' && G[i][j] != '#') G[i][j] = getchar();
		}
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			for (int d = 1; d <= 8; d++)
				if (id[i + dx[d]][j + dy[d]] && G[i][j] == '#' && G[i + dx[d]][j + dy[d]] == '#')
					merge(id[i][j], id[i + dx[d]][j + dy[d]]);
	for (int i = 1; i <= h; i++)
		for (int j = 1; j <= w; j++)
			dfs(i, j, 2, Se[get_fa(id[i][j])]);
	memcpy(tmp_fa, fa, sizeof(int[ct + 1]));
	memcpy(tmp_siz, siz, sizeof(int[ct + 1]));
	while (q--)
	{
		dsu_ct = 0;
		int k;
		scanf("%d", &k);
		for (int i = 1; i <= k; i++)
		{
			scanf("%d%d", &u[i], &v[i]);
			u[i]++, v[i]++;
			G[u[i]][v[i]] = '#';
		}
		for (int i = 1; i <= k; i++)
			for (int d = 1; d <= 8; d++)
				if (id[u[i] + dx[d]][v[i] + dy[d]] && G[u[i] + dx[d]][v[i] + dy[d]] == '#')
					tmp_merge(id[u[i]][v[i]], id[u[i] + dx[d]][v[i] + dy[d]]); 
		for (int i = 1; i <= k; i++)
			for (int d = 0; d <= 8; d++)
				if (id[u[i] + dx[d]][v[i] + dy[d]])
				{
					if (tmp_get_fa(id[u[i] + dx[d]][v[i] + dy[d]]) == tmp_get_fa(id[h][1]))
					{
						int pos = get_fa(id[u[i] + dx[d]][v[i] + dy[d]]);
						for (set <int> :: iterator it = Se[pos].begin(); it != Se[pos].end(); it++)
							if (tmp_get_fa(*it) == tmp_get_fa(id[1][w]))
							{
								puts("NO");
								goto END;
							}
					}
					if (tmp_get_fa(id[u[i] + dx[d]][v[i] + dy[d]]) == tmp_get_fa(id[1][w]))
					{
						int pos = get_fa(id[u[i] + dx[d]][v[i] + dy[d]]);
						for (set <int> :: iterator it = Se[pos].begin(); it != Se[pos].end(); it++)
							if (tmp_get_fa(*it) == tmp_get_fa(id[h][1]))
							{
								puts("NO");
								goto END;
							}
					}
				}
		for (int i = 1; i <= k; i++)
			for (int j = i + 1; j <= k; j++)
				if (max(abs(u[i] - u[j]), abs(v[i] - v[j])) <= 2)
				{
					if (tmp_get_fa(id[u[i]][v[i]]) == tmp_get_fa(id[1][w]) && tmp_get_fa(id[u[j]][v[j]]) == tmp_get_fa(id[h][1]))
					{
						puts("NO");
						goto END;
					}
					if (tmp_get_fa(id[u[i]][v[i]]) == tmp_get_fa(id[h][1]) && tmp_get_fa(id[u[j]][v[j]]) == tmp_get_fa(id[1][w]))
					{
						puts("NO");
						goto END;
					}
				}
		puts("YES");
		END:fflush(stdout);
		for (int i = dsu_ct; i >= 1; i--)
		{
			tmp_fa[D[i].first] = D[i].first;
			tmp_siz[D[i].second] -= tmp_siz[D[i].first];
		}
		for (int i = 1; i <= k; i++)
			G[u[i]][v[i]] = '.';
	}
	return 0;
}