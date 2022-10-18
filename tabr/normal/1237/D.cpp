#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <class T>
struct sparse {
    int n, h;
    vector<vector<T>> table;
    function<T(T, T)> func = [&](T x, T y) { return min(x, y); };

    sparse(vector<T> a) {
        n = (int)a.size();
        h = 32 - __builtin_clz(n);
        table.resize(h);
        table[0] = a;
        for (int j = 1; j < h; j++) {
            table[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                table[j][i] = func(table[j - 1][i], table[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    T get(int from, int to) const {  // [from, to]
        int k = 32 - __builtin_clz(to - from + 1) - 1;
        return func(table[k][from], table[k][to - (1 << k) + 1]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n * 2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    if ((*max_element(a.begin(), a.end()) + 1) / 2 <= *min_element(a.begin(), a.end())) {
        for (int i = 0; i < n; i++) {
            cout << -1 << " ";
        }
        cout << '\n';
        return 0;
    }
    sparse<int> st(a);
    vector<int> b(n * 2);
    for (int i = 0; i < n; i++) {
        int lo = i, hi = i + n;
        while (hi - lo > 1) {
            int mid = (hi + lo) / 2;
            if (st.get(i, mid) < (a[i] + 1) / 2) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        if (hi == i + n) {
            hi = (int)1e9;
        }
        b[i] = hi;
        b[i + n] = hi + n;
    }
    debug(a);
    debug(b);
    st = sparse<int>(b);
    for (int i = 0; i < n; i++) {
        cout << st.get(i, min(2 * n - 1, b[i])) - i << " ";
    }
    cout << '\n';
    return 0;
}