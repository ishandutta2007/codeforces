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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> x;
    int piv;
    for (int i = 1; i < h; i++) {
        int dif = 0;
        for (int j = 0; j < w; j++) {
            if (a[0][j] != a[i][j]) {
                dif++;
                x.emplace_back(j);
            }
        }
        if (dif >= 5) {
            cout << "No" << '\n';
            return 0;
        } else if (dif <= 2) {
            x.clear();
            continue;
        }
        piv = i;
        break;
    }
    if (x.empty()) {
        cout << "Yes" << '\n';
        for (int i : a[0]) {
            cout << i << " ";
        }
        cout << '\n';
        return 0;
    }
    vector<int> c(h);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (binary_search(x.begin(), x.end(), j)) {
                continue;
            }
            if (a[i][j] != a[piv][j]) {
                c[i]++;
            }
        }
    }
    int sz = (int)x.size();
    debug(x);
    for (int mask = 0; mask < (1 << sz); mask++) {
        if (__builtin_popcount(mask) != 2) {
            continue;
        }
        vector<int> b = c;
        vector<int> d;
        for (int k = 0; k < sz; k++) {
            if (mask & (1 << k)) {
                d.emplace_back(x[k]);
                continue;
            }
            for (int i = 0; i < h; i++) {
                if (a[piv][x[k]] != a[i][x[k]]) {
                    b[i]++;
                }
            }
        }
        debug(b);
        debug(d);
        int maxb = *max_element(b.begin(), b.end());
        if (maxb > 2) {
            continue;
        } else if (maxb == 2) {
            int id = (int)(max_element(b.begin(), b.end()) - b.begin());
            for (int k = 0; k < h; k++) {
                for (int l = 0; l < 2; l++) {
                    if (a[id][d[l]] != a[k][d[l]]) {
                        b[k]++;
                    }
                }
            }
            if (*max_element(b.begin(), b.end()) == 2) {
                cout << "Yes" << '\n';
                a[piv][d[0]] = a[id][d[0]];
                a[piv][d[1]] = a[id][d[1]];
                for (int j : a[piv]) {
                    cout << j << " ";
                }
                cout << '\n';
                return 0;
            }
        } else if (maxb == 0) {
            cout << "Yes" << '\n';
            for (int i : a[piv]) {
                cout << i << " ";
            }
            cout << '\n';
            return 0;
        } else {
            for (int l = 0; l < 2; l++) {
                int e = -1;
                int id = (int)(max_element(b.begin(), b.end()) - b.begin());
                for (int i = 0; i < h; i++) {
                    if (b[i] == 0) {
                        continue;
                    }
                    if (a[i][d[l]] != a[id][d[l]]) {
                        if (e == -1) {
                            e = a[i][d[l ^ 1]];
                        } else if (e != a[i][d[l ^ 1]]) {
                            e = -2;
                            break;
                        }
                    }
                }
                if (e == -1) {
                    e = a[id][d[l ^ 1]];
                } else if (e == -2) {
                    continue;
                }
                cout << "Yes" << '\n';
                a[id][d[l ^ 1]] = e;
                a[piv][d[0]] = a[id][d[0]];
                a[piv][d[1]] = a[id][d[1]];
                for (int i : a[piv]) {
                    cout << i << " ";
                }
                cout << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}