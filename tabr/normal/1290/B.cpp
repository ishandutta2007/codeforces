#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> a(n + 1, vector<int>(26));
    rep(i, 1, n + 1) {
        a[i][s[i - 1] - 'a']++;
        rep(j, 0, 26) a[i][j] += a[i - 1][j];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "Yes" << endl;
            continue;
        }
        vector<int> x = a[r];
        rep(j, 0, 26) x[j] -= a[l - 1][j];
        debug(x);
        int cnt = 0;
        rep(j, 0, 26) cnt += (x[j] != 0);
        if (cnt == 1) {
            cout << "No" << endl;
            continue;
        } else if (cnt == 2) {
            if (s[l - 1] != s[r - 1])
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
    return 0;
}