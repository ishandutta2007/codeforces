#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int ans[maxn];

int main() {
    int n, m, q; cin >> n >> m >> q;
    string s, t; cin >> s >> t;
    for (int i = 0; i + t.size() - 1 < s.size(); ++i) {
        if (s.substr(i, t.size()) == t) ans[i] = 1;
    }
    for (int i = 1; i < maxn; ++i) ans[i] += ans[i - 1];
    while (q--) {
        int l, r; cin >> l >> r;
        --l, --r;
        r -= t.size() - 1;
        if (r < l) cout << 0 << endl;
        else cout << ans[r] - (l == 0 ? 0 : ans[l - 1]) << endl;
    }
}