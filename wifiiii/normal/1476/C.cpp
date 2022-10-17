#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> c(n), a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> c[i];
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        ll ans = 0, cur = 0;
        for(int i = 1; i < n; ++i) {
            if(a[i] > b[i]) swap(a[i], b[i]);
            if(i == 1) cur = b[i] - a[i] + 2;
            else if(a[i] == b[i]) cur = 2;
            else cur = max(cur + a[i] - 1 + c[i-1] - b[i], b[i] - a[i]) + 2;
            ans = max(ans, cur + c[i] - 1);
        }
        cout << ans << endl;
    }
}