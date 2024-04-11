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

struct sparse {
    using T = pair<int, int>;
    int n;
    int h;
    vector<vector<T>> table;

    T op(T x, T y) {
        return max(x, y);
    }

    sparse(const vector<T>& v) {
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

struct segtree {
    using T = tuple<long long, long long, long long>;
    using F = pair<long long, long long>;
    int n;
    int size;
    int log_size;
    vector<T> node;
    vector<F> lazy;

    T e() {
        return make_tuple(0LL, 0LL, 0LL);
    }

    F id() {
        return make_pair(0LL, 0LL);
    }

    T op(T a, T b) {
        std::get<0>(a) += std::get<0>(b);
        std::get<1>(a) += std::get<1>(b);
        std::get<2>(a) += std::get<2>(b);
        return a;
    }

    T mapping(F f, T x) {
        std::get<0>(x) += std::get<2>(x) * f.first;
        std::get<1>(x) += std::get<2>(x) * f.second;
        return x;
    }

    F composition(F f, F g) {
        f.first += g.first;
        f.second += g.second;
        return f;
    }

    segtree() : segtree(0) {}
    segtree(int _n) {
        build(vector<T>(_n, e()));
    }
    segtree(const vector<T>& v) {
        build(v);
    }

    void build(const vector<T>& v) {
        n = (int) v.size();
        if (n <= 1) {
            log_size = 0;
        } else {
            log_size = 32 - __builtin_clz(n - 1);
        }
        size = 1 << log_size;
        node.resize(2 * size, e());
        lazy.resize(size, id());
        for (int i = 0; i < n; i++) {
            node[i + size] = v[i];
        }
        for (int i = size - 1; i > 0; i--) {
            pull(i);
        }
    }

    void push(int x) {
        node[2 * x] = mapping(lazy[x], node[2 * x]);
        node[2 * x + 1] = mapping(lazy[x], node[2 * x + 1]);
        if (2 * x < size) {
            lazy[2 * x] = composition(lazy[x], lazy[2 * x]);
            lazy[2 * x + 1] = composition(lazy[x], lazy[2 * x + 1]);
        }
        lazy[x] = id();
    }

    void pull(int x) {
        node[x] = op(node[2 * x], node[2 * x + 1]);
    }

    void set(int p, T v) {
        assert(0 <= p && p < n);
        p += size;
        for (int i = log_size; i >= 1; i--) {
            push(p >> i);
        }
        node[p] = v;
        for (int i = 1; i <= log_size; i++) {
            pull(p >> i);
        }
    }

    T get(int p) {
        assert(0 <= p && p < n);
        p += size;
        for (int i = log_size; i >= 1; i--) {
            push(p >> i);
        }
        return node[p];
    }

    T get(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        l += size;
        r += size;
        for (int i = log_size; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                push(l >> i);
            }
            if (((r >> i) << i) != r) {
                push((r - 1) >> i);
            }
        }
        T vl = e();
        T vr = e();
        while (l < r) {
            if (l & 1) {
                vl = op(vl, node[l++]);
            }
            if (r & 1) {
                vr = op(node[--r], vr);
            }
            l >>= 1;
            r >>= 1;
        }
        return op(vl, vr);
    }

    void apply(int p, F f) {
        assert(0 <= p && p < n);
        p += size;
        for (int i = log_size; i >= 1; i--) {
            push(p >> i);
        }
        node[p] = mapping(f, node[p]);
        for (int i = 1; i <= log_size; i++) {
            pull(p >> i);
        }
    }

    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= n);
        l += size;
        r += size;
        for (int i = log_size; i >= 1; i--) {
            if (((l >> i) << i) != l) {
                push(l >> i);
            }
            if (((r >> i) << i) != r) {
                push((r - 1) >> i);
            }
        }
        int ll = l;
        int rr = r;
        while (l < r) {
            if (l & 1) {
                node[l] = mapping(f, node[l]);
                if (l < size) {
                    lazy[l] = composition(f, lazy[l]);
                }
                l++;
            }
            if (r & 1) {
                r--;
                node[r] = mapping(f, node[r]);
                if (l < size) {
                    lazy[r] = composition(f, lazy[r]);
                }
            }
            l >>= 1;
            r >>= 1;
        }
        l = ll;
        r = rr;
        for (int i = 1; i <= log_size; i++) {
            if (((l >> i) << i) != l) {
                pull(l >> i);
            }
            if (((r >> i) << i) != r) {
                pull((r - 1) >> i);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<int> pos(n + 1, -1);
    for (int i = 0; i < n; i++) {
        pos[p[i]] = i;
    }
    vector<vector<int>> div(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; i * j <= n; j++) {
            div[i * j].emplace_back(i);
        }
    }
    vector<pair<int, int>> sdef(n);
    for (int i = 0; i < n; i++) {
        sdef[i] = make_pair(p[i], i);
    }
    sparse sp(sdef);
    vector<vector<tuple<int, int, long long, long long>>> events(n + 1);
    function<void(int, int)> Dfs = [&](int l, int r) {
        if (l >= r) {
            return;
        }
        auto v = sp.get(l, r);
        Dfs(l, v.second);
        Dfs(v.second + 1, r);
        vector<pair<int, int>> c;
        for (int i : div[v.first]) {
            if (l <= pos[i] && pos[i] < r) {
                c.emplace_back(pos[i], i);
            }
        }
        sort(c.begin(), c.end());
        int sz = (int) c.size();
        c.emplace_back(r, -1);
        int j = sz - 1;
        unordered_set<int> st;
        for (int i = sz - 1; i >= 0; i--) {
            for (; j >= 0; j--) {
                st.emplace(c[j].second);
                if (!st.count(v.first)) {
                    continue;
                }
                bool ok = false;
                for (int k : st) {
                    if (v.first / k != k && st.count(v.first / k)) {
                        ok = true;
                    }
                }
                if (ok) {
                    events[c[i].first].emplace_back(l, c[j].first + 1, 1, 1 - c[i].first);
                    events[c[i + 1].first].emplace_back(l, c[j].first + 1, -1, -1 + c[i + 1].first);
                    break;
                }
            }
            if (j == -1 || c[i].second == v.first) {
                break;
            }
            st.erase(c[i].second);
        }
    };
    Dfs(0, n);
    vector<vector<pair<int, int>>> que(n);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        que[r].emplace_back(l, i);
    }
    vector<long long> ans(q);
    segtree seg(vector<tuple<long long, long long, long long>>(n, make_tuple(0LL, 0LL, 1LL)));
    for (int i = 0; i < n; i++) {
        for (auto [l, r, x, y] : events[i]) {
            seg.apply(l, r, make_pair(x, y));
        }
        for (auto [j, id] : que[i]) {
            auto t = seg.get(j, i + 1);
            ans[id] = get<0>(t) * i + get<1>(t);
        }
    }
    for (auto i : ans) {
        cout << i << '\n';
    }
    return 0;
}