#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> a;
    vector<int> p(3);
    iota(p.begin(), p.end(), 0);
    do {
        vector<int> b(n + 1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            b[i + 1] = b[i];
            if (c != p[i % 3]) {
                b[i + 1]++;
            }
        }
        a.emplace_back(b);
    } while (next_permutation(p.begin(), p.end()));
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = n + 1;
        for (int i = 0; i < 6; i++) {
            ans = min(ans, a[i][r + 1] - a[i][l]);
        }
        cout << ans << '\n';
    }
    return 0;
}