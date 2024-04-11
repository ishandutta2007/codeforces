#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

long long max_set(vector<vector<bool>> g) {
    int n = g.size();
    int m = n / 2;
    vector<bool> a(1 << m, true);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j]) {
                a[(1 << i) | (1 << j)] = false;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (1 << m); j++) {
            if (j & (1 << i)) {
                if (!a[j - (1 << i)]) {
                    a[j] = false;
                }
            }
        }
    }
    vector<int> b(1 << m, (1 << (n - m)) - 1);
    for (int i = 0; i < m; i++) {
        for (int j = m; j < n; j++) {
            if (g[i][j]) {
                b[1 << i] ^= 1 << (j - m);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (1 << m); j++) {
            if (j & (1 << i)) {
                b[j] &= b[j ^ (1 << i)];
            }
        }
    }
    vector<int> c(1 << (n - m), 1);
    for (int i = m; i < n; i++) {
        for (int j = m; j < n; j++) {
            if (g[i][j]) {
                c[(1 << (i - m)) | (1 << (j - m))] = 0;
            }
        }
    }
    for (int i = m; i < n; i++) {
        for (int j = 0; j < (1 << (n - m)); j++) {
            if (j & (1 << (i - m))) {
                if (!c[j ^ (1 << (i - m))]) {
                    c[j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < (1 << (n - m)); i++) {
        if (c[i]) {
            c[i] = i;
        }
    }
    for (int i = m; i < n; i++) {
        for (int j = 0; j < (1 << (n - m)); j++) {
            if (j & (1 << (i - m))) {
                if (__builtin_popcount(c[j]) < __builtin_popcount(c[j ^ (1 << (i - m))])) {
                    c[j] = c[j ^ (1 << (i - m))];
                }
            }
        }
    }
    long long res = 0;
    debug(a, b, c);
    for (int i = 0; i < (1 << m); i++) {
        if (a[i]) {
            long long tmp = c[b[i]];
            tmp <<= m;
            tmp += i;
            if (__builtin_popcountll(res) < __builtin_popcountll(tmp)) {
                res = tmp;
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, id = 1;
    cin >> n >> m;
    map<string, int> mp;
    set<int> st;
    vector<vector<bool>> g(m, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            for (int j : st) {
                for (int k : st) {
                    if (j != k) {
                        g[j - 1][k - 1] = g[k - 1][j - 1] = true;
                    }
                }
            }
            st.clear();
        } else {
            string s;
            cin >> s;
            if (mp[s] == 0) {
                mp[s] = id;
                id++;
            }
            st.emplace(mp[s]);
        }
    }
    for (int j : st) {
        for (int k : st) {
            if (j != k) {
                g[j - 1][k - 1] = g[k - 1][j - 1] = true;
            }
        }
    }
    st.clear();
    debug(g);
    ll mx = max_set(g);
    debug(mx);
    cout << __builtin_popcountll(mx) << '\n';
    return 0;
}