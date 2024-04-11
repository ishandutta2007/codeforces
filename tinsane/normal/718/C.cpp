#pragma region Template
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#include <unordered_map>
#include <unordered_set>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef vector<int>::iterator vint_iter;

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-13;

#pragma endregion

const int P = 1e9 + 7;
int sum(int a, int b)
{
	a += b;
	return a >= P ? a - P : a;
}
int mul(int a, int b)
{
	return (ll) a * b % P;
}

struct Matr
{
	int a[2][2];
	Matr() : a() {}
	Matr operator+ (const Matr& m) const
	{
		Matr res;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				res.a[i][j] = sum(a[i][j], m.a[i][j]);
		return res;
	}
	Matr operator* (const Matr& m) const
	{
		Matr res;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k)
					res.a[i][j] = sum(res.a[i][j], mul(a[i][k], m.a[k][j]));
		return res;
	}
	bool operator== (const Matr& m) const
	{
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				if (a[i][j] != m.a[i][j])
					return false;
		return true;
	}
};
Matr E, F;

Matr bpow(Matr m, ll p)
{
	Matr res = E;
	for (; p > 0; p /= 2, m = m * m)
		if (p % 2 == 1)
			res = res * m;
	return res;
}

const int N = 1e5 + 10;
Matr segt[4 * N], to_p[4 * N];

void push(int ind)
{
	if (to_p[ind] == E)
		return;
	segt[ind * 2] = segt[ind * 2] * to_p[ind];
	segt[ind * 2 + 1] = segt[ind * 2 + 1] * to_p[ind];
	to_p[ind * 2] = to_p[ind * 2] * to_p[ind];
	to_p[ind * 2 + 1] = to_p[ind * 2 + 1] * to_p[ind];
	to_p[ind] = E;
}

void build(int ind, int l, int r)
{
	to_p[ind] = E;
	if (l == r)
	{
		segt[ind] = E;
		return;
	}
	int mid = (l + r) / 2;
	build(ind * 2, l, mid);
	build(ind * 2 + 1, mid + 1, r);
	segt[ind] = segt[ind * 2] + segt[ind * 2 + 1];
}

void mul(int ind, int l, int r, int L, int R, const Matr& m)
{
	if (r < L || R < l)
		return;
	if (L <= l && r <= R)
	{
		to_p[ind] = to_p[ind] * m;
		segt[ind] = segt[ind] * m;
		return;
	}
	push(ind);
	int mid = (l + r) / 2;
	mul(ind * 2, l, mid, L, R, m);
	mul(ind * 2 + 1, mid + 1, r, L, R, m);
	segt[ind] = segt[ind * 2] + segt[ind * 2 + 1];
}

Matr get(int ind, int l, int r, int L, int R)
{
	if (r < L || R < l)
		return Matr();
	if (L <= l && r <= R)
		return segt[ind];
	push(ind);
	int mid = (l + r) / 2;
	return get(ind * 2, l, mid, L, R) +
		get(ind * 2 + 1, mid + 1, r, L, R);
}

Matr fibo(int num)
{
	return bpow(F, num);
}

int n, m;

void solve()
{
	E.a[0][0] = E.a[1][1] = 1;
	F.a[0][1] = F.a[1][0] = F.a[1][1] = 1;
	scanf("%d%d", &n, &m);
	build(1, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		int a;
		scanf("%d", &a);
		mul(1, 0, n - 1, i, i, fibo(a));
	}
	for (int i = 0; i < m; ++i)
	{
		int t, l, r;
		scanf("%d%d%d", &t, &l, &r);
		--l, --r;
		switch (t)
		{
		case 1:
			int x;
			scanf("%d", &x);
			mul(1, 0, n - 1, l, r, fibo(x));
			break;
		case 2:
			printf("%d\n", get(1, 0, n - 1, l, r).a[1][0]);
			break;
		default:
			throw;
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("alter.in", "r", stdin);
	//freopen("alter.out", "w", stdout);
#endif

#ifdef STRESS
	while (true)
#endif
#ifdef MULTITEST
		int t;
	scanf("%d", &t);
	while (t--)
#endif
		solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
#endif
}