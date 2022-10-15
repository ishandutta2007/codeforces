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

    constexpr int nmax = 100, kmax = 1e4;
    bool dp[nmax][nmax][kmax + 1]{};

    dp[0][0][0] = true;
    for (int x = 0; x < nmax; ++x) {
        for (int y = 0; y < nmax; ++y) {
            for (int k = 0; k < kmax; ++k) {
                if (not dp[x][y][k]) continue;
                if (x + 1 < nmax && k + y + 1 <= kmax) dp[x + 1][y][k + y + 1] = true;
                if (y + 1 < nmax && k + x + 1 <= kmax) dp[x][y + 1][k + x + 1] = true;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        --n, --m;
        string res = dp[n][m][k] ? "YES" : "NO";
        cout << res << endl;
    }

    exit(0);
}