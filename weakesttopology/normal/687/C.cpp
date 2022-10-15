#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

constexpr int nmax = 500;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<bitset<nmax + 1>> dp(k + 1), dpnxt(k + 1);
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        for (int y = 0; y + x <= k; ++y) {
            dpnxt[y + x] |= dp[y];
            dpnxt[y] |= dp[y] << x;
        }
        for (int y = 0; y <= k; ++y) dp[y] |= dpnxt[y];
        fill(all(dpnxt), 0);
    }

    vector<int> ans;
    for (int x = 0; x <= k; ++x) {
        if (dp[x][k - x]) ans.push_back(x);
    }

    int r = (int)size(ans);
    cout << r << endl;
    for (int i = 0; i < r; ++i) {
        cout << ans[i] << "\n "[i + 1 < r];
    }

    exit(0);
}