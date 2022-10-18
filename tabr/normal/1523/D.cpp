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
    int n, m, p;
    cin >> n >> m >> p;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> c(m);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') {
                a[i][j] = 1;
                c[j]++;
            }
        }
    }
    vector<int> b;
    for (int j = 0; j < m; j++) {
        if (c[j] >= (n + 1) / 2) {
            b.emplace_back(j);
        }
    }
    int k = (int) b.size();
    map<int, int> dp;
    set<int> st;
    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (int j = 0; j < k; j++) {
            if (a[i][b[j]]) {
                mask ^= 1 << j;
            }
        }
        dp[mask]++;
        st.emplace(mask);
    }
    debug(dp);
    vector<int> z;
    while (!st.empty()) {
        int i = *st.rbegin();
        st.erase(i);
        z.emplace_back(i);
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                st.emplace(i ^ (1 << j));
            }
        }
    }
    sort(z.begin(), z.end(), [&](int i, int j) {
        return __builtin_popcount(i) > __builtin_popcount(j);
    });
    for (int i : z) {
        st.emplace(i);
    }
    for (int i = 0; i < k; i++) {
        for (int j : z) {
            if (j & (1 << i)) {
                assert(st.count(j ^ (1 << i)));
                dp[j ^ (1 << i)] += dp[j];
            }
        }
    }
    debug(dp);
    int ans = 0;
    for (int i : z) {
        if (dp[i] >= (n + 1) / 2) {
            ans = i;
            break;
        }
    }
    string res(m, '0');
    for (int i = 0; i < k; i++) {
        if (ans & (1 << i)) {
            res[b[i]] = '1';
        }
    }
    cout << res << '\n';
    return 0;
}