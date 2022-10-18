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
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        set<int> st;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                st.emplace(x[j] - x[i]);
            }
        }
        cout << st.size() << '\n';
    }
    return 0;
}