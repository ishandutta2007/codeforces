#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll median(ll a, ll b, ll c, ll d)
{
    ll x[4] = { a, b, c, d };
    sort(all(x));
    return x[1];
}

ll solve()
{
    int n, m; cin >> n >> m;
    vector a(n, vector(m, 0LL));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) cin >> a[i][j];

    ll ans = 0;

    for (int i = 0; i < n / 2; ++i)
        for (int j = 0; j < m / 2; ++j)
        {
            ll *x[4] = { &a[i][j], &a[i][m - 1 - j], &a[n - 1 - i][j], &a[n - 1 - i][m - 1 - j] };
            ll med = median(*x[0], *x[1], *x[2], *x[3]);
            for (int t = 0; t < 4; ++t)
            {
                ans += abs(*x[t] - med);
                *x[t] = med;
            }
        }

    if (n & 1)
    {
        for (int j = 0; j < m / 2; ++j)
        {
            ll *x[2] { &a[n / 2][j], &a[n / 2][m - 1 - j] };
            ll med = median(0, *x[0], *x[1], LINF);
            for (int t = 0; t < 2; ++t)
            {
                ans += abs(*x[t] - med);
                *x[t] = med;
            }
        }
    }

    if (m & 1)
    {
        for (int i = 0; i < n / 2; ++i)
        {
            ll *x[2] { &a[i][m / 2], &a[n - 1 - i][m / 2] };
            ll med = median(0, *x[0], *x[1], LINF);
            for (int t = 0; t < 2; ++t)
            {
                ans += abs(*x[t] - med);
                *x[t] = med;
            }
        }
    }

    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < m; ++j) cout << a[i][j] << " ";
    //     cout << endl;
    // }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}