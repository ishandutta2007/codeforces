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

const ll INF = (ll)1e18;

ll f, t, t0;
ll a1, t1, p1;
ll a2, t2, p2;
ll best;

void relax(ll x, ll y)
{
	if (x < 0 || y < 0)
		return;
	ll delta = max(0LL, f - a1 * x - a2 * y);
	ll wasted = 0;
	ll need = f;
	if (a1 * x > need)
		wasted += t1 * need;
	else
	{
		wasted += t1 * a1 * x;
		need -= a1 * x;
		if (a2 * y > need)
			wasted += t2 * need;
		else
		{
			wasted += t2 * a2 * y;
			need -= a2 * y;
			wasted += t0 * need;
		}
	}
	if (wasted > t)
		return;
	best = min(best, p1 * x + p2 * y);
}

ll cdiv(ll a, ll b)
{
	return (a + b - 1) / b;
}

void solve()
{
	cin >> f >> t >> t0;
	cin >> a1 >> t1 >> p1;
	cin >> a2 >> t2 >> p2;

	best = INF;

	for (int it = 0; it < 2; it++)
	{
		for (ll x = 0; a1 * (x - 1) <= f; x++)
		{
			relax(x, 0);
			if (t2 < t0)
			{
				ll y0 = cdiv(t - t0 * f - x * a1 * (t1 - t0), a2 * (t2 - t0));
				relax(x, y0 - 1);
				relax(x, y0);
				relax(x, y0 + 1);
			}
		}

		swap(a1, a2);
		swap(t1, t2);
		swap(p1, p2);
	}

	if (best == INF)
		best = -1;
	cout << best << endl;
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