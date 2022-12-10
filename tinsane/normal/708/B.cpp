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

int a00, a11, a01, a10;

void solve()
{
	scanf("%d%d%d%d", &a00, &a01, &a10, &a11);
	int m = sqrt(a00 * 2) + 1;
	int n = sqrt(a11 * 2) + 1;
	if (n * (n - 1) / 2 != a11 || m * (m - 1) / 2 != a00)
	{
		puts("Impossible");
		return;
	}
	if (a10 + a01 == 0)
	{
		if (a00 == 0)
			for (int i = 0; i < n; ++i)
				printf("1");
		else if (a11 == 0)
			for (int i = 0; i < m; ++i)
				printf("0");
		else
			puts("Impossible");
		return;
	}
	if (a10 + a01 != (ll) n * m)
	{
		puts("Impossible");
		return;
	}
	if (a01 == 0)
	{
		for (int i = 0; i < n; ++i)
			printf("1");
		for (int i = 0; i < m; ++i)
			printf("0");
		return;
	}
	for (; a10 >= m; a10 -= m, --n)
		printf("1");
	for (int i = a10; i < m; ++i)
		printf("0");
	printf("1");
	--n;
	for (int i = 0; i < a10; ++i)
		printf("0");
	for (int i = 0; i < n; ++i)
		printf("1");
	puts("");
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