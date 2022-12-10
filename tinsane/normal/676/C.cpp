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
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-12;

const int N = 1e5 + 10;
int n, k;
char str[N];
int a[N], b[N], asi, bsi;
int ans = 0;

void solve()
{
	scanf("%d%d%s", &n, &k, str);
	for (int i = 0; i < n; ++i)
		if (str[i] == 'a')
			a[asi++] = i;
		else
			b[bsi++] = i;
	if (bsi <= k || asi <= k)
	{
		printf("%d", n);
		return;
	}
	for (int i = 0; i + k <= asi; ++i)
	{
		int l = i ? a[i - 1] + 1 : 0;
		int r = i + k < asi ? a[i + k] - 1 : n - 1;
		ans = max(ans, r - l + 1);
	}
	for (int i = 0; i + k <= bsi; ++i)
	{
		int l = i ? b[i - 1] + 1 : 0;
		int r = i + k < bsi ? b[i + k] - 1 : n - 1;
		ans = max(ans, r - l + 1);
	}
	printf("%d", ans);
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
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
	return 0;
}