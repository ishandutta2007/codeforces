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
int n, x[N], y[N];
string s;

void solve()
{
	cin >> n >> s;
	for (int i(0); i < n; ++i)
	{
		x[i + 1] = x[i];
		y[i + 1] = y[i];
		if (s[i] == 'U')
			++y[i + 1];
		else if (s[i] == 'D')
			--y[i + 1];
		else if (s[i] == 'L')
			--x[i + 1];
		else
			++x[i + 1];
	}
	int ans = 0;
	for (int i(0); i <= n; ++i)
		for (int j(i + 1); j <= n; ++j)
			ans += (x[i] == x[j]) && (y[i] == y[j]);
	cout << ans;
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