#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (int i = 1; i < n; i += 2) {
        ll x = 1LL << (i - 1);
        for (int j = 0; j < n; j++) {
            a[i][j] = x;
            x *= 2;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int q;
    cin >> q;
    while (q--) {
        ll b;
        cin >> b;
        vector<pair<int, int>> res(1);
        ll x = 1;
        for (int l = 0; l < 2 * n - 2; l++) {
            int i, j;
            tie(i, j) = res.back();
            debug(i, j, x);
            if (i != n - 1 && (a[i + 1][j] & x) == (b & x)) {
                i++;
            } else {
                j++;
            }
            res.emplace_back(i, j);
            x *= 2;
        }
        for (auto p : res) {
            p.first++, p.second++;
            cout << p.first << " " << p.second << endl;
        }
    }
    return 0;
}