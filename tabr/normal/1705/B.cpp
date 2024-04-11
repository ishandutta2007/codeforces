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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long ans = 0;
        set<int> st;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == 0) {
                st.emplace(i);
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == 0) {
                st.erase(i);
                continue;
            }
            while (!st.empty() && a[i] > 0) {
                ans++;
                a[i]--;
                int j = *st.begin();
                a[j]++;
                st.erase(j);
            }
            ans += a[i];
            a[i] = 0;
        }
        cout << ans << '\n';
    }
    return 0;
}