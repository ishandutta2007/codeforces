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
        vector<ll> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        for(int i = 1; i < n; ++i) a[i] += a[i - 1];
        ll ans = 0;
        for(int i = 0; i < n; ++i) {
            if(x >= a[i]) {
                ans += (x - a[i]) / (i + 1) + 1;
            }
        }
        cout << ans << '\n';
    }
}