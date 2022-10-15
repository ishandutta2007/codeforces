#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int n; cin >> n;

    vector<int> s(n);
    for (auto& x : s) cin >> x;

    sort(rall(s));

    int m; cin >> m;

    vector<int> popcount(1 << m, 0);

    for (int mask = 1; mask < (1 << m); ++mask)
    {
        int msb = mask & (mask - 1);
        popcount[mask] = 1 + popcount[msb];
    }

    enum Action { pick, ban };

    vector<int> team(m + 1, -1);
    vector<Action> action(m + 1);

    for (int j = 0; j < m; ++j)
    {
        char c; cin >> c;
        action[j] = c == 'p' ? pick : ban;
        cin >> team[j]; --team[j];
    }

    reverse(all(team)), reverse(all(action));

    vector<int> dp(1 << m, -INF);

    dp[0] = 0;

    for (int mask = 1; mask < (1 << m); ++mask)
    {
        int w = popcount[mask];
        int sgn = (team[w] == team[w - 1]) ? +1 : -1;

        for (int j = 0; j < m; ++j) if (mask >> j & 1)
        {
            int add = s[j] * (action[w] == pick);
            dp[mask] = max(dp[mask], sgn * dp[mask ^ (1 << j)] + add);
        }
    }

    int ans = dp.back() * (team[m] == 0 ? +1 : -1);

    cout << ans << endl;

    exit(0);
}