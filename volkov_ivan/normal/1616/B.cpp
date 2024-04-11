#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    string t = "";
    t += s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] > s[i - 1])
            break;
        t += s[i];
    }
    string t2 = t;
    reverse(t2.begin(), t2.end());
    t += t2;
    t2 = "";
    t2 += t[0];
    t2 += t[0];
    cout << min(t, t2) << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        solve();
    return 0;
}