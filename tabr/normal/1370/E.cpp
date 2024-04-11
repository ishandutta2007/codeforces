#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<int> x;
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            x.emplace_back(s[i] - '0');
            if (s[i] == '0') {
                d++;
            } else {
                d--;
            }
        }
    }
    int m = x.size();
    if (d != 0) {
        cout << -1 << '\n';
        return 0;
    }
    if (x.empty()) {
        cout << 0 << '\n';
        return 0;
    }
    vector<int> y;
    for (int i = 0; i < m; i++) {
        if (i == 0 || x[i] != x[i - 1]) {
            y.emplace_back(1);
        } else {
            y.back()++;
        }
    }
    m = y.size();
    vector<int> nxt(m);
    iota(nxt.begin(), nxt.end(), 1);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        while (y[i]) {
            int j = i;
            ans++;
            while (j < m) {
                y[j]--;
                while (nxt[j] < m && y[nxt[j]] == 0) {
                    nxt[j] += 2;
                }
                j = nxt[j];
            }
        }
    }
    cout << ans << '\n';
    return 0;
}