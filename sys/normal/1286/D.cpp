#include <bits/stdc++.h>
using namespace std;

const int p = 998244353, Maxn = 200005;
int n, ct, x[Maxn], v[Maxn], pr[Maxn];
long long inv[10 * Maxn];
long long ans;
struct Matrix
{
	long long val[2][2];
	Matrix ()
	{
		memset(val, 0, sizeof(val));
	}
	Matrix operator * (const Matrix &A) const
	{
		Matrix ans;
		for (int i = 0; i <= 1; i++)
			for (int j = 0; j <= 1; j++)
				for (int k = 0; k <= 1; k++)
					(ans.val[i][j] += val[i][k] * A.val[k][j]) %= p;
		return ans;
	}
} M[Maxn];
struct Tree
{
	int lt, rt;
	Matrix val;
} tree[4 * Maxn];
void build(int root, int lt, int rt)
{
	tree[root] = (Tree){lt, rt};
	if (lt + 1 == rt)
		tree[root].val = M[lt];
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
		tree[root].val = M[pos];
	else
	{
		int mid = (tree[root].lt + tree[root].rt) >> 1;
		if (pos >= mid) modify(root << 1 | 1, pos);
		else modify(root << 1, pos);
		tree[root].val = tree[root << 1].val * tree[root << 1 | 1].val;
	}
}
struct sta
{
	int id, d, v;
	long long * pos;
	bool operator < (const sta &tmp) const
	{
		return d / (double) v < tmp.d / (double) tmp.v;
	}
} A[2 * Maxn];
long long cal(void)
{
	return (pr[1] * (tree[1].val.val[1][0] + tree[1].val.val[1][1]) + (1 - pr[1] + p) * (tree[1].val.val[0][0] + tree[1].val.val[0][1])) % p;
}
int main()
{
	scanf("%d", &n);
	if (n == 1)
	{
		puts("0");
		return 0;
	}
	inv[0] = inv[1] = 1;
	for (int i = 2; i <= 2000000; i++)
		inv[i] = (p - p / i) * inv[p % i] % p;
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", &x[i], &v[i], &pr[i]), pr[i] = (pr[i] * inv[100]) % p;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 1; j++)
			for (int k = 0; k <= 1; k++)
				M[i].val[j][k] = k ? pr[i] : (1 - pr[i] + p) % p;
		int d = x[i] - x[i - 1];
		A[++ct] = (sta){i, d, v[i] + v[i - 1], &M[i].val[1][0]};
		if (v[i] > v[i - 1]) A[++ct] = (sta){i, d, v[i] - v[i - 1], &M[i].val[0][0]};
		if (v[i] < v[i - 1]) A[++ct] = (sta){i, d, v[i - 1] - v[i], &M[i].val[1][1]};
	}
	build(1, 2, n + 1);
	sort(A + 1, A + 1 + ct);
	for (int i = 1; i <= ct; i++)
	{
		long long las = cal();
		*A[i].pos = 0;
		modify(1, A[i].id);
		(ans += A[i].d * inv[A[i].v] % p * (las - cal() + p)) %= p;
	}
	printf("%lld", ans);
	return 0;
}