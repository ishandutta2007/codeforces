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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            int j;
            cin >> j;
            j--;
            g[j].emplace_back(i);
        }
        int low = 0, high = n;
        while (high - low > 1) {
            int mid = (high + low) >> 1;
            int need = 0;
            function<int(int, int)> Dfs = [&](int v, int p) {
                int a = 0;
                for (int to : g[v]) {
                    a = max(a, Dfs(to, v));
                }
                a++;
                if (v != 0 && p != 0 && a >= mid) {
                    need++;
                    return 0;
                }
                return a;
            };
            Dfs(0, -1);
            if (need <= k) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cout << high << '\n';
    }
    return 0;
}