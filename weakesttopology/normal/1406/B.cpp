#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

ll solve()
{
    int n; cin >> n;

    vector a(n, 0LL);
    for (int i = 0; i < n; ++i) cin >> a[i];

    const int m = 5;

    vector dpmax(n, vector(m, -LINF));
    vector dpmin(n, vector(m, LINF));
    dpmax[0][0] = dpmin[0][0] = a[0];

    auto chmax = [](ll& x, ll y){ x = max(x, y); };
    auto chmin = [](ll& x, ll y){ x = min(x, y); };

    for (int i = 1; i < n; ++i)
    {
        dpmax[i][0] = max(dpmax[i - 1][0], a[i]);
        dpmin[i][0] = min(dpmin[i - 1][0], a[i]);

        for (int j = 1; j <= min(i, m - 1); ++j)
        {
            chmax(dpmax[i][j], dpmin[i - 1][j - 1] * a[i]);
            chmax(dpmax[i][j], dpmax[i - 1][j - 1] * a[i]);
            chmax(dpmax[i][j], dpmax[i - 1][j]);

            chmin(dpmin[i][j], dpmin[i - 1][j - 1] * a[i]);
            chmin(dpmin[i][j], dpmax[i - 1][j - 1] * a[i]);
            chmin(dpmin[i][j], dpmin[i - 1][j]);
        }
    }

    return dpmax[n - 1][m - 1];
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}