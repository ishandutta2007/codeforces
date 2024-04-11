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
        string s;
        cin >> s;
        string t;
        cin >> t;
        set<char> st;
        st.emplace(s[0]);
        st.emplace(s[1]);
        st.emplace(t[0]);
        st.emplace(t[1]);
        cout << st.size() - 1 << '\n';
    }
    return 0;
}