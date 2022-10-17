#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<ll> sum(n + 1);
        for(int i = 0; i < n; ++i) sum[i + 1] = sum[i] + a[i];
        vector<ll> mx(n + 1, -1e18);
        for(int k = 1; k <= n; ++k) {
            for(int i = k; i <= n; ++i) {
                mx[k] = max(mx[k], sum[i] - sum[i - k]);
            }
        }
        for(int k = n - 1; k >= 0; --k) mx[k] = max(mx[k], mx[k + 1]);
        ll ans = 0;
        for(int i = 0; i <= n; ++i) {
            ans = max(ans, mx[i] + 1ll * x * i);
            cout << ans << ' ';
        }
        cout << '\n';
    }
}