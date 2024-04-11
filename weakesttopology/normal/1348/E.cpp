#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename T>
bool chmax(T& x, T y) { return x < y ? (x = y, true) : false; }
const int inf = 0x3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> dp(k, {-inf, -inf});
    dp[0] = {0, 0};
    ll ans = 0;
    auto take = [&](int& x) {
        int l = max(0, (x - 2 * (k - 1))) / k;
        x -= l * k;
        ans += l;
    };
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        take(a), take(b);
        auto dpnxt = dp;
        for (int x = 0; x < k; ++x) {
            auto [cnt, y] = dp[x];
            // match z from a with k - z from b
            for (int z = 0; z <= min(k, a); ++z) {
                if (k - z > b) continue;
                int nx = x + (a - z), ny = y + (b - (k - z));
                chmax(dpnxt[nx % k], {cnt + 1 + (nx / k) + (ny / k), ny % k});
            }
            // do not match anything
            int nx = x + a, ny = y + b;
            chmax(dpnxt[nx % k], {cnt + (nx / k) + (ny / k), ny % k});
        }
        swap(dp, dpnxt);
    }
    ans += max_element(begin(dp), end(dp))->first;
    cout << ans << endl;
    exit(0);
}