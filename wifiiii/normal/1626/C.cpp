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
        vector<int> a(n), b(n), f(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        for(int i = 1; i < n; ++i) {
            for(int j = i - 1; j >= 0; --j) {
                if(a[i] - b[i] + 1 <= a[j]) {
                    f[j] = 1;
                } else {
                    break;
                }
            }
        }
        ll ans = 0, s = -1;
        for(int i = 0; i < n; ++i) {
            if(s == -1) {
                s = a[i] - b[i] + 1;
            }
            s = min(s, (ll)a[i] - b[i] + 1);
            if(f[i] == 0) {
                ans += (a[i] - s + 1) * (a[i] - s + 2) / 2;
                s = -1;
            }
        }
        cout << ans << '\n';
    }
}