#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <class T>
struct fenwick {
    vector<T> node;
    int n;

    fenwick(int _n)
        : n(_n) {
        node.resize(n);
    }

    void add(int x, T v) {
        while (x < n) {
            node[x] += v;
            x |= (x + 1);
        }
    }
    T get(int x) {  // [0, x]
        T v = 0;
        while (x >= 0) {
            v += node[x];
            x = (x & (x + 1)) - 1;
        }
        return v;
    }
    T get(int x, int y) {  // [x, y]
        return (get(y) - (x ? get(x - 1) : 0));
    }
    int lower_bound(T v) {
        int x = 0;
        int h = 1;
        while (n >= (h << 1)) {
            h <<= 1;
        }
        for (int k = h; k > 0; k >>= 1) {
            if (x + k <= n && node[x + k - 1] < v) {
                v -= node[x + k - 1];
                x += k;
            }
        }
        return x;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fenwick<ll> bt(1000001);
    bt.add(0, 1);
    bt.add(1000000, 1);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> add, del;
    for (int i = 0; i < n; i++) {
        int y, l, r;
        cin >> y >> l >> r;
        if (l == 0) {
            bt.add(y, 1);
            del.emplace_back(r, y);
        } else {
            add.emplace_back(l, y);
        }
    }
    add.emplace_back(1e7, -1);
    del.emplace_back(1e7, -1);
    sort(add.begin(), add.end());
    sort(del.begin(), del.end());
    vector<vector<int>> t(m + 2, vector<int>(3));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> t[i][j];
        }
    }
    t[m] = {1000000, 0, 1000000};
    t[m + 1] = {10000000, -1, -1};
    sort(t.begin(), t.end());
    ll ans = 0;
    int pa = 0, pd = 0, pt = 0;
    set<int> st;
    while (true) {
        int x = min({add[pa].first, del[pd].first, t[pt][0]});
        if (x == 1e7) {
            break;
        }
        while (add[pa].first == x) {
            st.emplace(add[pa].second);
            pa++;
        }
        while (t[pt][0] == x) {
            ans += bt.get(t[pt][1], t[pt][2]) - 1;
            while (!st.empty()) {
                ll y = *st.begin();
                if (t[pt][1] <= y && y <= t[pt][2]) {
                    bt.add(y, 1);
                    st.erase(y);
                } else {
                    break;
                }
            }
            while (!st.empty()) {
                ll y = *st.rbegin();
                if (t[pt][1] <= y && y <= t[pt][2]) {
                    bt.add(y, 1);
                    st.erase(y);
                } else {
                    break;
                }
            }
            pt++;
        }
        while (del[pd].first == x) {
            bt.add(del[pd].second, -1);
            pd++;
        }
    }
    cout << ans << '\n';
    return 0;
}