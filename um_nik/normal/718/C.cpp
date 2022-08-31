#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y)
{
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y)
{
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y)
{
	return (x * y) % MOD;
}

struct Matrix
{
	ll a[2][2];

	Matrix()
	{
		a[0][0] = a[1][1] = 1;
		a[1][0] = a[0][1] = 0;
	}

	Matrix operator * (const Matrix &A) const
	{
		Matrix R = Matrix();
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				R.a[i][j] = 0;
				for (int h = 0; h < 2; h++)
					R.a[i][j] += a[i][h] * A.a[h][j];
				R.a[i][j] %= MOD;
			}
		return R;
	}
	Matrix operator + (const Matrix &A) const
	{
		Matrix R = Matrix();
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				R.a[i][j] = add(a[i][j], A.a[i][j]);
		return R;
	}
};

const int N = 1 << 17;
struct Node
{
	int l, r;
	Matrix A;
	Matrix add;

	Node() : l(-1), r(-1), A(), add() {}
	Node(int _l, int _r) : l(_l), r(_r), A(), add() {}
};
Node tree[2 * N];

void push(int v)
{
	if (v >= N) throw;
	for (int u = 2 * v; u < 2 * v + 2; u++)
	{
		tree[u].add = tree[u].add * tree[v].add;
		tree[u].A = tree[u].A * tree[v].add;
	}
	tree[v].add = Matrix();
	return;
}
void update(int v)
{
	if (v >= N) throw;
	tree[v].A = tree[2 * v].A + tree[2 * v + 1].A;
	return;
}

void build()
{
	for (int i = 0; i < N; i++)
		tree[N + i] = Node(i, i + 1);
	for (int i = N - 1; i > 0; i--)
	{
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r);
		update(i);
	}
}

void multOnSegm(int v, int l, int r, Matrix A)
{
	if (l <= tree[v].l && tree[v].r <= r)
	{
		tree[v].add = tree[v].add * A;
		tree[v].A = tree[v].A * A;
		return;
	}
	if (l >= tree[v].r || tree[v].l >= r) return;
	push(v);
	for (int u = 2 * v; u < 2 * v + 2; u++)
		multOnSegm(u, l, r, A);
	update(v);
	return;
}

Matrix getOnSegm(int v, int l, int r)
{
	if (l <= tree[v].l && tree[v].r <= r) return tree[v].A;
	if (l >= tree[v].r || tree[v].l >= r) return Matrix();
	push(v);
	return getOnSegm(2 * v, l, r) + getOnSegm(2 * v + 1, l, r);
}

Matrix bin_pow(Matrix A, ll p)
{
	if (p == 0) return Matrix();
	if (p == 2 || (p & 1)) return A * bin_pow(A, p - 1);
	return bin_pow(bin_pow(A, p / 2), 2);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	Matrix F = Matrix();
	F.a[0][0] = F.a[1][0] = F.a[0][1] = 1;
	F.a[1][1] = 0;

	build();
	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		multOnSegm(1, i, i + 1, bin_pow(F, x));
	}
	while(q--)
	{
		int t;
		scanf("%d", &t);
		if (t == 1)
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			l--;
			multOnSegm(1, l, r, bin_pow(F, x));
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			l--;
			Matrix A = getOnSegm(1, l, r);
			printf("%lld\n", A.a[1][0]);
		}
	}

	return 0;
}