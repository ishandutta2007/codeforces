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
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }
    vector<pair<int, int>> ans;
    auto add = [&](int i, int j) {
        debug(i, j, c);
        ans.emplace_back(i + 1, j + 1);
        swap(c[i], c[j]);
        c[i] *= -1;
        c[j] *= -1;
    };
    vector<vector<int>> a;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        if (d[i]) {
            continue;
        }
        vector<int> v;
        v.emplace_back(i);
        d[i] = 1;
        int b = c[i];
        while (b != i) {
            d[b] = 1;
            v.emplace_back(b);
            b = c[b];
        }
        if ((int)v.size() > 1) {
            a.emplace_back(v);
        }
    }
    for (int i = 0; i < (int)a.size(); i += 2) {
        if (i == (int)a.size() - 1) {
            vector<int> x = a[i];
            int p = x[0], q = x[1];
            if ((int)x.size() == 2) {
                for (int j = 0; j < n; j++) {
                    if (j != p && j != q) {
                        add(p, j);
                        add(q, j);
                        add(p, j);
                        break;
                    }
                }
            } else {
                add(p, q);
                if (-c[q] == q) {
                    swap(p, q);
                }
                while (-c[p] != p) {
                    add(p, -c[p]);
                }
                while (c[-c[q]] != q) {
                    add(q, -c[q]);
                }
                add(p, -c[q]);
                add(q, -c[q]);
                add(p, q);
            }
            break;
        }
        vector<int> x = a[i], y = a[i + 1];
        int p = x[0], q = y[0];
        add(p, q);
        while (-c[p] != q) {
            add(p, -c[p]);
        }
        while (-c[q] != p) {
            add(q, -c[q]);
        }
        add(p, q);
    }
    assert((int)ans.size() <= n + 1);
    vector<int> cc(n);
    iota(cc.begin(), cc.end(), 0);
    assert(c == cc);
    cout << ans.size() << '\n';
    for (auto [i, j] : ans) {
        cout << i << " " << j << '\n';
    }
    return 0;
}