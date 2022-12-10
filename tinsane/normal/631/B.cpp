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

const int N = 5e3 + 10;
int n, m, cols[N], rows[N], q, cols_t[N], rows_t[N];

void solve()
{
	cin >> n >> m >> q;
	for (int i = 0; i < q; ++i)
	{
		int type, num, color;
		cin >> type >> num >> color;
		if (type == 1)
		{
			rows[num - 1] = color;
			rows_t[num - 1] = i + 1;
		}
		else
		{
			cols[num - 1] = color;
			cols_t[num - 1] = i + 1;
		}
	}
	for (int i = 0; i < n; ++i, cout << '\n')
		for (int j = 0; j < m; ++j)
			if (cols_t[j] > rows_t[i])
				cout << cols[j] << ' ';
			else
				cout << rows[i] << ' ';
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