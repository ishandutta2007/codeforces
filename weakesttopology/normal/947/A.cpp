#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

auto sieve(int N) {
    vector<int> lp(N + 1, 0), pr;
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) pr.push_back(lp[i] = i);
        for (auto p : pr) {
            if (p > lp[i] || i * p > N) break;
            lp[i * p] = p;
        }
    }
    return pair(lp, pr);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    auto [lp, pr] = sieve(n + 1);

    vector<int> dp(n + 1, 0), dpnxt(n + 1, 0);
    dp[n] = 1;

    auto update = [&](int l, int r, int x) {
        dpnxt[l] += x;
        if (r < n) dpnxt[r + 1] -= x;
    };

    for (int t = 0; t < 2; ++t) {
        for (int x = 3; x <= n; ++x) {
            if (not dp[x] || lp[x] == x) continue;
            for (int y = x; y != 1; y /= lp[y]) {
                update(x - lp[y] + 1, x, 1);
            }
        }
        fill(all(dp), 0), swap(dp, dpnxt);
        for (int x = 1; x <= n; ++x) dp[x] += dp[x - 1];
    }

    int res = 3;
    while (not dp[res]) ++res;

    cout << res << endl;

    exit(0);
}