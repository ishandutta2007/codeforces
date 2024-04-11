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
        int n;
        cin >> n;
        vector<long long> w(n);
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }
        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            g[x].emplace_back(y);
            g[y].emplace_back(x);
        }
        vector<long long> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < (int)g[i].size(); j++) {
                ans.emplace_back(w[i]);
            }
        }
        sort(ans.rbegin(), ans.rend());
        debug(ans);
        long long s = accumulate(w.begin(), w.end(), 0LL);
        cout << s << " ";
        for (int i = 0; i < n - 2; i++) {
            s += ans[i];
            cout << s << " ";
        }
        cout << '\n';
    }
    return 0;
}