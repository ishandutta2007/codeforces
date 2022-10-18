#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];

    int l = 0, r = 1e9 + 1;
    pair<int, int> ans = {1, 1};
    int mx = (1 << m) - 1;

    while (r - l > 1) {
        int mid = l + (r - l) / 2;
        vector<int> tmp(mx + 1);
        pair<int, int> res = {0, 0};
        tmp[0] = 1;
        rep(i, 0, n) {
            int bt = 0;
            rep(j, 0, m) {
                if (a[i][j] >= mid) {
                    bt += (1 << j);
                }
            }
            if (tmp[bt] == 0) {
                tmp[bt] = i + 1;
                rep(c, 0, mx + 1) if (((c | bt) == mx) && tmp[c]) {
                    res = make_pair(tmp[c], i + 1);
                }
            }
            if (res.first != 0) break;
        }
        if (res.first != 0) {
            l = mid;
            ans = res;
        } else {
            r = mid;
        }
    }
    cout << ans.first << ' ' << ans.second << endl;
    // cout << l << endl;
    return 0;
}