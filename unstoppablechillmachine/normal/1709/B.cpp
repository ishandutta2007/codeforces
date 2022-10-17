#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> pref_pos(n), pref_neg(n);
    for (int i = 1; i < n; i++) {
        pref_pos[i] = pref_pos[i - 1];
        pref_neg[i] = pref_neg[i - 1];
        if (a[i] > a[i - 1]) {
            pref_pos[i] += a[i] - a[i - 1];
        } else {
            pref_neg[i] += a[i - 1] - a[i];
        }
    }
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        from--, to--;
        if (from < to) {
            cout << pref_neg[to] - pref_neg[from] << '\n';
        } else {
            cout << pref_pos[from] - pref_pos[to] << '\n';
        }
    }
    return 0;
}