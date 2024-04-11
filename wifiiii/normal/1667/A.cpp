#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    ll ans = 1e18;
    for(int i = 0; i < n; ++i) {
        ll pre = 0, tmp = 0;
        for(int j = i - 1; j >= 0; --j) {
            ll nxt = (pre + a[j]) / a[j] * a[j];
            tmp += (pre + a[j]) / a[j];
            pre = nxt;
        }
        pre = 0;
        for(int j = i + 1; j < n; ++j) {
            ll nxt = (pre + a[j]) / a[j] * a[j];
            tmp += (pre + a[j]) / a[j];
            pre = nxt;
        }
        ans = min(ans, tmp);
    }
    cout << ans << '\n';
}