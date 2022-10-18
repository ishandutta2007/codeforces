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
    const int m = 200;
    vector<int> g(m);
    g[0] = 0;
    g[1] = 1;
    for (int i = 2; i < m; i++) {
        set<int> st;
        for (int j = 0; j < i; j++) {
            st.emplace(g[max(0, j - 1)] ^ g[max(0, i - 2 - j)]);
        }
        while (st.count(g[i])) {
            g[i]++;
        }
    }
    debug(g);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> c(2);
        for (int i = 0; i < n; i++) {
            c[s[i] == 'B']++;
        }
        if (c[0] > c[1]) {
            cout << "Alice" << '\n';
            continue;
        } else if (c[0] < c[1]) {
            cout << "Bob" << '\n';
            continue;
        }
        vector<int> d;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && (s[i] == s[j]) == (i % 2 == j % 2)) {
                j++;
            }
            if (j - i - 1 > 0) {
                d.emplace_back(j - i - 1);
            }
        }
        int ans = 0;
        for (int i : d) {
            if (i < 100) {
                ans ^= g[i];
            } else {
                i %= 34;
                i += 34 * 3;
                ans ^= g[i];
            }
        }
        if (ans) {
            cout << "Alice" << '\n';
        } else {
            cout << "Bob" << '\n';
        }
    }
    return 0;
}