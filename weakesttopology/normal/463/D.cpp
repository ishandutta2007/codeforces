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

bool chmax(auto& x, auto y) { return x < y ? x = y, true : false; }

int main()
{ _
    int n, k; cin >> n >> k;

    vector pos(k, vector(n, 0));

    for (int j = 0; j < k; ++j)
        for (int i = 0; i < n; ++i)
        {
            int p; cin >> p; --p;
            pos[j][p] = i;
        }

    vector E(n, vector(0, 0));

    vector indeg(n, 0);

    for (int x = 0; x < n; ++x)
        for (int y = 0; y < n; ++y)
        {
            bool good = true;
            for (int j = 0; j < k; ++j)
                good = good && pos[j][x] < pos[j][y];

            if (good)
            {
                E[x].push_back(y);
                ++indeg[y];
            }
        }

    queue<int> q;

    for (int x = 0; x < n; ++x) if (indeg[x] == 0) q.push(x);

    vector topo(0, 0);

    while (not empty(q))
    {
        int x = q.front(); q.pop();
        topo.push_back(x);
        for (auto y : E[x]) if (--indeg[y] == 0) q.push(y);
    }

    reverse(all(topo));

    vector dp(n, 1);

    for (auto x : topo) for (auto y : E[x]) chmax(dp[x], 1 + dp[y]);

    int ans = *max_element(all(dp));

    cout << ans << endl;

    exit(0);
}