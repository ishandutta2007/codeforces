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

const int N = 1e5 + 10;
int n, k, piles[N];

int mex(int x)
{
	if (k)
	{
		if (x == 1 || x == 3)
			return 1;
		if ((x == 2) || (x & 1))
			return 0;
		if (x == 4)
			return 2;
		if (mex(x / 2) != 1)
			return 1;
		else
			return 2;
	}
	else
	{
		if (x == 2)
			return 2;
		if (x == 1)
			return 1;
		return 1 - (x & 1);
	}
}

void solve()
{
	cin >> n >> k;
	k &= 1;
	for (int i(0); i < n; ++i)
		cin >> piles[i];
	int res = 0;
	for (int i(0); i < n; ++i)
		res ^= mex(piles[i]);
	if (res)
		cout << "Kevin";
	else
		cout << "Nicky";
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