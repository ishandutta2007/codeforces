#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
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
#pragma comment(linker, "/STACK:167772160")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

int n, d, h;

void solve()
{
	cin >> n >> d >> h;
	if (2 * h < d || (h == d && d == 1 && n != 2))
	{
		cout << -1;
		return;
	}
	int now = 2;
	for (int i = 0; i < d - h; ++i, ++now)
		cout << now << ' ' << now - 1 << '\n';
	cout << now << ' ' << 1 << '\n';
	++now;
	for (int i = 1; i < h; ++i, ++now)
		cout << now << ' ' << now - 1 << '\n';
	int last = now - 2;
	if (h == 1)
		last = 1;
	for (; now <= n; ++now)
		cout << now << ' ' << last << '\n';
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("sequence.in", "r", stdin);
	//freopen("sequence.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0);

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}