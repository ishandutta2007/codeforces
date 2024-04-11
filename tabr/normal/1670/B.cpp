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
        string s;
        cin >> s;
        int k;
        cin >> k;
        string t;
        for (int i = 0; i < k; i++) {
            char c;
            cin >> c;
            t += c;
        }
        set<int> st;
        set<int> sp;
        for (int i = 0; i < n; i++) {
            st.emplace(i);
            if (t.find(s[i]) != string::npos) {
                sp.emplace(i);
            }
        }
        int ans = 0;
        while (true) {
            bool found = false;
            vector<int> del;
            for (int i : sp) {
                if (i == *st.begin()) {
                    del.emplace_back(i);
                } else {
                    found = true;
                    int j = *prev(st.lower_bound(i));
                    if (sp.count(j)) {
                        del.emplace_back(j);
                    }
                    st.erase(j);
                }
            }
            for (int i : del) {
                sp.erase(i);
            }
            if (!found) {
                break;
            }
            ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}