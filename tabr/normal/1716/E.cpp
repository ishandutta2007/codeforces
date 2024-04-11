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
    function<vector<vector<long long>>(int, vector<long long>)> Solve = [&](int n, vector<long long> a) {
        if (n == 0) {
            vector<vector<long long>> res(3, vector<long long>(1));
            res[0][0] = res[1][0] = res[2][0] = max(0LL, a[0]);
            return res;
        }
        int k = 1 << (n - 1);
        vector<long long> al(a.begin(), a.begin() + k);
        vector<long long> ar(a.begin() + k, a.end());
        auto bl = Solve(n - 1, al);
        auto br = Solve(n - 1, ar);
        long long sl = accumulate(al.begin(), al.end(), 0LL);
        long long sr = accumulate(ar.begin(), ar.end(), 0LL);
        vector<vector<long long>> res(3, vector<long long>(1 << n));
        for (int i = 0; i < k; i++) {
            res[0][i] = max({bl[0][i], br[0][i], bl[2][i] + br[1][i]});
            res[0][i + k] = max({bl[0][i], br[0][i], bl[1][i] + br[2][i]});
            res[1][i] = max(bl[1][i], sl + br[1][i]);
            res[1][i + k] = max(br[1][i], sr + bl[1][i]);
            res[2][i] = max(br[2][i], bl[2][i] + sr);
            res[2][i + k] = max(bl[2][i], br[2][i] + sl);
        }
        return res;
    };
    int n;
    cin >> n;
    vector<long long> a(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
    }
    auto ans = Solve(n, a);
    int q;
    cin >> q;
    int t = 0;
    while (q--) {
        int c;
        cin >> c;
        t ^= 1 << c;
        cout << ans[0][t] << '\n';
    }
    return 0;
}