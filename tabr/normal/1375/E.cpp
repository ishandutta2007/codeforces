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
    vector<int> a(n);
    vector<pair<int, int>> t(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        t[i] = make_pair(a[i], i);
    }
    vector<int> c = a;
    sort(t.begin(), t.end());
    for (int i = 0; i < n; i++) {
        a[t[i].second] = i;
    }
    debug(a);
    vector<pair<int, int>> ans;
    for (int i = n - 1; i >= 0; i--) {
        vector<pair<int, int>> x;
        for (int j = 0; j < i; j++) {
            if (c[j] > c[i]) {
                x.emplace_back(a[j], j);
            }
        }
        sort(x.begin(), x.end());
        for (auto p : x) {
            ans.emplace_back(p.second, i);
            swap(a[p.second], a[i]);
        }
    }
    debug(a);
    cout << ans.size() << '\n';
    for (auto p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << '\n';
    }
    return 0;
}