#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int ans = 1e9;
        for(int i = 0; i < n; ++i) {
            for(int i2 = i + 1; i2 < n; ++i2) {
                int s = 0;
                for(int j = 0; j < m; ++j) {
                    s += abs(a[i][j] - a[i2][j]);
                }
                ans = min(ans, s);
            }
        }
        cout << ans << '\n';
    }
}