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
        vector<int> a(n);
        bool have0 = false, have2 = false;
        set<int> st;
        for (auto &x : a) {
            cin >> x;
            while (x % 10 != 0 && x % 10 != 2) {
                x += x % 10;
            }
            if (x % 10 == 0) {
                have0 = true;
                st.insert(x);
            } else {
                have2 = true;
                st.insert(x % 20);
            }
        }
        if (have0 && have2) {
            cout << "No\n";
            continue;
        }
        if (st.size() == 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}