#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        ll cur = a[0], ans = 0;
        for(int i = 1; i < n; ++i) {
            if(a[i] * 100 > cur * k) {
                ans += (a[i] * 100 + k - 1) / k - cur;
                cur += (a[i] * 100 + k - 1) / k - cur;
            }
            assert(a[i] * 100 <= cur * k);
            cur += a[i];
        }
        cout << ans << endl;
    }
}