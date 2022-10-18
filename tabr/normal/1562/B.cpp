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
        string s;
        cin >> n >> s;
        string x = "2357";
        int ok = 0;
        for (int i = 0; i < n; i++) {
            if (x.find(s[i]) == string::npos) {
                cout << 1 << '\n';
                cout << s[i] << '\n';
                ok = 1;
                break;
            }
        }
        if (ok) {
            continue;
        }
        cout << 2 << '\n';
        set<int> st;
        st.emplace(23);
        st.emplace(37);
        st.emplace(53);
        st.emplace(73);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int z = (s[i] - '0') * 10 + (s[j] - '0');
                if (!st.count(z)) {
                    cout << z << '\n';
                    ok = 1;
                    break;
                }
            }
            if (ok) {
                break;
            }
        }
    }
    return 0;
}