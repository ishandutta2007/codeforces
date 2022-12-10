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
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-13;

#pragma endregion

const int P = 1e9 + 7;

int sum(int a, int b)
{
	a += b;
	if (a >= P)
		return a - P;
	return a;
}

int mul(int a, int b)
{
	return (ll) a * b % P;
}
int n;
int a = 0, b = 1, c = 2, d = 1;
int p2 = 2;

void mbpow(ll p)
{
	int ra = 1, rb = 0, rc = 0, rd = 1;
	for (; p > 0; p /= 2)
	{
		if (p % 2 == 1)
		{
			int tra = ra, trb = rb, trc = rc, trd = rd;
			ra = sum(mul(tra, a), mul(trc, b));
			rb = sum(mul(trb, a), mul(trd, b));
			rc = sum(mul(tra, c), mul(trc, d));
			rd = sum(mul(trb, c), mul(trd, d));
		}
		int ta = a, tb = b, tc = c, td = d;
		a = sum(mul(ta, ta), mul(tb, tc));
		b = sum(mul(ta, tb), mul(tb, td));
		c = sum(mul(ta, tc), mul(tc, td));
		d = sum(mul(tb, tc), mul(td, td));
	}
	a = ra;
	b = rb;
	c = rc;
	d = rd;
}

int bpow(int x, ll p)
{
	int res = 1;
	for (; p > 0; p /= 2, x = mul(x, x))
		if (p % 2 == 1)
			res = mul(res, x);
	return res;
}

void solve()
{
	scanf("%d", &n);
	bool ok = false;
	for (int i = 0; i < n; ++i)
	{
		ll p;
		scanf("%I64d", &p);
		p2 = bpow(p2, p);
		mbpow(p);
	}
	p2 = mul(p2, (P + 1) / 2);
	printf("%d/%d", (p2 - b + P) % P, p2);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("bandits.in", "r", stdin);
	//freopen("bandits.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
}