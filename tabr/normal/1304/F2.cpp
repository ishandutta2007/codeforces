#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

template <class T>
struct segtree {
    int n;
    T def = 1e9;
    vector<T> node, lazy;
    vector<bool> flag;
    function<T(T, T)> f = [](T a, T b) { return max(a, b); };  // node-node
    function<T(T, T)> g = [](T a, T b) { return a + b; };      // node-lazy if add a + b

    segtree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        node.resize(2 * n - 1);
        lazy.resize(2 * n - 1);
        flag.resize(2 * n - 1, false);
    }

    inline void eval(int k, int l, int r) {
        if (!flag[k]) return;
        node[k] = g(node[k], lazy[k]);
        if (r - l > 1) {
            lazy[k * 2 + 1] = g(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = g(lazy[k * 2 + 2], lazy[k]);
            flag[k * 2 + 1] = flag[k * 2 + 2] = true;
        }
        lazy[k] = 0;
        flag[k] = false;
    }
    inline void update(int a, int b, T v, int k, int l, int r) {
        eval(k, l, r);
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            lazy[k] = g(lazy[k], v);
            flag[k] = true;
            eval(k, l, r);
        } else {
            update(a, b, v, 2 * k + 1, l, (l + r) / 2);
            update(a, b, v, 2 * k + 2, (l + r) / 2, r);
            node[k] = f(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    inline T get(int a, int b, int k, int l, int r) {
        if (r < 0) r = n;
        eval(k, l, r);
        if (b <= l || r <= a) return def;
        if (a <= l && r <= b) return node[k];
        T vl = get(a, b, 2 * k + 1, l, (l + r) / 2);
        T vr = get(a, b, 2 * k + 2, (l + r) / 2, r);
        return f(vl, vr);
    }
    inline void update(int a, int b, T v) {
        update(a, b, v, 0, 0, n);
    }
    inline T get(int a, int b) {
        return get(a, b, 0, 0, n);
    }
    inline T get(int a) {
        return get(a, a + 1, 0, 0, n);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(m + 1)), s(n + 2, vector<int>(m + 1));
    vector<vector<int>> dp(n + 1, vector<int>(m - k + 2));
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            cin >> a[i][j];
            s[i][j] = a[i][j] + s[i][j - 1];
        }
    }
    int mm = m - k + 1;
    rep(i, 1, mm + 1) {
        dp[1][i] = s[1][i + k - 1] - s[1][i - 1] + s[2][i + k - 1] - s[2][i - 1];
    }
    rep(i, 2, n + 1) {
        segtree<int> t(mm + 2);
        rep(j, 1, mm + 1) t.update(j, j + 1, dp[i - 1][j]);
        rep(j, 1, k + 1) t.update(1, j + 1, -a[i][j]);
        rep(j, 1, mm + 1) {
            dp[i][j] = s[i][j + k - 1] - s[i][j - 1] + s[i + 1][j + k - 1] - s[i + 1][j - 1];
            dp[i][j] += t.get(0, t.n);
            if (j != mm) {
                t.update(max(j - k + 1, 1), j + 1, a[i][j]);
                t.update(j + 1, min(mm + 1, j + 1 + k), -a[i][j + k]);
            }
        }
    }
    cout << *max_element(dp[n].begin(), dp[n].end()) << endl;
    return 0;
}