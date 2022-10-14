#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

void test_case() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> x, y;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') x.pb(i);
        else y.pb(i);
    }
    if ((int) x.size() != (int) y.size() * 2) {
        cout << "NO" << '\n';
        return;
    }
    vector<tuple<int, int, int>> b;
    for (int i = 0; i < (int) y.size(); i++) {
        b.emplace_back(x[i], y[i], x[i + (int) y.size()]);
    }
    bool ok = true;
    for (auto tp : b) {
        int xx = get<0>(tp), yy = get<1>(tp), zz = get<2>(tp);
        if (xx > yy || xx > zz || yy > zz) {
            ok = false;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1; cin >> T;
    while (T--)
        test_case();
}