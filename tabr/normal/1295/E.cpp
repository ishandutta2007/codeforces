#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"

template <class T>
struct LazySegmentTree {
    int n;
    T def;
    vector<T> node, lazy;
    vector<bool> flag;
    function<T(T, T)> func;

    LazySegmentTree(int _n, T _def, function<T(T, T)> _func)
        : def(_def), func(_func) {
        n = 1;
        while (n < _n) n *= 2;
        node.resize(2 * n - 1, def);
        lazy.resize(2 * n - 1, def);
        flag.resize(2 * n - 1, false);
    }

    LazySegmentTree(vector<T> a, T _def, function<T(T, T)> _func)
        : def(_def), func(_func) {
        n = 1;
        while (n < a.size()) n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1, 0);
        flag.resize(2 * n - 1, false);
        for (int i = 0; i < a.size(); i++) node[i + n - 1] = a[i];
        for (int i = n - 2; i >= 0; i--)
            node[i] = func(node[i * 2 + 1], node[i * 2 + 2]);
    }

    void eval(int k, int l, int r) {
        if (flag[k]) {
            node[k] += lazy[k];
            if (r - l > 1) {
                lazy[k * 2 + 1] += lazy[k];
                lazy[k * 2 + 2] += lazy[k];
                flag[k * 2 + 1] = flag[k * 2 + 2] = true;
            }
            lazy[k] = 0;
            flag[k] = false;
        }
    }

    void update(int a, int b, T v, int k, int l, int r) {
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] += v;
            flag[k] = true;
            eval(k, l, r);
        } else {
            update(a, b, v, 2 * k + 1, l, (l + r) / 2);
            update(a, b, v, 2 * k + 2, (l + r) / 2, r);
            node[k] = func(node[2 * k + 1], node[2 * k + 2]);
        }
    }

    T get(int a, int b, int k, int l, int r) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) return def;
        if (a <= l && r <= b) return node[k];
        T vl = get(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = get(a, b, 2 * k + 2, (l + r) / 2, r);
        return func(vl, vr);
    }

    void update(int a, int b, T v) {
        update(a, b, v, 0, 0, n);
    }

    T get(int a, int b) {
        return get(a, b, 0, 0, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> p(n), a(n), s(n), q(n);
    rep(i, 0, n) {
        cin >> p[i];
        p[i]--;
        q[p[i]] = i;
    }
    rep(i, 0, n) {
        cin >> a[i];
        s[i] = a[i];
        if (i) s[i] += s[i - 1];
    }
    auto func = [](ll a, ll b) { return min(a, b); };
    LazySegmentTree<ll> st(s, 1e18, func);
    ll ans = a[0];
    rep(i, 0, n) {
        int k = q[i];
        st.update(0, k, a[k]);
        st.update(k, n, -a[k]);
        ans = min(ans, st.get(0, n - 1));
    }
    cout << ans << endl;
    return 0;
}