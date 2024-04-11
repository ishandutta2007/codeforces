#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> a(n);
        ll tot = 0; ll ca = n * (n + 1) / 2;
        for(int i = 0; i < n; ++i) cin >> a[i], tot += a[i];
        if(tot % ca) {
            cout << "NO\n";
            continue;
        }
        ll s = tot / ca;
        vector<ll> ans(n);
        int ok = 1;
        for(int i = 0; i < n; ++i) {
            ans[(i + 1) % n] = (s - a[(i + 1) % n] + a[i]) / n;
            if((s - a[(i + 1) % n] + a[i]) % n) ok = 0;
        }
        for(int i = 0; i < n; ++i) if(ans[i] < 1 || ans[i] > 1e9) ok = 0;
        if(ok) {
            cout << "YES\n";
            for(ll i : ans) cout << i << " "; cout << '\n';
        } else {
            cout << "NO\n";
        }
    }
}