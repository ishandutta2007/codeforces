#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct segtree {
    using T = pair<long long, int>;
    using F = long long;
    int n;
    int size;
    int log_size;
    vector<T> node;
    vector<F> lazy;

    T e() {
        return make_pair(0, 0);
    }

    F id() {
        return 0;
    }

    T op(T a, T b) {
        return make_pair(a.first + b.first, a.second + b.second);
    }

    T mapping(F f, T x) {
        return make_pair(f * x.second + x.first, x.second);
    }

    F composition(F f, F g) {
        return f + g;
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
    int n, k;
    cin >> n >> k;
    vector<long long> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<pair<long long, int>> sdef(n, make_pair(0, 1));
    segtree seg(sdef);
    long long ans = 0;
    for (int i = n - 1; i >= k; i--) {
        long long c = b[i] - seg.get(i - k + 1, i + 1).first;
        if (c <= 0) {
            continue;
        }
        long long t = (c + k - 1) / k;
        seg.apply(i - k + 1, i + 1, t);
        ans += t;
    }
    long long t = 0;
    for (int i = 0; i < k; i++) {
        long long c = b[i] - seg.get(0, i + 1).first;
        if (c <= 0) {
            continue;
        }
        t = max(t, (c + i) / (i + 1));
    }
    ans += t;
    cout << ans << '\n';
    return 0;
}