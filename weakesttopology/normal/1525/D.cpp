#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

template<typename T>
bool chmin(T& x, T y) { return y < x ? (x = y, true) : false; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        x ? a.push_back(i) : b.push_back(i);
    }

    if (empty(a)) {
        cout << 0 << endl;
        exit(0);
    }

    int m = (int)size(b);

    vector<int> dp(m, INF), dpnxt(m, INF);
    for (int j = 0; j < m; ++j) dp[j] = abs(a[0] - b[j]);

    a.erase(begin(a));
    for (auto x : a) {
        int prefmin = INF;
        for (int j = 0; j < m; ++j) {
            chmin(dpnxt[j], abs(b[j] - x) + prefmin);
            chmin(prefmin, dp[j]);
        }
        fill(all(dp), INF), swap(dp, dpnxt);
    }

    int ans = *min_element(all(dp));
    cout << ans << endl;

    exit(0);
}