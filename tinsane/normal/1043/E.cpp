#include <bits/stdc++.h>
#ifdef LOCAL
#include "template.h"
#endif

using namespace std;
#ifndef LOCAL
#define dbg(...) (void)0
#define ARR(arr, ...) (void)0
#define eprintf(...) (void)0
#endif

#define mp make_pair
#define rand govno_ebanoe
#define dbg_time() eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC)

using ll = long long;
using pii = pair<int, int>;
using dbl = double;

struct Guy {
    int x, y;
    int id;
    Guy() = default;
    Guy(int _x, int _y, int _id) : x(_x), y(_y), id(_id) {}
    bool operator< (const Guy& g) const {
        return y - x < g.y - g.x;
    }
};

const int N = 3e5 + 10;
int n, m;
vector<pii> out;
Guy guys[N];
ll ans[N];
int xs[N], ys[N];

void solve()
{
    scanf("%d%d", &n, &m);
    ll sx = 0;
    for(int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        guys[i] = Guy(x, y, i);
        xs[i] = x;
        ys[i] = y;
        sx += xs[i];
    }
    sort(guys, guys + n);

    ll sd = 0;
    for(int i = 0; i < n; ++i) {
        auto g = guys[i].id;
        ans[g] = guys[i].x * 1LL * (n - 2) + sx;
        ans[g] += sd;
        ans[g] += (guys[i].y - guys[i].x) * 1LL * (n - i - 1);
        sd += guys[i].y - guys[i].x;
    }
    dbg(ARR(ans, n));

    for(int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        auto v = min(xs[a] + ys[b], xs[b] + ys[a]);
        ans[a] -= v; 
        ans[b] -= v;
    }
    for(int i = 0; i < n; ++i)
        printf("%lld ", ans[i]);
    puts("");
}

#ifdef LOCAL
#define ERR_CATCH
//#define NOERR
#endif

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#ifdef NOERR
	freopen("err.txt", "w", stderr);
#endif
#else
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

#ifdef ERR_CATCH
	try
	{
#endif

#ifdef ST
		ios_base::sync_with_stdio(false);
		while (true)
			solve();
#endif

#ifdef CASES
#define MULTITEST
#endif

#ifdef MULTITEST
		int t;
		scanf("%d", &t);
		char endl1[5];
		fgets(endl1, 5, stdin);
		for (int i = 0; i < t; ++i)
		{
#ifdef CASES
			printf("Case #%d: ", i + 1);
#endif
			solve();
#ifdef CASES
			eprintf("Passed case #%d:\n", i + 1);
#endif
		}
#else
		solve();
#endif

#ifdef ERR_CATCH
	}
	catch (logic_error e)
	{
		dbg(e.what());
		puts("___________________________________________________________________________");
		exit(0);
	}
#endif
	dbg_time();
}