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

const int N = 510;
int n;
ll a[N][N];
ll s;
int x, y;

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			scanf("%I64d", &a[i][j]);
			if (!a[i][j])
				x = i, y = j;
		}
	if (n == 1)
	{
		puts("1");
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		if (i == x)
			continue;
		for (int j = 0; j < n; ++j)
			s += a[i][j];
		break;
	}
	ll s1 = 0;
	for (int j = 0; j < n; ++j)
		s1 += a[x][j];
	if (s <= s1)
	{
		puts("-1");
		return;
	}
	a[x][y] = s - s1;
	bool ok = true;
	for (int i = 0; i < n; ++i)
	{
		s1 = 0;
		for (int j = 0; j < n; ++j)
			s1 += a[i][j];
		ok &= s1 == s;
	}
	for (int j = 0; j < n; ++j)
	{
		s1 = 0;
		for (int i = 0; i < n; ++i)
			s1 += a[i][j];
		ok &= s1 == s;
	}
	s1 = 0;
	for (int i = 0; i < n; ++i)
		s1 += a[i][i];
	ok &= s1 == s;
	s1 = 0;
	for (int i = 0; i < n; ++i)
		s1 += a[i][n - 1 - i];
	ok &= s1 == s;
	if (ok)
		printf("%I64d\n", a[x][y]);
	else
		puts("-1");
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