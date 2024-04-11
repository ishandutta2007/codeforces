#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int x;
        cin >> x;
        vector<int> a(4);
        cin >> a[1] >> a[2] >> a[3];
        set<int> st = {x, a[x], a[a[x]], a[a[a[x]]]};
        if (st.count(0)) {
            st.erase(0);
        }
        cout << (st.size() == 3 ? "YES" : "NO") << '\n';
    }
    return 0;
}