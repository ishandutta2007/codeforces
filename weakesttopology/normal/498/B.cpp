#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, T;
    cin >> n >> T;

    vector<double> dp(T + 1, 0), dpnxt(T + 1, 0);
    dp[0] = 1;

    double E = 0;

    for (int i = 0; i < n; ++i) {
        int pr, t;
        cin >> pr >> t;

        double p = pr / 100.0, q = 1 - p, maxed = pow(q, t - 1);

        for (int j = 1; j <= T; ++j) {
            dpnxt[j] = dpnxt[j - 1] * q + dp[j - 1] * p;
            if (j >= t) dpnxt[j] -= dp[j - t] * maxed * p;
        }
        for (int j = 0; j + t <= T; ++j) {
            dpnxt[j + t] += dp[j] * maxed;
        }
        fill(all(dp), 0), swap(dp, dpnxt);

        E += accumulate(all(dp), 0.0);
    }

    cout << setprecision(10) << fixed;
    cout << E << endl;

    exit(0);
}