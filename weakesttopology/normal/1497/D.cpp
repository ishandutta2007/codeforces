#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T>
bool chmax(T& x, T y) { return x < y ? (x = y, true) : false; }
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> tag(n);
        for (int i = 0; i < n; ++i) {
            cin >> tag[i];
        }
        vector<ll> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        vector<ll> dp(n);
        for (int i = 1; i < n; ++i) {
            vector<ll> dpnxt(n);
            ll suffmax = 0;
            for (int j = i - 1; j >= 0; --j) {
                if (tag[j] != tag[i]) {
                    ll temp = abs(s[i] - s[j]) + suffmax;
                    chmax(suffmax, dp[j] + abs(s[i] - s[j]));
                    chmax(dp[i], dp[j] + abs(s[i] - s[j]));
                    chmax(dp[j], temp);
                }
            }
        }
        ll ans = *max_element(begin(dp), end(dp));
        cout << ans << endl;
    }
    exit(0);
}