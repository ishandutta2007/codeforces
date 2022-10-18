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
        if (abs(a - b) > 1) {
            cout << -1 << '\n';
            continue;
        }
        if (a + b > n - 2) {
            cout << -1 << '\n';
            continue;
        }
        int sw = 0;
        if (a < b) {
            sw = 1;
            swap(a, b);
        }
        vector<int> p(n);
        if (a == 1 && b == 0) {
            iota(p.begin(), p.end(), 0);
            reverse(p.begin(), p.end());
            swap(p[0], p[1]);
        } else {
            set<int> st;
            for (int i = 1; i < n; i++) {
                if (a == 0 && b == 0) {
                    if (st.empty()) {
                        st.emplace(0);
                    }
                    if (p[i - 1] < 0) {
                        p[i] = *st.rbegin() + 1;
                        for (int j = i + 1; j < n; j++) {
                            p[j] = p[j - 1] + 1;
                        }
                        break;
                    } else {
                        p[i] = *st.begin() - 1;
                        for (int j = i + 1; j < n; j++) {
                            p[j] = p[j - 1] - 1;
                        }
                        break;
                    }
                }
                if (i % 2 == 1) {
                    p[i] = (i + 1) / 2;
                    a--;
                } else {
                    p[i] = -(i / 2);
                    b--;
                }
                st.emplace(p[i]);
            }
            int mn = *min_element(p.begin(), p.end());
            for (int i = 0; i < n; i++) {
                p[i] -= mn;
            }
        }
        for (int i : p) {
            if (sw) {
                cout << n - i << " ";
            } else {
                cout << i + 1 << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}