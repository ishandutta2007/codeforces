#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        multiset<int> st;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            while (x % 2 == 0) {
                x /= 2;
            }
            st.insert(x);
        }
        vector<int> b(n);
        for (auto &x : b) {
            cin >> x;
        }
        sort(b.rbegin(), b.rend());
        bool ok = true;
        for (auto &val : b) {
            while (val > 0 && st.find(val) == st.end()) {
                val /= 2;
            }
            if (val == 0) {
                ok = false;
                break;
            }
            st.erase(st.find(val));
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}