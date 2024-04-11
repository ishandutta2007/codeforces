#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int n; cin >> n;

    vector<int> a(n);

    for (auto& x : a)
    {
        cin >> x;

        int sq = 1;

        for (int y = 2; y * y <= abs(x); ++y)
        {
            if (x % (y * y) == 0) sq = y * y;
        }

        x /= sq;
    }

    auto values = a;
    sort(all(values)), values.erase(unique(all(values)), end(values));

    for (auto& x : a)
    {
        auto iter = lower_bound(all(values), x);
        x = (int)distance(begin(values), iter);
    }

    int m = size(values);

    vector<int> ans(n + 1, 0), vis(m, 0);

    for (int l = 0; l < n; ++l)
    {
        int k = 0;

        bool zero = false;

        for (int r = l; r < n; ++r)
        {
            if (vis[a[r]]++ == 0) ++k;
            if (values[a[r]] == 0) zero = true;

            ans[max(k - zero, 1)] += 1;
        }

        fill(all(vis), 0);
    }

    for (int k = 1; k <= n; ++k) cout << ans[k] << "\n "[k < n];

    exit(0);
}