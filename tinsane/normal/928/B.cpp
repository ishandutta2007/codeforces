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

const int N = 100500;

struct Segment
{
    int l, r;
    Segment(int _l, int _r): l(_l), r(_r) {}
    int len() const
    {
        return max(0, r - l + 1);
    }
    Segment operator&(const Segment& o) const
    {
        return {max(l, o.l), min(r, o.r)};
    }
};

int n, k;
int message[N];
int dp[N];

Segment get_seg(int i)
{
    return {max(0, i - k), min(n - 1, i + k)};
}

void solve()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &message[i]);
        message[i]--;
    }

    for (int i = 0; i < n; i++)
    {
        auto seg = get_seg(i);
        if (message[i] == -1)
            dp[i] = seg.len();
        else
            dp[i] = dp[message[i]] + seg.len() - (get_seg(message[i]) & seg).len();
    }

    for (int i = 0; i < n; i++)
        printf("%d ", dp[i]);
    printf("\n");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}