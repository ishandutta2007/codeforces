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
    auto calc = [n](int l, int r) {
        return l * (n - l) + (n - l) * (n - l + 1) / 2 - (n - r - 1) * (n - r) / 2;
    };
    set<int> left_borders = {0};
    int result = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            result += calc(*left_borders.rbegin(), i - 1);
            left_borders.insert(i);
        }
    }
    result += calc(*left_borders.rbegin(), n - 1);
    left_borders.insert(n);
    auto add = [&](int pos) {
        if (left_borders.count(pos)) {
            return;
        }
        auto r = left_borders.upper_bound(pos);
        auto l = r;
        l--;
        result -= calc(*l, *r - 1);
        result += calc(*l, pos - 1);
        result += calc(pos, *r - 1);
        left_borders.insert(pos);
    };

    auto del = [&](int pos) {
        if (!left_borders.count(pos)) {
            return;
        }
        auto r = left_borders.upper_bound(pos);
        auto l = r;
        l--;
        l--;
        result -= calc(*l, pos - 1);
        result -= calc(pos, *r - 1);
        result += calc(*l, *r - 1);
        left_borders.erase(pos);
    };
    for (int i = 0; i < m; i++) {
        int pos, new_val;
        cin >> pos >> new_val;
        pos--;
        a[pos] = new_val;
        if (pos > 0 && a[pos] != a[pos - 1] && !left_borders.count(pos)) {
            add(pos);
        }
        if (pos > 0 && a[pos] == a[pos - 1] && left_borders.count(pos)) {
            del(pos);
        }
        if (pos + 1 < n && a[pos + 1] != a[pos] && !left_borders.count(pos + 1)) {
            add(pos + 1);
        }
        if (pos + 1 < n && a[pos] == a[pos + 1] && left_borders.count(pos + 1)) {
            del(pos + 1);
        }
        cout << result << '\n';
        /*for (auto it : left_borders) {
            cout << it << ' ';
        }
        cout << '\n';*/
    }
    return 0;
}