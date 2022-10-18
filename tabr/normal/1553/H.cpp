#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int inf = (int) 1e9;
    auto dc = [&](auto &&self, vector<int> x, int k) -> vector<vector<int>> {
        vector<vector<int>> res(3, vector<int>(1 << k));
        if (k == 0) {
            res[0][0] = inf;
            if (!x[0]) {
                res[0][0] = inf;
                res[1][0] = inf;
                res[2][0] = -inf;
            }
            return res;
        }
        int sz = 1 << (k - 1);
        vector<int> xl = vector<int>(x.begin(), x.begin() + sz);
        vector<int> xr = vector<int>(x.begin() + sz, x.end());
        auto al = self(self, xl, k - 1);
        auto ar = self(self, xr, k - 1);
        for (int i = 0; i < sz; i++) {
            res[0][i] = res[0][i + sz] = min(al[0][i], ar[0][i]);
            res[0][i] = min(res[0][i], sz + ar[1][i] - al[2][i]);
            res[0][i + sz] = min(res[0][i + sz], sz + al[1][i] - ar[2][i]);
            res[1][i] = min(al[1][i], ar[1][i] + sz);
            res[2][i] = max(al[2][i], ar[2][i] + sz);
            res[1][i + sz] = min(al[1][i] + sz, ar[1][i]);
            res[2][i + sz] = max(al[2][i] + sz, ar[2][i]);
        }
        return res;
    };
    int k, n;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> x(1 << k);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x[a[i]] = 1;
    }
    sort(a.begin(), a.end());
    auto ans = dc(dc, x, k);
    for (int i = 0; i < (1 << k); i++) {
        cout << ans[0][i] << " ";
    }
    cout << '\n';
    return 0;
}