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

const int n = 5;
int res, w[n], h[n], s[n];

void solve()
{
	for (int i(0); i < n; ++i)
		cin >> w[i];
	for (int i(0); i < n; ++i)
		cin >> h[i];
	for (int i(0); i < n; ++i)
		s[i] = (i + 1) * 500;
	int a, b;
	cin >> a >> b;
	res = 250 * (100 * a - 50 * b);
	for (int i(0); i < n; ++i)
		res += max(75 * s[i], (250 - w[i]) * s[i] - 12500 * h[i]);
	cout << res / 250;
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