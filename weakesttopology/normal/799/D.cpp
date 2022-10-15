#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define rall(X) rbegin(X), rend(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

bool chmax(auto& x, auto y) { return x < y ? x = y, true : false; }

int main()
{ _
    int a, b, h, w, n; cin >> a >> b >> h >> w >> n;

    vector ext(n + 1, 1);
    for (int i = 0; i < n; ++i) cin >> ext[i];

    sort(rall(ext));
    ext.resize(min(size(ext), 40));

    constexpr int N = 1e5;

    array<int, N + 1> dp;

    fill(all(dp), -1), fill(all(dp), -1);

    dp[h] = w, dp[w] = h;

    int ans = -1;

    for (int ct = 0, t = 0; ct < size(ext) && ans == -1; ++ct, t ^= 1)
    {
        for (int x = 1; x <= N; ++x)
            if ((x >= a && dp[x] >= b) || (x >= b && dp[x] >= a))
            {
                ans = ct;
                break;
            }

        int y = ext[ct];

        for (int x = N; x > 0; --x)
        {
            chmax(dp[(int)min(ll(N), ll(y) * x)], dp[x]);
            chmax(dp[x], (int)min(ll(N), ll(dp[x]) * y));
        }
    }

    cout << ans << endl;

    exit(0);
}