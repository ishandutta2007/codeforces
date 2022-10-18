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
        cout << 2 << '\n';
        set<int> st;
        for (int i = 1; i <= n; i++) {
            st.emplace(i);
        }
        for (int i = 1; i <= n; i++) {
            int x = i;
            while (st.count(x)) {
                st.erase(x);
                cout << x << " \n"[st.empty()];
                x <<= 1;
            }
        }
    }
    return 0;
}