#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        vector<array<int, 2>> a(m);
        for (int i : {0, 1}) {
            for (int j = 0; j < m; ++j) {
                cin >> a[j][i];
            }
        }
        vector<array<long long, 2>> pref(m), suff(m);
        for (int i : {0, 1}) {
            for (int j = 0; j + 1 < m; ++j) {
                pref[j + 1][i] = pref[j][i] + a[j][i];
            }
            for (int j = m - 1; j > 0; --j) {
                suff[j - 1][i] = suff[j][i] + a[j][i];
            }
        }
        long long ans = 0x3f3f3f3f3f3f3f3f;
        for (int j = 0; j < m; ++j) {
            ans = min(ans, max(pref[j][1], suff[j][0]));
        }
        cout << ans << '\n';
    }
    exit(0);
}