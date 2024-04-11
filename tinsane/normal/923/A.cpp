#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x) cerr << #x << " = " << x << endl
#define dbga(arr, len) {cerr << #arr << " = "; for (int _ = 0; _ < len; _++) cerr << arr[_] << " "; cerr << endl;}
#define dbgi(it) {cerr << #it << " = "; for (const auto &_ : it) cerr << _ << " "; cerr << endl;}
#else
#define dbg(...) (void)0
#define dbgv(x) (void)0
#define dbga(arr, len) (void)0
#define dbgi(it) (void)0
#endif

using ll = long long;
using dbl = long double;
using pii = pair<int, int>;

const int N = 1000500;
const int MIN_X = 3;

vector<int> primes[N];

void solve()
{
    for (int i = 2; i < N; i++)
    {
        if (!primes[i].empty())
            continue;
        primes[i].push_back(i);
        for (int j = i + i; j < N; j += i)
            primes[j].push_back(i);
    }

    int x2;
    scanf("%d", &x2);
    int res = x2;

    for (int x1 = MIN_X; x1 <= x2; x1++)
    {
        bool can_reach_x2 = false;
        for (int p : primes[x2])
            can_reach_x2 |= p < x1 && x2 - x1 < p;
        if (!can_reach_x2)
            continue;

        for (int p : primes[x1])
        {
            int x0 = max(MIN_X, x1 - p + 1);
            if (p < x0)
                res = min(res, x0);
        }
    }

    printf("%d\n", res);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}