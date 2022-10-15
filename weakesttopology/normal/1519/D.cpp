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

    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    vector<ll> pref(n, 0), suff(n, 0);
    for (int i = 0; i + 1 < n; ++i) {
        pref[i + 1] = pref[i] + a[i] * b[i];
    }
    for (int i = n - 1; i > 0; --i) {
        suff[i - 1] = suff[i] + a[i] * b[i];
    }

    constexpr int nmax = 5000;
    ll dp[nmax][nmax]{};
    ll res = inner_product(all(a), begin(b), 0LL);

    for (int i = 0; i < n; ++i) dp[i][i] = a[i] * b[i];
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len <= n; ++l) {
            int r = l + len - 1;
            dp[l][r] = a[l] * b[r] + a[r] * b[l] + dp[l + 1][r - 1];
            res = max(res, pref[l] + suff[r] + dp[l][r]);
        }
    }

    cout << res << endl;

    exit(0);
}