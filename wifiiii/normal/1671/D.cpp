#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        ll ans = 0;
        for(int i = 1; i < n; ++i) ans += abs(a[i] - a[i - 1]);
        auto [mn, mx] = minmax_element(a.begin(), a.end());
        if(*mn > 1) {
            int p = min(a[0] - 1, a.back() - 1);
            for(int i = 1; i < n; ++i) {
                p = min(p, abs(a[i] - 1) + abs(a[i - 1] - 1) - abs(a[i] - a[i - 1]));
            }
            ans += p;
        }
        if(*mx < x) {
            int p = min(abs(a[0] - x), abs(a.back() - x));
            for(int i = 1; i < n; ++i) {
                p = min(p, abs(a[i] - x) + abs(a[i - 1] - x) - abs(a[i] - a[i - 1]));
            }
            ans += p;
        }
        cout << ans << '\n';
    }
}