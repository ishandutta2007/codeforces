#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        ll ans = 0;
        for(int i = 0; i < n; ++i) cin >> a[i], ans += a[i];
        reverse(a.begin(), a.end());
        for(int i = 0; i < n; ++i) a[i] -= i;
        sort(a.begin(), a.end(), greater<int>());
        for(int i = 0; i < k; ++i) {
            ans -= a[i];
        }
        ans -= 1ll * k * (k - 1) / 2;
        cout << ans << '\n';
    }
}