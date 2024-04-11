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
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-12;

#pragma endregion

const int N = 1e3 + 10;
int n, m, K;
string s, t;
int dp[N][N][12][2];
const int OPEN = 1;
const int CLOSE = 0;

void relax(int& a, int b)
{
	a = max(a, b);
}

void update(int i, int j, int k)
{
	if (i < n && j < m && s[i] == t[j])
		relax(dp[i + 1][j + 1][k][OPEN], dp[i][j][k][CLOSE] + 1);
	relax(dp[i + 1][j][k][CLOSE], dp[i][j][k][CLOSE]);
	relax(dp[i][j + 1][k][CLOSE], dp[i][j][k][CLOSE]);

	relax(dp[i][j][k + 1][CLOSE], dp[i][j][k][OPEN]);
	if (i < n && j < m && s[i] == t[j])
		relax(dp[i + 1][j + 1][k][OPEN], dp[i][j][k][OPEN] + 1);
}

void solve()
{
	cin >> n >> m >> K >> s >> t;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			for (int k = 0; k <= K; ++k)
				update(i, j, k);
	printf("%d", dp[n][m][K][0]);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("chocolate.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
	return 0;
}