#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct segtree {
    using S = pair<long long, int>;
    using F = long long;

    function<S()> e = [&]() {
        return S{(long long)-1e18, -1};
    };

    function<F()> id = [&]() {
        return 0;
    };

    function<S(S, S)> op = [&](S a, S b) {
        return max(a, b);
    };

    function<S(F, S)> mapping = [&](F f, S x) {
        x.first += f;
        return x;
    };

    function<F(F, F)> composition = [&](F f, F g) {
        return f + g;
    };

    int n;
    vector<S> node;
    vector<F> lazy;
    vector<bool> flag;

    segtree() : segtree(0) {}
    segtree(int _n) {
        n = 1 << (32 - __builtin_clz(_n - 1));
        node.resize(2 * n - 1, e());
        lazy.resize(2 * n - 1, id());
        flag.resize(2 * n - 1);
    }
    segtree(vector<S> v) {
        n = 1 << (32 - __builtin_clz((int)v.size() - 1));
        node.resize(2 * n - 1, e());
        lazy.resize(2 * n - 1, id());
        flag.resize(2 * n - 1);
        for (int i = 0; i < (int)v.size(); i++) {
            node[i + n - 1] = v[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            node[i] = op(node[i * 2 + 1], node[i * 2 + 2]);
        }
    }

    void eval(int x, int l, int r) {
        if (!flag[x]) {
            return;
        }
        node[x] = mapping(lazy[x], node[x]);
        if (r - l > 1) {
            lazy[x * 2 + 1] = composition(lazy[x], lazy[x * 2 + 1]);
            lazy[x * 2 + 2] = composition(lazy[x], lazy[x * 2 + 2]);
            flag[x * 2 + 1] = flag[x * 2 + 2] = true;
        }
        lazy[x] = id();
        flag[x] = false;
    }

    void update(int a, int b, F v, int x, int l, int r) {
        eval(x, l, r);
        if (b <= l || r <= a) {
            return;
        }
        if (a <= l && r <= b) {
            lazy[x] = composition(v, lazy[x]);
            flag[x] = true;
            eval(x, l, r);
        } else {
            update(a, b, v, 2 * x + 1, l, (l + r) / 2);
            update(a, b, v, 2 * x + 2, (l + r) / 2, r);
            node[x] = op(node[2 * x + 1], node[2 * x + 2]);
        }
    }

    S get(int a, int b, int x, int l, int r) {
        eval(x, l, r);
        if (b <= l || r <= a) {
            return e();
        }
        if (a <= l && r <= b) {
            return node[x];
        }
        S vl = get(a, b, 2 * x + 1, l, (l + r) / 2);
        S vr = get(a, b, 2 * x + 2, (l + r) / 2, r);
        return op(vl, vr);
    }

    void update(int a, int b, F v) {
        update(a, b, v, 0, 0, n);
    }

    S get(int a, int b) {
        return get(a, b, 0, 0, n);
    }

    S get(int a) {
        return get(a, a + 1, 0, 0, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> s(n);
    vector<int> p;
    for (int i = 0; i < n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        if (x > y) {
            swap(x, y);
        }
        s[i] = {x, y, c};
        p.emplace_back(x);
        p.emplace_back(y);
    }
    sort(s.begin(), s.end(), [&](auto i, auto j) {
        return get<1>(i) < get<1>(j);
    });
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    int m = (int)p.size();
    vector<pair<long long, int>> ss(m);
    for (int i = 0; i < m; i++) {
        ss[i] = {p[i], i};
    }
    segtree st(ss);
    long long ans = 0;
    int mn = (int)2e9, mx = (int)2e9;
    for (int i = 0; i < n; i++) {
        auto [x, y, c] = s[i];
        x = (int)(lower_bound(p.begin(), p.end(), x) - p.begin());
        y = (int)(lower_bound(p.begin(), p.end(), y) - p.begin());
        st.update(0, x + 1, c);
        if (i == n - 1 || get<1>(s[i + 1]) != p[y]) {
            long long t = st.get(0, y + 1).first - p[y];
            if (ans < t) {
                ans = t;
                mn = p[st.get(0, y + 1).second];
                mx = p[y];
            }
        }
    }
    cout << ans << '\n';
    cout << mn << " " << mn << " " << mx << " " << mx << '\n';
    return 0;
}