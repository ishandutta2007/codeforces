#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <class T>
vector<int> compress(vector<T> a) {
    vector<T> t = a;
    sort(t.begin(), t.end());
    t.resize(unique(t.begin(), t.end()) - t.begin());
    int n = (int)a.size();
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = lower_bound(t.begin(), t.end(), a[i]) - t.begin();
    }
    return res;
}

template <class T>
struct segtree {
    int n;
    T ie = 1e9;
    vector<T> node;
    function<T(T, T)> f = [&](T a, T b) { return min(a, b); };

    segtree() : segtree(0) {}
    segtree(int _n) : segtree(vector<T>(_n, 0)) {}
    segtree(vector<T> v) {
        n = 1 << (32 - __builtin_clz((int)v.size() - 1));
        node.resize(2 * n - 1, ie);
        for (int i = 0; i < (int)v.size(); i++) {
            node[i + n - 1] = v[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            node[i] = f(node[2 * i + 1], node[2 * i + 2]);
        }
    }

    void update(int x, T v) {
        x += n - 1;
        node[x] = v;  // update
        // node[x] += v;  // add
        while (x > 0) {
            x = (x - 1) / 2;
            node[x] = f(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    T get(int a, int b, int x, int l, int r) {
        if (r <= a || b <= l) {
            return ie;
        }
        if (a <= l && r <= b) {
            return node[x];
        }
        T vl = get(a, b, 2 * x + 1, l, (l + r) / 2);
        T vr = get(a, b, 2 * x + 2, (l + r) / 2, r);
        return f(vl, vr);
    }

    T get(int a, int b) {
        return get(a, b, 0, 0, n);
    }

    T get(int a) {
        return node[a + n - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 2);
    vector<int> b(k + 2);
    a[0] = -1e9;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    a[n + 1] = 2e9;
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
    }
    b[k + 1] = n + 1;
    int ans = 0;
    for (int i = 0; i <= k; i++) {
        if (a[b[i + 1]] < a[b[i]]) {
            cout << -1 << '\n';
            return 0;
        }
        int t = 0;
        vector<int> c;
        for (int j = b[i] + 1; j < b[i + 1]; j++) {
            if (a[b[i]] <= a[j] && a[j] <= a[b[i + 1]]) {
                c.emplace_back(a[j]);
            } else {
                t++;
            }
        }
        ans += t;
        if (c.empty()) {
            continue;
        }
        c = compress(c);
        debug(c);
        int m = (int)c.size();
        segtree<int> st(m);
        for (int s : c) {
            st.update(s, st.get(0, s + 1) - 1);
        }
        ans += m + st.node[0];
    }
    cout << ans << '\n';
    return 0;
}