#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        ll ans = 11ll * count(s.begin(), s.end(), '1');
        int l = -1, r = -1;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '1') {
                if(l == -1) l = i;
                r = i;
            }
        }
        r = n - 1 - r;
        if(ans == 0) {
            cout << 0 << '\n';
        } else if(ans == 11) {
            if(r <= k) cout << 1 << '\n';
            else if(l <= k) cout << 10 << '\n';
            else cout << 11 << '\n';
        } else {
            if(l + r <= k) cout << ans - 11 << '\n';
            else if(r <= k) cout << ans - 10 << '\n';
            else if(l <= k) cout << ans - 1 << '\n';
            else cout << ans << '\n';
        }
    }
}