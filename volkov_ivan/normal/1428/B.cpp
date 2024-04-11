#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool has_0 = 0, has_1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '>') has_0 = 1;
        if (s[i] == '<') has_1 = 1;
    }
    if (!has_0 || !has_1) {
        cout << n << "\n";
        return;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int nxt = (i + 1) % n;
        if (s[i] == '-' || s[nxt] == '-') res++;
    }
    cout << res << "\n";
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}