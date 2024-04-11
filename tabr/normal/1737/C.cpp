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
        int n;
        cin >> n;
        vector<int> x(5), y(5);
        for (int i = 0; i < 4; i++) {
            cin >> x[i] >> y[i];
            x[i]--;
            y[i]--;
        }
        x[4] = x[0] ^ x[1] ^ x[2];
        y[4] = y[0] ^ y[1] ^ y[2];
        if (x[4] % 2 == x[3] % 2 && y[4] % 2 == y[3] % 2) {
            cout << "NO" << '\n';
        } else {
            set<pair<int, int>> st;
            for (int i = 0; i < 3; i++) {
                st.emplace(x[i], y[i]);
            }
            if (st.count(make_pair(x[3], y[3]))) {
                cout << "YES" << '\n';
            } else {
                string ans = "YES";
                for (int z = 0; z < 4; z++) {
                    st.clear();
                    for (int i = 0; i < 3; i++) {
                        st.emplace(x[i], y[i]);
                    }
                    if (st.count(make_pair(0, 0)) && st.count(make_pair(0, 1)) && st.count(make_pair(1, 0))) {
                        ans = "NO";
                        if (x[3] == 0 || y[3] == 0) {
                            ans = "YES";
                        }
                        break;
                    }
                    for (int i = 0; i < 5; i++) {
                        tie(x[i], y[i]) = make_pair(n - 1 - y[i], x[i]);
                    }
                }
                cout << ans << '\n';
            }
        }
    }
    return 0;
}