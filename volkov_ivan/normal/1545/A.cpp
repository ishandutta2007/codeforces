#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector <int> l, r;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i % 2 == 0)
            l.push_back(x);
        else
            r.push_back(x);
    }
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    vector <int> v;
    int uk_l = 0, uk_r = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            v.push_back(l[uk_l++]);
        else
            v.push_back(r[uk_r++]);
    }
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}