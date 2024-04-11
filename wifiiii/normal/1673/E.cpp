#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1 << 20;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int r = n - 1 - k;
    vector<int> ans(N);
    vector<vector<int>> dp(N);
    auto f = [&](int x, int y) -> int {
        y = min(y, x);
        int ret = 0;
        if(dp[x].empty()) {
            dp[x].resize(x + 1);
            int h = 0;
            for(int i = 0; i <= x; ++i) {
                h ^= ((x ^ i) == ((x ^ i) & x));
                dp[x][i] = h;
            }
        }
        return dp[x][y];
    };
    for(int i = 0; i < n; ++i) {
        int p = a[i], q = 0;
        for(int j = i; j < n; ++j) {
            if(j > i) q += a[j];
            if(q > 20 || p * (1ll << q) >= N || j - i > r) break;
            int x = max(i - 1, 0) + max(n - j - 2, 0);
            int y = r - (j - i);
            ans[p * (1ll << q)] ^= f(x, y);
        }
    }
    int g = 0;
    for(int i = N - 1; i >= 0; --i) {
        if(ans[i]) {
            g = 1;
        }
        if(g) cout << ans[i];
    }
    if(!g) cout << 0;
    cout << '\n';
}