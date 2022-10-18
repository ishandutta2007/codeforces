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
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        a[m - 1]++;
    }
    vector<int> c(k);
    for (int i = 0; i < k; i++) {
        cin >> c[i];
    }
    vector<vector<int>> ans(1);
    int it = 0, lim = 0;
    auto add = [&](int i) {
        if (ans[it].size() < lim) {
            ans[it].emplace_back(i);
        } else if (it + 1 == ans.size()) {
            it++;
            ans.emplace_back(vector<int>(1, i));
        } else {
            it++;
            ans[it].emplace_back(i);
        }
    };
    for (int i = k - 1; i >= 0; i--) {
        int j = i;
        while (j > 0 && c[j - 1] == c[i]) {
            j--;
        }
        it = 0, lim = c[i];
        for (; i >= j; i--) {
            while (a[i]--) {
                add(i);
            }
        }
        i++;
    }
    cout << ans.size() << '\n';
    for (auto v : ans) {
        cout << v.size() << " ";
        for (auto i : v) {
            cout << i + 1 << " ";
        }
        cout << '\n';
    }
    return 0;
}