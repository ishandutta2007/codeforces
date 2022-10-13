#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    int64_t ans = 1, mod = 1e9 + 7;
    bool off = false;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        for(int j = 0; j < m; j++)
            if(s[j] == '#') {
                ans *= 2;
                if(ans >= mod) ans -= mod;
            }
            else off = true;
    }
    ans -= !off;
    if(ans < 0) ans += mod;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solve();
}