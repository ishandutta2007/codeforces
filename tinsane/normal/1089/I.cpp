#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define dbg(...) fprintf(stderr, __VA_ARGS__)
#define dbgv(x) cerr << #x << " = " << x << endl
#define dbga(arr, len) {cerr << #arr << " = "; for (int _ = 0; _ < len; _++)\
cerr << arr[_] << " "; cerr << endl;}
#define dbgi(it) {cerr << #it << " = "; for (const auto& _ : it)\
cerr << _ << " "; cerr << endl;}
#else
#define dbg(...) (void)0
#define dbgv(x) (void)0
#define dbga(arr, len) (void)0
#define dbgi(it) (void)0
#endif

using ll = long long;
using dbl = long double;
using pii = pair<int, int>;


int MOD;
void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD) a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
void ssub(int &a, int b)
{
    a -= b;
    if (a < 0) a += MOD;
}
int sub(int a, int b)
{
    ssub(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}

const int N = 405;
int dp[N][N];
int fact[N];
int ans[N];
int splitPref[N];

void calcDp()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
        fact[i] = mul(fact[i - 1], i);
    for (int n = 1; n < N; n++)
    {
        for (int k = 1; k < n; k++)
        {
            int cur = sub(fact[k], splitPref[k]);
            cur = mul(cur, fact[n - k]);
            sadd(splitPref[n], cur);
        }
    }
    dp[0][0] = 1;
    for (int pos = 0; pos < N; pos++)
        for (int cnt = 0; cnt <= pos; cnt++)
        {
            int cur = dp[pos][cnt];
            for (int k = 1; k + pos < N; k++)
                sadd(dp[pos + k][cnt + 1], mul(cur, fact[k]));
        }
    for (int k = 1; k < N; k++)
    {
        ans[k] = fact[k];
        for (int t = 3; t < k; t++)
            ssub(ans[k], mul(dp[k][t], ans[t]));
        ssub(ans[k], mul(2,splitPref[k]));
        if (k < 12)
            dbg("k = %d, ans = %d\n", k, ans[k]);
    }
}

void solve() {
    int t;
    scanf("%d%d", &t, &MOD);
    calcDp();
    ans[2] = 2;
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    dbg("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}