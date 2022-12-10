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

#ifdef LOCAL
#define eprint() debugOutput()
#else
#define eprint() ;
#endif

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const double pi = 2 * atan2(1, 0);
const ld PI = 2 * atan2l(1, 0);
const double eps = 1e-8;
const ld EPS = 1e-12;
void debugOutput();

const int N = 11;
int n, m, al, k;
char orch[N][N];

void solve()
{
	cin >> n >> m >> al >> k;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			orch[i][j] = '.';
	for (int i = 0; i < al; ++i)
	{
		int x, y;
		cin >> x >> y;
		--x, --y;
		orch[x][y] = '*';
	}
	int ans = 0;
	for (int bx = 0; bx < n; ++bx)
		for (int by = 0; by < m; ++by)
			for (int ex = bx + 1; ex <= n; ++ex)
				for (int ey = by + 1; ey <= m; ++ey)
				{
					int cnt = 0;
					for (int i = bx; i < ex; ++i)
						for (int j = by; j < ey; ++j)
							cnt += orch[i][j] == '*';
					ans += (cnt >= k);
				}
	cout << ans;
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
	fprintf(stderr, "\n\nTime: %.3f", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}

void debugOutput()
{}