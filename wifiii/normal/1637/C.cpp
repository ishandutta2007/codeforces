#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        if(n == 3) {
            if(a[1] % 2 == 0) {
                cout << a[1] / 2 << '\n';
            } else {
                cout << -1 << '\n';
            }
            continue;
        }
        int ok = 0, cnt = 0;
        ll ans = 0;
        for(int i = 1; i < n - 1; ++i) {
            if(a[i] > 1) ok = 1;
            ans += (a[i] + 1) / 2;
        }
        if(ok) cout << ans << '\n';
        else cout << -1 << '\n';
    }
}