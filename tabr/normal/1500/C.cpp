#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int N = 1515;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m + 1));
    vector<vector<int>> b(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            a[i][j]--;
        }
        a[i][m] = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            b[i][j]--;
        }
        int it = (int)(lower_bound(a.begin(), a.end(), b[i]) - a.begin());
        if (it == n) {
            cout << -1 << '\n';
            return 0;
        }
        for (int j = 0; j < m; j++) {
            if (a[it][j] != b[i][j]) {
                cout << -1 << '\n';
                return 0;
            }
        }
        b[i][m] = a[it][m];
        a[it][m] = -1;
        assert(b[i][m] >= 0);
    }
    m++;
    vector<bitset<N>> c(m);
    vector<bitset<N>> d(m);
    for (int i = 0; i < m; i++) {
        int pre = 100000000;
        for (int j = 0; j < n; j++) {
            if (b[j][i] < pre) {
                c[i][j] = true;
            }
            if (b[j][i] != pre) {
                d[i][j] = true;
            }
            pre = b[j][i];
        }
    }
    d.emplace_back(bitset<N>().flip(0));
    // vector<vector<bool>> g(m + 1, vector<bool>(m, true));
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (i == j) {
    //             g[i][j] = false;
    //         }
    //         bitset<N> e = ~d[i];
    //         e &= c[j];
    //         if (e.count()) {
    //             g[i][j] = false;
    //         }
    //     }
    // }
    // for (int i = 0; i < m; i++) {
    //     if ((int)c[i].count() != 1) {
    //         g[m][i] = false;
    //     }
    // }
    // debug(g);
    // debug(c);
    // debug(d);
    stack<int> st;
    vector<bool> vis(m + 1);
    function<void(int, bitset<N>)> dfs = [&](int v, bitset<N> x) {
        if (v != m - 1) {
            st.emplace(v);
            vis[v] = true;
        }
        bitset<N> y = x;
        y |= d[v];
        if ((int)y.count() == n) {
            cout << st.size() - 1 << '\n';
            while (st.top() != m) {
                cout << st.top() + 1 << " ";
                st.pop();
            }
            cout << '\n';
            exit(0);
        }
        if (v == m - 1) {
            return;
        }
        for (int to = 0; to < m; to++) {
            if (vis[to]) {
                continue;
            }
            bitset<N> e = ~y;
            e &= c[to];
            if (e.count()) {
                continue;
            }
            dfs(to, y);
        }
        vis[v] = false;
        st.pop();
    };
    dfs(m, bitset<N>());
    cout << -1 << '\n';
    return 0;
}