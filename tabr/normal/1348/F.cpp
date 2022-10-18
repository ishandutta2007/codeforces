#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <class T>
struct sparse {
    int n, h;
    vector<vector<T>> table;
    function<T(T, T)> func;

    sparse(vector<T> a, function<T(T, T)> f) {
        n = a.size();
        func = f;
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
    vector<int> a(n), b(n);
    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        p[a[i]].emplace_back(i);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> ans(n);
    vector<int> c(n), l(n), r(n);
    for (int i = 0; i < n; i++) {
        for (int j : p[i]) {
            pq.emplace(b[j], j);
        }
        pair<int, int> t = pq.top();
        pq.pop();
        ans[t.second] = i;
        c[i] = t.second;
        l[i] = a[t.second];
        r[i] = b[t.second];
    }
    sparse<int> s(l, [&](int a, int b) { return min(a, b); });
    sparse<int> t(r, [&](int a, int b) { return max(a, b); });
    debug(l, r);
    for (int i = 0; i < n; i++) {
        pair<int, int> sw = {-1, i};
        if (i + 1 <= r[i] && s.get(i + 1, r[i]) <= i) {
            for (int j = i + 1; j <= r[i]; j++) {
                if (l[j] <= i) {
                    sw.first = j;
                    break;
                }
            }
        }
        if (i <= i - 1 && t.get(l[i], i - 1) >= i) {
            for (int j = i - 1; j >= l[i]; j--) {
                if (r[j] >= i) {
                    sw.first = j;
                    break;
                }
            }
        }
        if (sw.first != -1) {
            debug(sw, i);
            cout << "NO" << '\n';
            for (int j : ans) {
                cout << j + 1 << " ";
            }
            cout << '\n';
            swap(ans[c[sw.first]], ans[c[sw.second]]);
            for (int j : ans) {
                cout << j + 1 << " ";
            }
            cout << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';
    for (int i : ans) {
        cout << i + 1 << " ";
    }
    cout << '\n';
    return 0;
}