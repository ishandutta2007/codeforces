#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        if(n == 1) {
            cout << 1 << '\n';
            continue;
        }
        if(n == 2) {
            cout << (abs(a[0] - a[1]) == 1 ? 1 : 2) << '\n';
            continue;
        }
        vector<ll> b(n - 1);
        for (int i = 0; i < n - 1; ++i) b[i] = abs(a[i + 1] - a[i]);
        vector<ll> c(n);
        int ans = 0;
        for(int i = 0; i < n - 1;) {
            ll g = 0, g2 = 0, tmp;
            int l = i, r = i + 1;
            while(l >= 0 && (tmp = gcd(g, b[l])) != 1) c[l] = g, g = tmp, --l;
            while(l <= i) {
                while(r < n - 1 && gcd(g, (tmp = gcd(g2, b[r]))) != 1) g2 = tmp, ++r;
                ans = max(ans, r - l - 1);
                l += 1;
                g = c[l];
            }
            i = r;
        }
        cout << ans + 1 << '\n';
    }
}