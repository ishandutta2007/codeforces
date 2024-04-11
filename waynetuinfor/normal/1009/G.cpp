#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
string s, t, ans;
int cnt[6], c[1 << 6], mask[maxn];
int tc[1 << 6];
int n;

bool ok() {
    int all = 0;
    for (int i = 0; i < (1 << 6); ++i) tc[i] = c[i];
    for (int i = 5; i >= 0; --i) {
        for (int j = (1 << 6) - 1; j >= 0; --j) {
            if (j >> i & 1) tc[j] += tc[j ^ (1 << i)];
        }
    }
    for (int i = 0; i < (1 << 6); ++i) {
        int all = 0;
        for (int j = 0; j < 6; ++j) if (i >> j & 1) all += cnt[j];
        if (all < tc[i]) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; ++i) ++cnt[s[i] - 'a'];
    for (int i = 0; i < n; ++i) mask[i] = (1 << 6) - 1, ++c[mask[i]];
    int m; cin >> m;
    while (m--) {
        int p; cin >> p >> t;
        --p;
        --c[mask[p]];
        mask[p] = 0;
        for (int i = 0; i < t.size(); ++i) mask[p] ^= (1 << (t[i] - 'a'));
        ++c[mask[p]];
    }
    for (int i = 0; i < n; ++i) {
        bool ad = false;
        --c[mask[i]];
        for (int j = 0; j < 6 && !ad; ++j) if (mask[i] >> j & 1) {
            if (cnt[j] == 0) continue;
            --cnt[j];
            if (ok()) {
                ad = true;
                ans += (char)(j + 'a');
                continue;
            }
            ++cnt[j];
        }
        if (!ad) {
            cout << "Impossible";
            return 0;
        }
    }
    cout << ans;
    return 0;
}