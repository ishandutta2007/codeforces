#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct min_segtree {
    using T = pair<long long, long long>;

    int n;
    vector<T> node;

    T e() {
        return T{(long long) 1e18, 0};
    }

    T op(T x, T y) {
        if (x.first == y.first) {
            x.second += y.second;
            return x;
        }
        return min(x, y);
    }

    min_segtree() : min_segtree(0) {}
    min_segtree(int _n) {
        if (_n <= 1) {
            n = _n;
        } else {
            n = 1 << (32 - __builtin_clz(_n - 1));
        }
        node.resize(2 * n, e());
    }
    min_segtree(vector<T> v) {
        if ((int) v.size() <= 1) {
            n = (int) v.size();
        } else {
            n = 1 << (32 - __builtin_clz((int) v.size() - 1));
        }
        node.resize(2 * n, e());
        for (int i = 0; i < (int) v.size(); i++) {
            node[i + n] = v[i];
        }
        for (int i = n - 1; i > 0; i--) {
            node[i] = op(node[2 * i], node[2 * i + 1]);
        }
    }

    void update(int k, T v) {
        k += n;
        node[k] = v;  // update
        // node[k] += v;  // add
        while (k > 1) {
            k /= 2;
            node[k] = op(node[2 * k], node[2 * k + 1]);
        }
    }

    T get(int x, int y, int k, int l, int r) {
        if (r <= x || y <= l) {
            return e();
        }
        if (x <= l && r <= y) {
            return node[k];
        }
        T vl = get(x, y, 2 * k, l, (l + r) / 2);
        T vr = get(x, y, 2 * k + 1, (l + r) / 2, r);
        return op(vl, vr);
    }

    T get(int x, int y) {
        return get(x, y, 1, 0, n);
    }

    T get(int x) {
        return node[x + n];
    }

    template <class G>
    int find_first(int r, G g) {
        assert(g(e()));
        int k = r + n;
        T x = e();
        get(r - 1);
        do {
            k--;
            while (k > 1 && k % 2 == 1) {
                k /= 2;
            }
            if (!g(op(node[k], x))) {
                while (k < n - 1) {
                    k = 2 * k + 1;
                    if (g(op(node[k], x))) {
                        x = op(node[k], x);
                        k--;
                    }
                }
                return k - n + 1;
            }
            x = op(node[k], x);
        } while ((k & -k) != k);
        return 0;
    }
};

struct max_segtree {
    using T = pair<long long, long long>;

    int n;
    vector<T> node;

    T e() {
        return T{(long long) -1e18, 0};
    }

    T op(T x, T y) {
        if (x.first == y.first) {
            x.second += y.second;
            return x;
        }
        return max(x, y);
    }

    max_segtree() : max_segtree(0) {}
    max_segtree(int _n) {
        if (_n <= 1) {
            n = _n;
        } else {
            n = 1 << (32 - __builtin_clz(_n - 1));
        }
        node.resize(2 * n, e());
    }
    max_segtree(vector<T> v) {
        if ((int) v.size() <= 1) {
            n = (int) v.size();
        } else {
            n = 1 << (32 - __builtin_clz((int) v.size() - 1));
        }
        node.resize(2 * n, e());
        for (int i = 0; i < (int) v.size(); i++) {
            node[i + n] = v[i];
        }
        for (int i = n - 1; i > 0; i--) {
            node[i] = op(node[2 * i], node[2 * i + 1]);
        }
    }

    void update(int k, T v) {
        k += n;
        node[k] = v;  // update
        // node[k] += v;  // add
        while (k > 1) {
            k /= 2;
            node[k] = op(node[2 * k], node[2 * k + 1]);
        }
    }

    T get(int x, int y, int k, int l, int r) {
        if (r <= x || y <= l) {
            return e();
        }
        if (x <= l && r <= y) {
            return node[k];
        }
        T vl = get(x, y, 2 * k, l, (l + r) / 2);
        T vr = get(x, y, 2 * k + 1, (l + r) / 2, r);
        return op(vl, vr);
    }

    T get(int x, int y) {
        return get(x, y, 1, 0, n);
    }

    T get(int x) {
        return node[x + n];
    }

    template <class G>
    int find_first(int r, G g) {
        assert(g(e()));
        int k = r + n;
        T x = e();
        get(r - 1);
        do {
            k--;
            while (k > 1 && k % 2 == 1) {
                k /= 2;
            }
            if (!g(op(node[k], x))) {
                while (k < n - 1) {
                    k = 2 * k + 1;
                    if (g(op(node[k], x))) {
                        x = op(node[k], x);
                        k--;
                    }
                }
                return k - n + 1;
            }
            x = op(node[k], x);
        } while ((k & -k) != k);
        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i += 2) {
            a[i] *= -1;
        }
        vector<long long> pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        min_segtree minseg(n + 10);
        max_segtree maxseg(n + 10);
        long long ans = 0;
        for (int i = 0; i <= n; i++) {
            int x = minseg.find_first(i, [&](pair<long long, long long> z) { return z.first >= pref[i]; });
            int y = maxseg.find_first(i, [&](pair<long long, long long> z) { return z.first <= pref[i]; });
            x = max(x, y);
            auto b = minseg.get(x, i);
            auto c = maxseg.get(x, i);
            if (b.first == pref[i]) {
                ans += b.second;
            }
            if (c.first == pref[i]) {
                ans += c.second;
            }
            if (i % 2 == 0) {
                maxseg.update(i, {pref[i], 1});
            } else {
                minseg.update(i, {pref[i], 1});
            }
        }
        cout << ans << '\n';
    }
    return 0;
}