#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    bool is0[k], is1[k];
    memset(is0, 0, sizeof(is0));
    memset(is1, 0, sizeof(is1));
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') is0[i % k] = 1;
        if (s[i] == '1') is1[i % k] = 1;
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < k; i++) {
        if (is0[i] && is1[i]) {
            cout << "NO\n";
            return;
        }
        if (is0[i]) cnt0++;
        if (is1[i]) cnt1++;
    }
    if (cnt0 <= k / 2 && cnt1 <= k / 2) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}