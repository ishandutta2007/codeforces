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

void chmin(auto& x, auto y){ x = min(x, y); }

ll ceil(ll x, ll D) { return (x + D - 1) / D; }

int main()
{ _
    int n, m;
    cin >> n >> m;

    vector<bool> dp(m + 1, false);
    dp[0] = true;

    vector<int> res(m + 1, -1);
    res[0] = 0;

    const int D = 1e5;

    for (int i = 1; i <= n; ++i)
    {
        int type;
        cin >> type;

        ll x, y;
        cin >> x >> y;

        auto next = [&](ll w){ return type == 1 ? w + ceil(x, D) : ceil(w * x, D); };

        for (ll j = m; j >= type - 1; --j)
        {
            if (not dp[j]) continue;
            for (ll w = next(j), cnt = 1; w <= m && not dp[w] && cnt <= y; w = next(w), cnt += 1)
                dp[w] = true, res[w] = i;
        }
    }

    for (int j = 1; j <= m; ++j) cout << res[j] << "\n "[j < m];

    exit(0);
}