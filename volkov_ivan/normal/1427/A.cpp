#include <bits/stdc++.h>
//#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    vector <int> mn, pl, zeroes;
    int s_mn = 0, s_pl = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) zeroes.push_back(0);
        if (a[i] < 0) mn.push_back(a[i]), s_mn += -a[i];
        if (a[i] > 0) pl.push_back(a[i]), s_pl += a[i];
    }
    if (s_mn == s_pl) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (s_mn > s_pl) {
        for (int elem : mn) cout << elem << ' ';
        for (int elem : pl) cout << elem << ' ';
        for (int elem : zeroes) cout << elem << ' ';
    } else {
        for (int elem : pl) cout << elem << ' ';
        for (int elem : mn) cout << elem << ' ';
        for (int elem : zeroes) cout << elem << ' ';
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
    for (int i = 0; i < t; i++) solve();
    return 0;
}