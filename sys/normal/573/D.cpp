#include <bits/stdc++.h>
using namespace std;

const long long inf = 0x3f3f3f3f3f3f3f3fLL;
const int Maxn = 30005;
int n, q, ban[Maxn], ord1[Maxn], ord2[Maxn], pos1[Maxn], pos2[Maxn];
long long a[Maxn], b[Maxn];
struct Matrix
{
	long long val[3][3];
	Matrix()
	{
		for (int i = 0; i <= 2; i++)
			for (int j = 0; j <= 2; j++)
				val[i][j] = -inf;
	}
	Matrix operator * (const Matrix &A) const
	{
		Matrix ans;
		for (int i = 0; i <= 2; i++)
			for (int j = 0; j <= 2; j++)
				for (int k = 0; k <= 2; k++)
					ans.val[i][k] = max(ans.val[i][k], val[i][j] + A.val[j][k]);
		return ans;
	}
};
struct Tree
{
	int lt, rt;
	Matrix val;
} tree[4 * Maxn];
Matrix gen(int x)
{
	Matrix result;
	result.val[0][0] = (x > 2 && ban[x - 2] != x - 2) ? a[x - 2] * b[x - 2] : -inf;
	result.val[0][1] = (x > 2 && ban[x - 2] != x - 1 && ban[x - 1] != x - 2) ? a[x - 2] * b[x - 1] + a[x - 1] * b[x - 2] : -inf;
	result.val[0][2] = (x > 2 && ban[x - 2] != x - 1 && ban[x - 1] != x && ban[x] != x - 2) ? a[x - 2] * b[x - 1] + a[x - 1] * b[x] + a[x] * b[x - 2] : -inf;
	result.val[0][2] = max(result.val[0][2], (x > 2 && ban[x - 2] != x && ban[x - 1] != x - 2 && ban[x] != x - 1) ? a[x - 2] * b[x] + a[x - 1] * b[x - 2] + a[x] * b[x - 1] : -inf);
	result.val[1][0] = 0;
	result.val[1][1] = (x > 1 && ban[x - 1] != x - 1) ? a[x - 1] * b[x - 1] : -inf;
	result.val[1][2] = (x > 1 && ban[x - 1] != x && ban[x] != x - 1) ? a[x - 1] * b[x] + a[x] * b[x - 1] : -inf;
	result.val[2][1] = 0;
	result.val[2][2] = (ban[x] != x) ? a[x] * b[x] : -inf;
	return result;
}
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt};
	if (lt + 1 == rt)
		tree[root].val = gen(lt);
	else
	{
		int mid = (lt + rt) >> 1;
		build(root << 1, lt, mid);
		build(root << 1 | 1, mid, rt);
		tree[root].val = tree[root << 1].val * tree[root << 1 | 1].val;
	}
}
void modify(int root, int pos)
{
	if (tree[root].lt + 1 == tree[root].rt)
		tree[root].val = gen(tree[root].lt);
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) modify(root << 1 | 1, pos);
		else modify(root << 1, pos);
		tree[root].val = tree[root << 1].val * tree[root << 1 | 1].val;
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), ord1[i] = i;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &b[i]), ban[i] = i, ord2[i] = i;
	sort(ord1 + 1, ord1 + 1 + n, [](int x, int y){return a[x] < a[y];});
	sort(ord2 + 1, ord2 + 1 + n, [](int x, int y){return b[x] < b[y];});
	for (int i = 1; i <= n; i++)
		pos1[ord1[i]] = i, pos2[ord2[i]] = i;
	for (int i = 1; i <= n; i++)
		ban[pos1[i]] = pos2[i];
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);
	build(1, 1, n + 1);
	while (q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		swap(ban[pos1[x]], ban[pos1[y]]);
		for (int i = max(1, pos1[x] - 2); i <= min(n, pos1[x] + 2); i++)
			modify(1, i);
		for (int i = max(1, pos1[y] - 2); i <= min(n, pos1[y] + 2); i++)
			modify(1, i);
		Matrix res;
		res.val[0][2] = 0;
		printf("%lld\n", (res * tree[1].val).val[0][2]);
	}
	return 0;
}