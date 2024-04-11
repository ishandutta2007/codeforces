#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;

const ll MOD = (ll)1e9 + 7;
const int N = 4000;
const ll BASE = (ll)1e9;
ll p;
ll m;
ll a[N];
int n;
ll dp[2][N][2][2];

ll add(ll x, ll y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
ll sub(ll x, ll y)
{
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}
ll mult(ll x, ll y)
{
    return (x * y) % MOD;
}

ll getNum(string s)
{
    ll res = 0;
    for (int i = 0; i < (int)s.length(); i++)
        res = res * 10 + (ll)(s[i] - '0');
    return res;
}

struct Num
{
    vector<ll> x;

    Num() : x() {}
    Num(ll g)
    {
        x.clear();
        x.push_back(g);
    }

    void scan()
    {
        string s;
        cin >> s;
        int len = (int)s.length();
        x.clear();
        for (int idx = len - 9; idx >= 0; idx -= 9)
            x.push_back(getNum(s.substr(idx, 9)));
        if (len % 9 != 0)
            x.push_back(getNum(s.substr(0, len % 9)));
    }

    pair<Num, ll> divide(ll q)
    {
        Num R = Num();
        ll d = 0;
        for (int i = (int)x.size() - 1; i >= 0; i--)
        {
            d = d * BASE + x[i];
            R.x.push_back(d / q);
            d %= q;
        }
        reverse(R.x.begin(), R.x.end());
        while(!R.x.empty() && R.x.back() == 0) R.x.pop_back();
        return make_pair(R, d);
    }
};

void read()
{
    cin >> p >> m;
    n = 0;
    Num A = Num();
    A.scan();
    while(!A.x.empty())
    {
        pair<Num, ll> tmp = A.divide(p);
        A = tmp.first;
        a[n++] = tmp.second;
        if (n == N) throw;
    }
    return;
}

ll calc(ll l, ll r, ll k, ll b)
{
    if (l > r) return 0;
    return add(mult(b, r - l + 1), mult(k, ((r - l + 1) * (r + l) / 2) % MOD));
}

ll countWays(ll x, int l1, int l2, int r1, int r2)
{
    ll L1, L2;
    if (r2 == 0)
    {
        L1 = 0;
        L2 = x;
        if (l2 == 1)
            L2--;
    }
    else
    {
        L1 = x + 1;
        L2 = p - 1;
        if (l2 == 1)
            L1--;
    }
    if (r1 == 0)
        return calc(L1, L2, 1, 1 - l1);
    else
        return calc(L1, L2, MOD - 1, p - 1 + l1);
}

void solve(ll x)
{
    for (int i = 0; i < n; i++)
        for (int l1 = 0; l1 < 2; l1++)
            for (int l2 = 0; l2 < 2; l2++)
            {
                if (dp[0][i][l1][l2] == 0) continue;
                for (int r1 = 0; r1 < 2; r1++)
                    for (int r2 = 0; r2 < 2; r2++)
                        dp[1][i + r1][r1][r2] = add(dp[1][i + r1][r1][r2], mult(dp[0][i][l1][l2], countWays(x, l1, l2, r1, r2)));
            }
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();
//  for (int i = n - 1; i >= 0; i--)
//      printf("%d", a[i]);
//  printf("\n");
    if (m > n)
    {
        printf("0\n");
        return 0;
    }
    dp[0][0][0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
            for (int h = 0; h < 2; h++)
                for (int k = 0; k < 2; k++)
                    dp[1][j][h][k] = 0;
        solve(a[i]);
        for (int j = 0; j <= n; j++)
            for (int h = 0; h < 2; h++)
                for (int k = 0; k < 2; k++)
                    dp[0][j][h][k] = dp[1][j][h][k];
    }
    ll ans = 0;
    for (int i = m; i <= n; i++)
        ans = add(ans, dp[0][i][0][0]);
    printf("%lld\n", ans);

    return 0;
}