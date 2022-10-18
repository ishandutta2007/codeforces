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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> p(n);
        p[0] = a;
        p[n - 1] = b;
        set<int> st;
        for (int i = 1; i <= n; i++) {
            if (i != a && i != b) {
                st.emplace(i);
            }
        }
        for (int i = n - 2; i >= n / 2; i--) {
            p[i] = *st.begin();
            st.erase(st.begin());
        }
        for (int i = 1; i < n / 2; i++) {
            p[i] = *st.begin();
            st.erase(st.begin());
        }
        if (*min_element(p.begin(), p.begin() + n / 2) != a || *max_element(p.begin() + n / 2, p.end()) != b) {
            cout << -1 << '\n';
        } else {
            for (int i : p) {
                cout << i << " ";
            }
            cout << '\n';
        }
    }
    return 0;
}