#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 500005, Maxk = 55;
int n, m, k, q, ct, siz[Maxk][Maxn], fa[Maxk][Maxn], las[Maxn];
bool _null, tag[Maxk][Maxn];
struct edg
{
	int x, y;
} edge[Maxn];
struct quest
{
	int edge, col, nxt, pre;
} Q[Maxn];
struct back
{
	int x, siz, tag, col;
} sta[20 * Maxn];
vector <pair <int, int> > Ve[4 * Maxn];
void insert(int root, int lt, int rt, int L, int R, pair <int, int> mess)
{
	if (L == R) return ;
	if (lt == L && rt == R) Ve[root].push_back(mess);
	else
	{
		int mid = (lt + rt) >> 1;
		if (L >= mid) insert(root << 1 | 1, mid, rt, L, R, mess);
		else if (R <= mid) insert(root << 1, lt, mid, L, R, mess);
		else insert(root << 1, lt, mid, L, mid, mess), insert(root << 1 | 1, mid, rt, mid, R, mess);
	}
}
int get_fa(int col, int x, bool &v = _null)
{
	v = tag[col][x];
	while (x != fa[col][x]) x = fa[col][x], v ^= tag[col][x];
	return x;
}
void merge(int edge, int col, int x, int y)
{
	bool tmp1, tmp2;
	int a = get_fa(col, x, tmp1), b = get_fa(col, y, tmp2);
	if (siz[col][a] < siz[col][b]) swap(a, b);
	sta[++ct] = (back){b, siz[col][a], tag[col][b], col};
	fa[col][b] = a;
	siz[col][a] += siz[col][b];
	tag[col][b] ^= tmp1 ^ tmp2 ^ 1;
}
void revoke(int ct)
{
	siz[sta[ct].col][fa[sta[ct].col][sta[ct].x]] = sta[ct].siz;
	tag[sta[ct].col][sta[ct].x] = sta[ct].tag;
	fa[sta[ct].col][sta[ct].x] = sta[ct].x;
}
void dfs(int root, int lt, int rt)
{
	int tmp_ct = ct;
	for (vector <pair <int, int> > :: iterator it = Ve[root].begin(); it != Ve[root].end(); it++)
	{
		if (get_fa(it -> second, edge[it -> first].x) != get_fa(it -> second, edge[it -> first].y))
			merge(it -> first, it -> second, edge[it -> first].x, edge[it -> first].y);
	}
	if (lt + 1 == rt)
	{
		bool tmp1, tmp2;
		if (get_fa(Q[lt].col, edge[Q[lt].edge].x, tmp1) == get_fa(Q[lt].col, edge[Q[lt].edge].y, tmp2) && tmp1 == tmp2)
		{
			puts("NO");
			insert(1, 1, q + 1, lt + 1, Q[lt].nxt, make_pair(Q[lt].edge, Q[lt].col = Q[Q[lt].pre].col));
		}
		else
		{
			puts("YES");
			insert(1, 1, q + 1, lt + 1, Q[lt].nxt, make_pair(Q[lt].edge, Q[lt].col));
		}
	}
	else
	{
		int mid = (lt + rt) >> 1;
		dfs(root << 1, lt, mid), dfs(root << 1 | 1, mid, rt);
	}
	while (ct != tmp_ct)
		revoke(ct--);
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
			siz[i][j] = 1, fa[i][j] = j;
	for (int i = 1; i <= m; i++)
		scanf("%d%d", &edge[i].x, &edge[i].y);
	for (int i = 1; i <= q; i++)
		scanf("%d%d", &Q[i].edge, &Q[i].col);
	for (int i = 1; i <= q; i++)
	{
		Q[i].pre = las[Q[i].edge];
		las[Q[i].edge] = i;
	}
	memset(las, 0, sizeof(las));
	for (int i = q; i >= 1; i--)
	{
		Q[i].nxt = las[Q[i].edge];
		if (!Q[i].nxt) Q[i].nxt = q + 1;
		las[Q[i].edge] = i;
	}
	dfs(1, 1, q + 1);
	return 0;
}