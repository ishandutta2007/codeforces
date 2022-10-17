#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    ll ans = 0;
    for(int i = 0; i < n; i += 2) {
        ll cur = 0, minn = 0;
        for(int j = i + 1; j < n; ++j) {
            if(j % 2 == 1) {
                // a[i] >= l >= max(1, -minn),  1 - cur <= l <= a[j] - cur
                ll r = min(a[i], a[j] - cur);
                ll l = max(max(1ll, -minn), 1 - cur);
                if(r >= l) ans += r - l + 1;
            }
            if(j % 2 == 1) {
                // )
                cur -= a[j];
                minn = min(minn, cur);
            } else {
                // (
                cur += a[j];
                minn = min(minn, cur);
            }
        }
    }
    cout << ans << endl;
}