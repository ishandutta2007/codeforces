#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <ctime>
#include <valarray>
#include <complex>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<ll, ll> pll;
#define mp make_pair
#define X first
#define Y second
ll P;
ll K;
ll n;
int m;
ll value[2];

ll sum(ll x, ll y)
{
	x += y;
	if (x >= P) return x - P;
	return x;
}
ll sub(ll x, ll y)
{
	x -= y;
	if (x < 0) return x + P;
	return x;
}
ll mult(ll x, ll y)
{
	return (x * y) % P;
}

struct Matrix
{
	ll a[2][2];

	Matrix()
	{
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				a[i][j] = (ll)(i == j);
	}

	Matrix operator * (const Matrix &B) const
	{
		Matrix R = Matrix();
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				R.a[i][j] = 0;
				for (int h = 0; h < 2; h++)
					R.a[i][j] = sum(R.a[i][j], mult(a[i][h], B.a[h][j]));
			}
		return R;
	}

	void eprint() const
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
				eprintf("%lld ", a[i][j]);
			eprintf("\n");
		}
	}
};

struct Node
{
	int l, r;
	Matrix val;

	Node() : l(), r(), val() {}
	Node(int _l, int _r, Matrix _val) : l(_l), r(_r), val(_val) {}
};

const int N = 1 << 16;
Node tree[2 * N];

pll ev[N];
ll s[N];

void buildTree()
{
	for (int i = 0; i < N; i++)
	{
		if (i < n)
		{
			Matrix A = Matrix();
			A.a[0][0] = 0;
			A.a[1][0] = 1;
			A.a[0][1] = s[(i + n - 1) % n];
			A.a[1][1] = s[i];
			tree[N + i] = Node(i, i + 1, A);
		}
		else
			tree[N + i] = Node(i, i + 1, Matrix());
	}
	for (int i = N - 1; i > 0; i--)
		tree[i] = Node(tree[2 * i].l, tree[2 * i + 1].r, tree[2 * i].val * tree[2 * i + 1].val);
	return;
}

Matrix getMatrix(int v, int l, int r)
{
	if (l <= tree[v].l && tree[v].r <= r)
		return tree[v].val;
	if (tree[v].r <= l || r <= tree[v].l)
		return Matrix();
	return getMatrix(2 * v, l, r) * getMatrix(2 * v + 1, l, r);
}

Matrix bin_pow(const Matrix &A, ll p)
{
	Matrix R = Matrix();
	Matrix B = A;
	while(p > 0)
	{
		if (p & 1)
			R = R * B;
		B = B * B;
		p >>= 1;
	}
	return R;
}

void applyMatrix(const Matrix &A)
{
//	eprintf("apply matrix\n");
//	A.eprint();
	ll newValue[2];
	newValue[0] = sum(mult(value[0], A.a[0][0]), mult(value[1], A.a[1][0]));
	newValue[1] = sum(mult(value[0], A.a[0][1]), mult(value[1], A.a[1][1]));
	value[0] = newValue[0];
	value[1] = newValue[1];
	return;
}

void read()
{
	scanf("%lld%lld", &K, &P);
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &s[i]);
		s[i] %= P;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%lld%lld", &ev[i].X, &ev[i].Y);
		ev[i].Y %= P;
	}
	sort(ev, ev + m);
	while(m > 0 && ev[m - 1].X >= K) m--;
	ev[m++] = mp(K, 0);
	if (K == 0 || P == 1)
	{
		printf("0\n");
		exit(0);
	}
	if (K == 1)
	{
		printf("1\n");
		exit(0);
	}
	return;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	read();
	buildTree();
	value[0] = 0;
	value[1] = 1;
	ll curP = 1;
	for (int i = 0; i < m; i++)
	{
		if (curP != ev[i].X || i == 0)
		{
			if (i == 0)
			{
				ll newValue = sum(mult(value[0], s[(curP + n - 1) % n]), mult(value[1], s[curP % n]));
				value[0] = value[1];
				value[1] = newValue;
				curP++;
			}
			else
			{
				ll newValue = sum(mult(value[0], ev[i - 1].Y), mult(value[1], s[curP % n]));
				value[0] = value[1];
				value[1] = newValue;
				curP++;
			}
			ll nextPow = ((curP + n - 1) / n) * n;
//			eprintf("%lld\n", nextPow);
			if (nextPow <= ev[i].X && nextPow != curP)
			{
				applyMatrix(getMatrix(1, curP % n, n));
				curP = nextPow;
			}
//			eprintf("%lld %lld\n", value[0], value[1]);
			nextPow = (ev[i].X / n) * n;
//			eprintf("%lld\n", nextPow);
			if (nextPow > curP)
			{
				Matrix A = tree[1].val;
				ll p = (nextPow - curP) / n;
				A = bin_pow(A, p);
				applyMatrix(A);
				curP = nextPow;
			}
			applyMatrix(getMatrix(1, curP % n, ev[i].X % n));
			curP = ev[i].X;

			ll newValue = sum(mult(value[0], s[(curP + n - 1) % n]), mult(value[1], ev[i].Y));
			value[0] = value[1];
			value[1] = newValue;
			curP++;
		}
		else
		{
			ll newValue = sum(mult(value[0], ev[i - 1].Y), mult(value[1], ev[i].Y));
			value[0] = value[1];
			value[1] = newValue;
			curP++;
		}
	}
	printf("%lld\n", value[0]);

	return 0;
}