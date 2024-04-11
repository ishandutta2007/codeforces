#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> c;
    vector<vector<int>> a(n + 1, vector<int>(m + 1)),
        a2(n + 1, vector<int>(m + 1)), b(n + 1, vector<int>(m + 1));
    rep(i, 1, n + 1) rep(j, 1, m + 1) cin >> a[i][j];

    a2 = a;
    rep(i, 1, n) rep(j, 1, m) {
        if (a[i][j] * a[i + 1][j] * a[i][j + 1] * a[i + 1][j + 1]) {
            c.push_back(make_pair(i, j));
            a2[i][j] = 0;
            a2[i + 1][j] = 0;
            a2[i][j + 1] = 0;
            a2[i + 1][j + 1] = 0;
        }
    }
    if (a2 == b) {
        cout << c.size() << endl;
        for (auto x : c)
            cout << x.first << ' ' << x.second << endl;
    } else
        cout << -1 << endl;
    return 0;
}