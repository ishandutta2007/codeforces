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
    vector<int> a(n - 1);
    vector<bool> used(n + 1);
    int t = n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> res;
    used[a[0]] = true;
    for (int i = 1; i < n - 1; i++) {
        while (used[t]) {
            t--;
        }
        if (used[a[i]]) {
            res.emplace_back(a[i - 1], t);
            used[t] = true;
        } else {
            res.emplace_back(a[i - 1], a[i]);
            used[a[i]] = true;
        }
    }
    while (used[t]) {
        t--;
    }
    res.emplace_back(a[n - 2], t);
    /*
    if (res.size() != n - 1) {
        cout << -1 << '\n';
        return 0;
    }
    */
    cout << a[0] << '\n';
    for (auto p : res) {
        cout << p.first << " " << p.second << '\n';
    }
    return 0;
}