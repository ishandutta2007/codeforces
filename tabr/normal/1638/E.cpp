#ifndef tabr
#pragma GCC target("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#endif
#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <typename T>
struct fenwick {
    int n;
    vector<T> node;

    fenwick(int _n) : n(_n) {
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
    int n, q;
    scanf("%d%d", &n, &q);
    fenwick<long long> f(n + 10);
    set<pair<int, int>> st;
    st.emplace(-1, -1);
    st.emplace(0, 0);
    st.emplace(n, -1);
    auto add = [&](int l, int r, long long x) {
        f.add(l, x);
        f.add(r, -x);
    };
    vector<long long> c(n + 10);
    while (q--) {
        char op[10];
        scanf("%s", op);
        if (op[0] == 'C') {
            int l, r, z;
            scanf("%d%d%d", &l, &r, &z);
            l--, z--;
            {
                auto iter = prev(st.upper_bound(make_pair(l + 1, -10)));
                st.emplace(l, iter->second);
            }
            {
                auto iter = prev(st.upper_bound(make_pair(r + 1, -10)));
                st.emplace(r, iter->second);
            }
            while (true) {
                auto iter = st.lower_bound(make_pair(l, -10));
                if (iter->first >= r) {
                    break;
                }
                add(iter->first, next(iter)->first, c[iter->second]);
                st.erase(iter);
            }
            st.emplace(l, z);
            add(l, r, -c[z]);
        } else if (op[0] == 'A') {
            int z, x;
            scanf("%d%d", &z, &x);
            z--;
            c[z] += x;
        } else {
            int x;
            scanf("%d", &x);
            x--;
            long long ans = f.get(x);
            auto iter = prev(st.upper_bound(make_pair(x + 1, -10)));
            ans += c[iter->second];
            printf("%lld\n", ans);
        }
    }
    return 0;
}