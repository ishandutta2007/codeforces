#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct sparse {
    using T = int;
    int n;
    int h;
    vector<vector<T>> table;

    T op(T x, T y) {
        return min(x, y);
    }

    sparse(const vector<T> &v) {
        n = (int) v.size();
        h = 32 - __builtin_clz(n);
        table.resize(h);
        table[0] = v;
        for (int j = 1; j < h; j++) {
            table[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                table[j][i] = op(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int l, int r) {
        assert(l < r);
        int k = 31 - __builtin_clz(r - l);
        return op(table[k][l], table[k][r - (1 << k)]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        vector<int> shl(n), shr(n);
        for (int i = 1; i < n; i++) {
            if (a[i] <= b[i - 1]) {
                shl[i] = 1;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (a[i] <= b[i + 1]) {
                shr[i] = 1;
            }
        }
        sparse spl(shl), spr(shr);
        auto Check = [&](int i, int j) {
            if (a[i] > b[j]) {
                return false;
            } else if (i == j) {
                return true;
            } else if (i < j) {
                return spl.get(i + 1, j + 1) == 1;
            } else {
                return spr.get(j, i) == 1;
            }
        };
        for (int i = 0; i < n; i++) {
            int low = -1;
            int high = i;
            while (high - low > 1) {
                int mid = (high + low) >> 1;
                if (Check(i, mid)) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
            cout << b[high] - a[i] << " \n"[i == n - 1];
        }
        for (int i = 0; i < n; i++) {
            int low = i;
            int high = n;
            while (high - low > 1) {
                int mid = (high + low) >> 1;
                if (Check(i, mid)) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            cout << b[low] - a[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}