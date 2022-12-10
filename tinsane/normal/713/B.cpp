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

#define y1 wefpiewjfipewjfewifj
#define y2 wwfpiewjfipewjfewifj
int n;
int ax1 = -1, ax2 = -1, ay1, ay2;
int cnt;

int get(int x1, int x2, int y1, int y2)
{
	if (++cnt >= 200)
		throw;
	cout << '?' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	int res;
	cin >> res;
	if (x1 <= ax1 && ax2 <= x2 && y1 <= ay1 && ay2 <= y2)
		--res;
	return res;
}

void solve()
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	int lx = 1, rx = n, ly = 1, ry = n;
	int sh = (1 << 20);
	for (sh = 1 << 20; sh > 0; sh >>= 1)
		if (lx + sh <= rx && get(lx, rx - sh, ly, ry))
			rx -= sh;
	for (sh = 1 << 20; sh > 0; sh >>= 1)
		if (sh + lx <= rx && get(lx + sh, rx, ly, ry))
			lx += sh;
	for (sh = 1 << 20; sh > 0; sh >>= 1)
		if (ly + sh <= ry && get(lx, rx, ly, ry - sh))
			ry -= sh;
	for (sh = 1 << 20; sh > 0; sh >>= 1)
		if (sh + ly <= ry && get(lx, rx, ly + sh, ry))
			ly += sh;
	ax1 = lx;
	ax2 = rx;
	ay1 = ly;
	ay2 = ry;
	lx = 1, rx = n, ly = 1, ry = n;
	for (sh = 1 << 20; sh > 0; sh >>= 1)
		if (lx + sh <= rx && get(lx, rx - sh, ly, ry))
			rx -= sh;
	for (sh = 1 << 20; sh > 0; sh >>= 1)
		if (sh + lx <= rx && get(lx + sh, rx, ly, ry))
			lx += sh;
	for (sh = 1 << 20; sh > 0; sh >>= 1)
		if (ly + sh <= ry && get(lx, rx, ly, ry - sh))
			ry -= sh;
	for (sh = 1 << 20; sh > 0; sh >>= 1)
		if (sh + ly <= ry && get(lx, rx, ly + sh, ry))
			ly += sh;
	cout << "! " << ax1 << ' ' << ay1 << ' ' << ax2 << ' ' << ay2 << ' ' << lx << ' ' << ly << ' ' << rx << ' ' << ry << endl;
}

int main()
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("alter.in", "r", stdin);
	//freopen("alter.out", "w", stdout);
#endif

#ifdef STRESS
	while (true)
#endif
#ifdef MULTITEST
		int t;
	scanf("%d", &t);
	while (t--)
#endif
		solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
#endif
}