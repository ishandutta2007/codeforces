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

#ifdef LOCAL
#define lll ll
#else
#define lll __int128
#endif

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

const int P = 1e6 + 3;
int sum(int a, int b)
{
	a += b;
	return a >= P ? a - P : a;
}
int sub(int a, int b)
{
	return sum(a, P - b);
}
int mul(int a, int b)
{
	return (ll) a * b % P;
}
int bpow(int x, ll p)
{
	int res = 1;
	for (; p > 0; p /= 2, x = mul(x, x))
		if (p % 2 == 1)
			res = mul(res, x);
	return res;
}

ll n, k;
int a, b;

void solve()
{
	cin >> n >> k;
	ll tk = k - 1;
	for (int i = 0; i < n && tk > 0; ++i)
		tk /= 2;
	if (tk > 0)
	{
		puts("1 1");
		return;
	}
	ll p2 = n;
	ll p2d = (n % (P - 1)) * (k % (P - 1)) % (P - 1);
	for (ll x = 2; x < k; x <<= 1)
		p2 += (k - 1) / x;
	p2 %= P - 1;
	p2d -= p2;
	if (p2d < 0)
		p2d += P - 1;
	b = bpow(2, p2d);
	a = bpow(bpow(2, n), k);
	if (k < P)
	{
		int kek = 1;
		auto p2n = bpow(2, n);
		for (int i = 0; i < k; ++i)
			kek = mul(kek, sub(p2n, i));
		a = sub(a, kek);
	}
	a = mul(a, bpow(2, p2 * (P - 2)));
	printf("%d %d", a, b);
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
	fprintf(stderr, "\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
#endif
}