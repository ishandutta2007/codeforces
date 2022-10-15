#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

ll solve()
{
    int n, q; cin >> n >> q;
    vector a(n, 0LL);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector dpmin(n, LINF), dpmax(n, -LINF);

    dpmax[0] = a[0];

    for (int i = 1; i < n; ++i)
    {
        dpmin[i] = min(dpmin[i - 1], a[i] - dpmax[i - 1]);
        dpmax[i] = max({ dpmax[i - 1], a[i], a[i] - dpmin[i - 1] });
    }

    return dpmax[n - 1];
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}