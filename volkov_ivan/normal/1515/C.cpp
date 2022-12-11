#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    set <pair <int, int>> s;
    cout << "YES\n";
    for (int i = 0; i < m; i++)
        s.insert({0, i});
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        auto elem = *(s.begin());
        s.erase(s.begin());
        cout << elem.second + 1 << ' ';
        elem.first += h;
        s.insert(elem);
    }
    cout << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}