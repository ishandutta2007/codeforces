#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
string s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) if (s[i][j] == 'f' || s[i][j] == 'a' || s[i][j] == 'c' || s[i][j] == 'e') {
            if (i + 1 < n && j + 1 < m) {
                int f = 0, a = 0, c = 0, e = 0;
                for (int k = 0; k <= 1; ++k) for (int l = 0; l <= 1; ++l) {
                    if (s[i + k][j + l] == 'f') ++f;
                    if (s[i + k][j + l] == 'a') ++a;
                    if (s[i + k][j + l] == 'c') ++c;
                    if (s[i + k][j + l] == 'e') ++e;
                }
                ans += (f && a && c && e);
            }
        }
    }
    cout << ans << endl;
    return 0;
}