#include <bits/stdc++.h>
using namespace std;

const int Maxn = 40005;
int n, m, mct, top, c[Maxn], sta[Maxn], a[Maxn], head[Maxn];
long long g1[Maxn], g2[Maxn], k[Maxn], b[Maxn];
pair <int, int> M[10 * Maxn];
deque <int> De[Maxn];
struct Tree
{
	int lt, rt, id;
} tree[4 * Maxn];
long long f(int id, int x)
{
	return k[id] * x + b[id];
}
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt, 0};
	if (lt + 1 != rt)
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
	}
}
void insert(int root, int id)
{
	if (tree[root].lt + 1 == tree[root].rt)
	{
		if (f(id, tree[root].lt) < f(tree[root].id, tree[root].lt))
		{
			M[++mct] = make_pair(root, tree[root].id);
			tree[root].id = id;
		}
	}
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (k[id] > k[tree[root].id])
		{
			if (f(id, mid) < f(tree[root].id, mid))
			{
				insert(root << 1 | 1, tree[root].id);
				M[++mct] = make_pair(root, tree[root].id);
				tree[root].id = id;
			}
			else insert(root << 1, id);
		}
		else
		{
			if (f(id, mid) < f(tree[root].id, mid))
			{
				insert(root << 1, tree[root].id);
				M[++mct] = make_pair(root, tree[root].id);
				tree[root].id = id;
			}
			else insert(root << 1 | 1, id);
		}
	}
}
long long ask(int root, int x)
{
	if (tree[root].lt + 1 == tree[root].rt)
		return f(tree[root].id, x);
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (x >= mid) return min(f(tree[root].id, x), ask(root << 1 | 1, x));
		else return min(f(tree[root].id, x), ask(root << 1, x));
	}
}
void backto(int goal)
{
	while (mct != goal)
		tree[M[mct].first].id = M[mct].second, mct--;
}
double slope(int x, int y)
{
	return (g1[x - 1] - g1[y - 1]) / (double) (x - y);
}
void poly_insert1(int pos, int x)
{
	while (De[pos].size() > 1 && slope(*(++De[pos].rbegin()), *De[pos].rbegin()) > slope(*De[pos].rbegin(), x))
		De[pos].pop_back();
	De[pos].push_back(x);
}
void poly_insert2(int pos, int x)
{
	while (De[pos].size() > 1 && slope(x, *De[pos].begin()) > slope(*De[pos].begin(), *(++De[pos].begin())))
		De[pos].pop_front();
	De[pos].push_front(x);
}
void merge(int x, int y)
{
	if (De[x].size() > De[y].size())
	{
		for (int i = De[y].size() - 1; i >= 0; i--)
			poly_insert2(x, De[y][i]);
	}
	else
	{
		De[x].swap(De[y]);
		for (int i = 0; i < (int) De[y].size(); i++)
			poly_insert1(x, De[y][i]);
	}
}
long long get_mini(int pos, int val)
{
	int l = 0, r = De[pos].size() - 1;
	while (l + 1 <= r)
	{
		int mid = (l + r) >> 1;
		if (slope(De[pos][mid], De[pos][mid + 1]) < val) l = mid + 1; 
		else r = mid;
	}
	return g1[De[pos][l] - 1] - (De[pos][l] - 1) * val;
}
int main()
{
	b[0] = 0x3f3f3f3f3f3f3f3fLL;
	scanf("%d%d", &n, &m);
	build(1, 1, n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	memset(g1, 0x3f, sizeof(long long[n + 1]));
	g1[0] = 0;
	while (m--)
	{
		top = 0;
		backto(0);
		for (int i = 1; i <= n; i++)
		{
			De[i].clear();
			while (top && a[sta[top]] <= a[i])
			{
				backto(c[sta[top]]);
				merge(i, sta[top]);
				top--;
			}
			poly_insert1(i, i);
			sta[++top] = i;
			k[i] = a[i];
			b[i] = get_mini(i, a[i]);
			c[i] = mct;
			insert(1, i);
			g2[i] = ask(1, i);
		}
		memcpy(g1, g2, sizeof(long long[n + 1]));
	}
	printf("%lld", g1[n]);
	return 0;
}