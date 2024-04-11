#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> x, y;
    for (char c : s) {
        int a = c - '0';
        if (a % 2 == 0) x.push_back(a);
        if (a % 2 == 1) y.push_back(a);
    }
    int l = 0, r = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (r >= (int) y.size() || (l < (int) x.size() && x[l] < y[r])) cout << x[l++];
        else cout << y[r++];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}