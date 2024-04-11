#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, n), b(n + 1, -1);
    vector<pair<int, int>> t0;
    rep(i, 0, m) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            rep(j, l, r) b[j] = 0;
        } else
            t0.push_back(make_pair(l, r));
    }
    rep(i, 2, n + 1) a[i] = a[i - 1] + b[i - 1];
    for (auto p : t0) {
        int l = p.first, r = p.second;
        rep(i, l + 1, r + 1) {
            if (a[i - 1] > a[i])
                break;
            if (i == r) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    rep(i, 1, n + 1) cout << a[i] << ' ';
    cout << endl;

    return 0;
}