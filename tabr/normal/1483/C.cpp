#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <class T>
struct segtree {
    int n;
    T ie = -5e18;
    vector<T> node;
    function<T(T, T)> f = [&](T a, T b) { return max(a, b); };

    segtree() : segtree(0) {}
    segtree(int _n) : segtree(vector<T>(_n, ie)) {}
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
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> h[i + 1];
    }
    vector<long long> b(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> b[i + 1];
    }
    long long inf = (long long)1e18;
    vector<long long> dp(n + 1, -inf);
    dp[0] = 0;
    segtree<long long> st(n + 1);
    st.update(0, 0);
    stack<int> stk;
    stk.emplace(0);
    for (int i = 1; i <= n; i++) {
        while (h[stk.top()] > h[i]) {
            stk.pop();
        }
        dp[i] = b[i] + st.get(stk.top(), i);
        if ((int)stk.size() != 1) {
            dp[i] = max(dp[i], dp[stk.top()]);
        }
        st.update(i, dp[i]);
        stk.emplace(i);
    }
    cout << dp[n] << '\n';
    return 0;
}