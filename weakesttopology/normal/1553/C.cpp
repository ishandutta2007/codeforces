#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cost(const string& s) {
    int n = (int)size(s);
    int left[2] = {(n + 1) / 2, n / 2};
    int pts[2] = {0, 0};
    for (int i = 0; i < n; ++i) {
        int o = i % 2;
        pts[o] += s[i] == '1';
        left[o] -= 1;
        for (int t : {0, 1}) {
            if (pts[t] + left[t] < pts[t ^ 1]) return i + 1;
        }
    }
    return n;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int)size(s), ans = n;
        for (int mask = 0; mask < (1 << n); ++mask) {
            auto r = s;
            for (int i = 0; i < n; ++i) {
                if (s[i] != '?') continue;
                r[i] = (mask >> i & 1) ? '1' : '0';
            }
            ans = min(ans, cost(r));
        }
        cout << ans << '\n';
    }
    exit(0);
}