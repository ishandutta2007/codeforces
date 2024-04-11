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
    vector<bool> pn(10000001, true);
    vector<int> f(10000001, 1e9);
    pn[0] = pn[1] = false;
    for (int i = 2; i <= 10000000; i++) {
        if (pn[i]) {
            for (int j = 2; i * j <= 10000000; j++) {
                pn[i * j] = false;
                f[i * j] = min(i, f[i * j]);
            }
        }
    }
    vector<vector<int>> ans(2, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (pn[a]) {
            continue;
        }
        int m = f[a];
        while (a % m == 0) {
            a /= m;
        }
        if (a != 1) {
            ans[0][i] = m;
            ans[1][i] = a;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}