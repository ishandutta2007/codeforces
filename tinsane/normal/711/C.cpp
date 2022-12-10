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

const int N = 111;
int n, m, k;
int c[N];
int p[N][N];
ll dp[N][N][N];

void relax(ll& a, ll b)
{
	a = min(a, b);
}

void solve()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &c[i]);
	for (int i = 0; i < n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &p[i][j]);
	fill(&dp[0][0][0], &dp[N][0][0], LINF);
	if (c[0] != 0)
		dp[0][1][c[0]] = 0;
	else
		for (int i = 1; i <= m; ++i)
			dp[0][1][i] = p[0][i];
	for (int i = 0; i + 1 < n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= m; ++k)
			{
				if (dp[i][j][k] == LINF)
					continue;
				if (c[i + 1] != 0)
					relax(dp[i + 1][j + (c[i + 1] != k)][c[i + 1]], dp[i][j][k]);
				else
					for (int k1 = 1; k1 <= m; ++k1)
						relax(dp[i + 1][j + (k1 != k)][k1], dp[i][j][k] + p[i + 1][k1]);
			}
	ll ans = LINF;
	for (int i = 1; i <= m; ++i)
		ans = min(ans, dp[n - 1][k][i]);
	printf("%I64d\n", (ans == LINF ? -1LL : ans));
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