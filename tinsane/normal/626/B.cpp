#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <functional>
#include <unordered_set>
#pragma comment(linker, "/STACK:167772160")

using namespace std;

#ifdef LOCAL
#define eprintf(...) printf(__VA_ARGS__)
#else
#define eprintf(...) ;
#endif

typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

const double PI = 3.1415926535897932384626433;
const int INF = 1e9 + 10;
const ll LINF = 2e18 + 10;
const double eps = 1e-9;
const int P = 1e9 + 7;

const int N = 201;
int n, cnt[3], dp[N][N][N];
string s, res;

int get(int a, int b, int c)
{
	if (dp[a][b][c])
		return dp[a][b][c];
	if (a >= 2)
		dp[a][b][c] |= get(a - 1, b, c);
	if (b >= 2)
		dp[a][b][c] |= get(a, b - 1, c);
	if (c >= 2)
		dp[a][b][c] |= get(a, b, c - 1);
	if (a > 0 && b > 0)
		dp[a][b][c] |= get(a - 1, b - 1, c + 1);
	if (a > 0 && c > 0)
		dp[a][b][c] |= get(a - 1, b + 1, c - 1);
	if (c > 0 && b > 0)
		dp[a][b][c] |= get(a + 1, b - 1, c - 1);
	return dp[a][b][c];
}

void solve()
{
	cin >> n >> s;
	for (auto i : s)
	{
		if (i == 'B')
			++cnt[0];
		else if (i == 'G')
			++cnt[1];
		else
			++cnt[2];
	}
	dp[0][0][0] = -1;
	dp[0][0][1] = 4;
	dp[0][1][0] = 2;
	dp[1][0][0] = 1;
	int res = get(cnt[0], cnt[1], cnt[2]);
	if (res & 1)
		cout << 'B';
	if (res & 2)
		cout << 'G';
	if (res & 4)
		cout << 'R';
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0);

	solve();

	eprintf("\nTime : %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

	return 0;
}