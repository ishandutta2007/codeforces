#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10;
string s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> s[i];
    if (k == 1) {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) if (s[i][j] == '.') ++ans;
        }
        cout << ans << endl;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ) {
            if (s[i][j] == '*') { ++j; continue; }
            int p = j;
            for (; p < m && s[i][p] == '.'; ++p);
            if (p - j >= k) ans += p - j - k + 1;
            j = p;
        }
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ) {
            if (s[i][j] == '*') { ++i; continue; }
            int p = i;
            for (; p < n && s[p][j] == '.'; ++p);
            if (p - i >= k) ans += p - i - k + 1;
            i = p;
        }
    }
    cout << ans << endl;
    return 0;
}