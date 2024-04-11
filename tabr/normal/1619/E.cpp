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
        sort(a.begin(), a.end());
        vector<int> b(n + 1);
        for (int i = 0; i < n; i++) {
            b[a[i]]++;
        }
        long long ans = 0;
        stack<int> st;
        for (int x = 0; x <= n; x++) {
            if (x != 0 && b[x - 1] == 0) {
                if (st.empty()) {
                    ans = -1;
                } else {
                    ans += (x - 1) - st.top();
                    st.pop();
                }
            }
            if (ans == -1) {
                for (int y = x; y <= n; y++) {
                    cout << -1 << " ";
                }
                break;
            }
            cout << ans + b[x] << " ";
            while (b[x] > 1) {
                b[x]--;
                st.emplace(x);
            }
        }
        cout << '\n';
    }
    return 0;
}