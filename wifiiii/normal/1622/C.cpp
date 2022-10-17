#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n; ll k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        ll sum = 0;
        for(int i = 1; i < n; ++i) sum += a[i];
        ll ans = max(0ll, a[0] + sum - k);
        for(int i = 0; i < n; ++i) {
            ans = min(ans, i + max(0ll, (1ll * a[0] * (i + 1) + sum - k + i) / (i + 1)));
            sum -= a[n - 1 - i];
        }
        cout << ans << '\n';
    }
}