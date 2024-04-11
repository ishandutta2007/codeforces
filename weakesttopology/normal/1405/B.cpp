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

    ll ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        if (a[i] > 0) a[i + 1] += a[i];
        else
        {
            ans -= a[i];
            a.back() += a[i];
        }
    }
    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}