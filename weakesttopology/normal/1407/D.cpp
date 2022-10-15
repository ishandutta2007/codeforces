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

int main()
{ _
    int n; cin >> n;
    vector h(n, 0);
    for (int i = 0; i < n; ++i) cin >> h[i];

    stack<int> up, down; up.push(n - 1), down.push(n - 1);

    vector dp(n, INF); dp[n - 1] = 0;

    auto chmin = [](int& x, int y) { x = min(x, y); };

    for (int i = n - 2; i >= 0; --i)
    {
        if (h[i] == h[i + 1])
        {
            dp[i] = dp[i + 1] + 1;

            up.pop(), down.pop();
        }

        else if (h[i] > h[i + 1])
        {
            while (not up.empty() && h[i] > h[up.top()])
                chmin(dp[i], dp[up.top()] + 1), up.pop();

            if (not up.empty())
            {
                chmin(dp[i], dp[up.top()] + 1);
                if (h[i] == h[up.top()]) up.pop();
            }

            while (not down.empty() && h[i] <= h[down.top()]) down.pop();
        }

        else
        {
            while (not down.empty() && h[i] < h[down.top()])
                chmin(dp[i], dp[down.top()] + 1), down.pop();

            if (not down.empty())
            {
                chmin(dp[i], dp[down.top()] + 1);
                if (h[i] == h[down.top()]) down.pop();
            }

            while (not up.empty() && h[i] >= h[up.top()]) up.pop();
        }

        up.push(i), down.push(i);
    }

    int ans = dp[0];

    cout << ans << endl;

    exit(0);
}