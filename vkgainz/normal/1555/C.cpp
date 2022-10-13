#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int m; cin >> m;
        vector<vector<int>> a(2, vector<int>(m));
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];
        vector<int> pref(m + 2), suf(m + 2);
        for(int i = 1; i <= m; i++)
            pref[i] = pref[i - 1] + a[1][i - 1];
        for(int i = m; i >= 1; i--)
            suf[i] = suf[i + 1] + a[0][i - 1];
        int ans = 1e9;
        for(int i = 1; i <= m; i++) {
            ans = min(ans, max(pref[i - 1], suf[i + 1]));
        }
        cout << ans << "\n";
    }
}