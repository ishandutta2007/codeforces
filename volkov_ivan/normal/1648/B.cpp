#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int C = 1e6 + 7;
int has[C], pref[C];

void solve() {
    int n, c;
    cin >> n >> c;
    for (int i = 0; i <= c; i++)
        has[i] = pref[i] = 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        has[v] = 1;
    }
    for (int i = 1; i <= c; i++)
        pref[i] = pref[i - 1] + has[i];
    for (int t = 1; t <= c; t++) {
        if (has[t])
            continue;
        for (int y = 1; y * t <= c; y++) {
            if (!has[y])
                continue;
            int cur = 0;
            if (y * (t + 1) - 1 > c)
                cur = pref[c] - pref[y * t - 1];
            else
                cur = pref[y * (t + 1) - 1] - pref[y * t - 1];
            if (cur > 0) {
                cout << "No\n";
                return;
            }
        }
    }
    cout << "Yes\n";
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}