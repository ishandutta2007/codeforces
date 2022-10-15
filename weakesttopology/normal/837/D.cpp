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

    int n, k;
    cin >> n >> k;

    constexpr int kmax = 200, logmax = 60;
    int dp[kmax + 1][kmax * logmax];

    fill(&dp[0][0], &dp[kmax][kmax * logmax], -INF);
    dp[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        int x = 0;
        while (a % 2 == 0) a /= 2, x += 1;
        int y = 0;
        while (a % 5 == 0) a /= 5, y += 1;

        for (int j = k - 1; j >= 0; --j) {
            for (int z = n * logmax - x; z >= 0; --z) {
                dp[j + 1][z + x] = max(dp[j + 1][z + x], dp[j][z] + y);
            }
        }
    }

    int res = 0;
    for (int x = 0; x < n * logmax; ++x) {
        res = max(res, min(x, dp[k][x]));
    }

    cout << res << endl;

    exit(0);
}