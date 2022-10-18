#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct dsu {
    vector<int> p;
    vector<int> sz;
    int n;

    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }

    inline int get(int x) {
        if (p[x] == x) {
            return x;
        } else {
            return p[x] = get(p[x]);
        }
    }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x == y) {
            return false;
        }
        if (sz[x] > sz[y]) {
            swap(x, y);
        }
        p[x] = y;
        sz[y] += sz[x];
        return true;
    }

    inline bool same(int x, int y) {
        return (get(x) == get(y));
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int MAX = 1000010;
    vector<int> primes;
    vector<int> spf(MAX);
    vector<bool> is_prime(MAX, true);
    is_prime[0] = is_prime[1] = false;
    spf[0] = spf[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (!is_prime[i]) {
            continue;
        }
        primes.emplace_back(i);
        spf[i] = i;
        if (1LL * i * i >= MAX) {
            continue;
        }
        for (int j = i * i; j < MAX; j += i) {
            if (is_prime[j]) {
                is_prime[j] = false;
                spf[j] = i;
            }
        }
    }
    function<vector<pair<int, int>>(int)> factor = [&](int n) {
        vector<pair<int, int>> res;
        while (n != 1) {
            int p = spf[n];
            res.emplace_back(p, 0);
            while (p == spf[n]) {
                n /= p;
                res.back().second++;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    };
    int n, tt;
    cin >> n >> tt;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dsu uf(n + MAX);
    vector<vector<pair<int, int>>> f(n);
    for (int i = 0; i < n; i++) {
        f[i] = factor(a[i]);
        for (auto p : f[i]) {
            uf.unite(i, n + p.first);
        }
    }
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        auto g = factor(a[i] + 1);
        for (auto p : f[i]) {
            for (auto q : g) {
                int x = uf.get(p.first + n);
                int y = uf.get(q.first + n);
                if (x != y) {
                    if (x > y) {
                        swap(x, y);
                    }
                    st.emplace(x, y);
                }
            }
        }
        for (auto p : g) {
            for (auto q : g) {
                int x = uf.get(p.first + n);
                int y = uf.get(q.first + n);
                if (x != y) {
                    if (x > y) {
                        swap(x, y);
                    }
                    st.emplace(x, y);
                }
            }
        }
    }
    while (tt--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        if (uf.same(x, y)) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 2;
        for (auto p : f[x]) {
            for (auto q : f[y]) {
                int s = uf.get(p.first + n);
                int t = uf.get(q.first + n);
                if (s != t) {
                    if (s > t) {
                        swap(s, t);
                    }
                    if (st.count(make_pair(s, t))) {
                        ans = 1;
                        break;
                    }
                }
            }
            if (ans == 1) {
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}