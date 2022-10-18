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
    vector<int> g(n);
    iota(g.begin(), g.end(), 0);
    vector<vector<int>> res;
    while (c != g) {
        debug(c);
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[c[i]] = i;
        }
        vector<int> v;
        int t = -1, s = 1;
        for (int i = 0; i < n - 1; i++) {
            if (p[i] > p[i + 1]) {
                t = i;
                if (p[i + 1]) {
                    v.emplace_back(p[i + 1]);
                }
                for (int j = p[i + 1] + 1;; j++) {
                    if (c[j] == c[j - 1] + 1) {
                        s++;
                    } else {
                        break;
                    }
                }
                v.emplace_back(s);
                v.emplace_back(p[i] - p[i + 1] + 1 - s);
                if (n - 1 - p[i]) {
                    v.emplace_back(n - 1 - p[i]);
                }
                break;
            }
        }
        res.emplace_back(v);
        vector<int> d;
        assert(t != -1);
        for (int i = p[t] + 1; i < n; i++) {
            d.emplace_back(c[i]);
        }
        for (int i = p[t + 1] + s; i <= p[t]; i++) {
            d.emplace_back(c[i]);
        }
        for (int i = p[t + 1]; i < p[t + 1] + s; i++) {
            d.emplace_back(c[i]);
        }
        for (int i = 0; i < p[t + 1]; i++) {
            d.emplace_back(c[i]);
        }
        swap(c, d);
    }
    cout << res.size() << '\n';
    for (auto v : res) {
        cout << v.size() << " ";
        for (int i : v) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}