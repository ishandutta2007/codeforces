#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
string s[maxn];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) if (s[i][j] == 'B') ++cnt;
    }
    if (cnt == 0) return cout << "1" << endl, 0;
    int u = n + 1, d = -1, r = -1, l = m + 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'B') {
                u = min(u, i); d = max(d, i);
                l = min(l, j); r = max(r, j);
            }
        }
    }
    int len = max(d - u + 1, r - l + 1);
    if (len > n || len > m) return cout << "-1" << endl, 0;
    cout << len * len - cnt << endl;
    return 0;
}