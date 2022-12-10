#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

using ll = long long;
using pii = pair<int, int>;



void solve()
{
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int ix = min(x1, x2 - 1), ax = max(x1, x2 + 1), iy = min(y1, y2 - 1), ay = max(y1, y2 + 1);
	cout << 2 * ((ax - ix) + (ay - iy)) << endl;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif

	solve();

	eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}