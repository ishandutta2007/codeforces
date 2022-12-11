#include <bits/stdc++.h>
#define int long long

using namespace std;

string make(string w, int x) {
    int n = w.size();
    string s = "";
    for (int i = 0; i < n; i++) {
        char t = '0';
        if (i - x >= 0 && w[i - x] == '1') t = '1';
        if (i + x < n && w[i + x] == '1') t = '1';
        s += t;
    }
    return s;
}

void solve() {
    string s;
    int x;
    cin >> s >> x;
    string w;
    int n = s.size();
    for (int i = 0; i < n; i++) w += "1";
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (i - x >= 0) w[i - x] = '0';
            if (i + x < n) w[i + x] = '0';
        }
    }
    if (make(w, x) == s) cout << w << "\n";
    else cout << "-1\n";
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