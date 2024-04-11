#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;
using ld = long double;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

const ld EPS = 1e-6;

ld solve()
{
    int n, m; cin >> n >> m;

    int badprefix = -1;

    for (int i = 0; i < n; ++i)
    {
        int a; cin >> a; --a;
        if (a != i) badprefix = i;
    }

    ld ans = 1.0;

    for (int j = 0; j < m; ++j)
    {
        int r; cin >> r;

        ld p; cin >> p;

        if (r > badprefix) ans *= 1.0 - p;
    }

    if (badprefix == -1) return 1.0;

    ans = 1.0 - ans;

    return ans;
}

int main()
{ _
    int t; cin >> t;

    cout << setprecision(20) << fixed;

    while (t--) cout << solve() << endl;

    exit(0);
}