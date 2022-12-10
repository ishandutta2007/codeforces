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
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#pragma region TypeDefs

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#pragma endregion

const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const ld PI = acos(-1);
const ld eps = 1e-8;
const ld EPS = 1e-12;

struct Line
{
	ll a, b;
	ll y(ll x) { return a * x + b; }
	Line(ll a, ll b) : a(a), b(b) {}
};

const int N = 2e5 + 10;
ll a[N], ans, best, psum[N];
int n;
vector<Line> hull;

bool is_bad(Line a, Line b, Line c)
{
	return (b.b - c.b) * (b.a - a.a) <= (a.b - b.b) * (c.a - b.a);
}

void add_line(Line line)
{
	hull.push_back(line);
	while (hull.size() > 2 && is_bad(hull[hull.size() - 3], hull[hull.size() - 2], hull[hull.size() - 1]))
	{
		hull[hull.size() - 2] = hull.back();
		hull.pop_back();
	}
}

ll query(ll x)
{
	int l = -1, r = hull.size() - 1;
	while (r - l > 1)
	{
		int m = (l + r) / 2;
		if (hull[m].y(x) <= hull[m + 1].y(x))
			l = m;
		else
			r = m;
	}
	return hull[r].y(x);
}

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		ans += a[i] * (i + 1);
		psum[i + 1] = psum[i] + a[i];
	}

	for (int r = 1; r < n; ++r)
	{
		add_line(Line(r, -psum[r - 1]));
		best = max(best, query(a[r]) + psum[r] - a[r] * (r + 1));
	}

	hull.clear();
	for (int l = n - 2; l >= 0; --l)
	{
		add_line(Line(-(l + 2), -psum[l + 2]));
		best = max(best, query(-a[l]) + psum[l + 1] - a[l] * (l + 1));
	}

	cout << best + ans;
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
	ios_base::sync_with_stdio(0), cin.tie(0);

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}