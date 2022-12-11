#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    string s;
    cin >> s;
    int cntB = 0, lft = 0, deld = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == 'B') cntB++;
        if (s[i] == 'A') lft++;
        if (s[i] == 'B' && lft > 0) {
            lft--;
            deld++;
        }
    }
    deld += (cntB - deld) / 2;
    cout << (int) s.size() - 2 * deld << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}