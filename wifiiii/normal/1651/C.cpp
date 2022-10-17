#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        ll al = 1e9, ar = 1e9, bl = 1e9, br = 1e9;
        for(int i = 0; i < n; ++i) {
            al = min(al, abs(b[i] - a[0]));
            ar = min(ar, abs(b[i] - a[n - 1]));
            bl = min(bl, abs(a[i] - b[0]));
            br = min(br, abs(a[i] - b[n - 1]));
        }
        ll ans = min({abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]),
                      abs(a[0] - b[0]) + ar + br,
                      abs(a[n - 1] - b[n - 1]) + al + bl,
                      al + bl + ar + br,
                      abs(a[0] - b[n - 1]) + bl + ar,
                      abs(b[0] - a[n - 1]) + al + br,
                      abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0])});
        cout << ans << '\n';
    }
}