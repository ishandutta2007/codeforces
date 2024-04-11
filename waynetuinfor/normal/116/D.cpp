#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 150 + 5;
string s[maxn];
int l[maxn], r[maxn];
bool em[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
        l[i] = m; r[i] = -1;
        for (int j = 0; j < m; ++j) if (s[i][j] == 'W') {
            l[i] = min(l[i], j);
            r[i] = max(r[i], j);
        }
    }
    l[n] = m; r[n] = -1;
    // for (int i = 0; i < n; ++i) cout << l[i] << ' ' << r[i] << endl;
    int ans = 0, dir = 0, pos = 0, add = 0;
    for (int i = 0; i < n; ++i) {
        if (l[i] == m) em[i] = true;
        if (r[i] == -1) em[i] = true;
    }
    for (int i = 0; i < n; ++i) {
        if (!em[i]) add = i;
        // cout << pos << ' ' << dir << ' ' << l[i] << ' ' << r[i] << endl;
        if (dir == 0 && (!em[i] || !em[i + 1])) {
            // cout << "jizz: " << i << ' ' << dir << endl;
            ans += max({ 0, r[i] - pos, r[i + 1] - pos });
            pos = max({ pos, r[i], r[i + 1] });
        } else if (!em[i] || !em[i + 1]) {
            // cout << "jizz: " << i << ' ' << dir << endl;
            ans += max({ 0, pos - l[i], pos - l[i + 1] });
            pos = min({pos, l[i], l[i + 1] });
        }
        // cout << ans << endl;
        dir ^= 1;
    }
    cout << ans + add << endl;
    return 0;
}