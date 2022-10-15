#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    const int N = 3 * 2 * 1;
    vector<array<int, N>> pref(n);
    char p[3] = {'a', 'b', 'c'};
    int idx = 0;
    do {
        for (int i = 0; i < n; ++i) {
            pref[i][idx] = s[i] != p[i % 3];
            if (i > 0) {
                pref[i][idx] += pref[i - 1][idx];
            }
        }
        ++idx;
    } while (next_permutation(begin(p), end(p)));
    auto query = [&](int idx, int l, int r) {
        return pref[r][idx] - (l ? pref[l - 1][idx] : 0);
    };
    for (int j = 0; j < m; ++j) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int len = r - l + 1;
        int ans;
        if (len >= 3) {
            ans = n;
            for (int idx = 0; idx < N; ++idx) {
                ans = min(ans, query(idx, l, r));
            }
        }
        else if (len == 2) {
            ans = s[l] == s[l + 1];
        }
        else {
            ans = 0;
        }
        cout << ans << '\n';
    }
    exit(0);
}