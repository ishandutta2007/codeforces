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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
    }
    vector<int> a;
    vector<int> p(n, -1);
    for (int i = 0; i < n; i++) {
        if (l[i] != -1) {
            p[l[i]] = i;
        }
        if (r[i] != -1) {
            p[r[i]] = i;
        }
    }
    vector<int> beg(n), end(n), pos(n);
    function<void(int)> dfs = [&](int v) {
        if (v == -1) {
            return;
        }
        dfs(l[v]);
        a.emplace_back(v);
        dfs(r[v]);
    };
    dfs(0);
    vector<int> b(n, 1);
    char nn = (char) 96;
    vector<char> nxt(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i != n - 1 && s[a[i]] != s[a[i + 1]]) {
            nn = s[a[i + 1]];
        }
        nxt[a[i]] = nn;
    }
    debug(nxt);
    vector<int> was(n);
    vector<int> ng(n);
    for (int i : a) {
        was[i] = 1;
        if (!b[i] || ng[i]) {
            continue;
        }
        if (nxt[i] < s[i]) {
            function<void(int)> dfs2 = [&](int v) {
                if (v == -1 || ng[v]) {
                    return;
                }
                ng[v] = 1;
                dfs2(l[v]);
                dfs2(r[v]);
            };
            dfs2(r[i]);
            continue;
        }
        vector<int> c;
        int ok = 1;
        {
            int v = i;
            while (v != -1 && b[v] == 1) {
                if (s[v] > nxt[v] && was[v]) {
                    ok = 0;
                    break;
                }
                c.emplace_back(v);
                v = p[v];
            }
        }
        if (ok && k >= (int) c.size()) {
            k -= (int) c.size();
            for (int j : c) {
                b[j] = 0;
            }
        } else {
            function<void(int)> dfs2 = [&](int v) {
                if (v == -1 || ng[v]) {
                    return;
                }
                ng[v] = 1;
                dfs2(l[v]);
                dfs2(r[v]);
            };
            dfs2(i);
            if ((int) c.size() >= k) {
                reverse(c.begin(), c.end());
                dfs2(c[k]);
            }
        }
    }
    string ans;
    for (int i : a) {
        ans += string(2 - b[i], s[i]);
    }
    cout << ans << '\n';
    return 0;
}