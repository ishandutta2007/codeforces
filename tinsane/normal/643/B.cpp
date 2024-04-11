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
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

int n, k;
int a, b, c, d;

void solve()
{
	scanf("%d%d", &n, &k);
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if (k == n - 1 || k == n || n == 4)
	{
		printf("-1");
		return;
	}
	printf("%d %d ", a, c);
	for (int i = 1; i <= n; ++i)
		if (i != a && i != b && i != c && i != d)
			printf("%d ", i);
	printf("%d %d\n", d, b);
	printf("%d %d ", c, a);
	for (int i = 1; i <= n; ++i)
		if (i != a && i != b && i != c && i != d)
			printf("%d ", i);
	printf("%d %d\n", b, d);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("chocolate.in", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}