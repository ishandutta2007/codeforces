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
    set<int> st;
    for (int i = 1; i * i < (int)1e9; i++) {
        st.emplace(i * i);
    }
    while (tt--) {
        int n;
        cin >> n;
        string ans = "NO";
        if (n % 2 == 0 && st.count(n / 2)) {
            ans = "YES";
        }
        if (n % 4 == 0 && st.count(n / 4)) {
            ans = "YES";
        }
        cout << ans << '\n';
    }
    return 0;
}