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
        vector<vector<long long>> a(n);
        vector<int> u(n);
        for (int i = 0; i < n; i++) {
            cin >> u[i];
            u[i]--;
        }
        for (int i = 0; i < n; i++) {
            long long s;
            cin >> s;
            a[u[i]].emplace_back(s);
        }
        vector<long long> ans(n);
        for (int i = 0; i < n; i++) {
            sort(a[i].rbegin(), a[i].rend());
            int sz = (int)a[i].size();
            vector<long long> s(sz);
            partial_sum(a[i].begin(), a[i].end(), s.begin());
            for (int j = 0; j < sz; j++) {
                int t = sz / (j + 1) * (j + 1);
                ans[j] += s[t - 1];
            }
        }
        for (long long i : ans) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}