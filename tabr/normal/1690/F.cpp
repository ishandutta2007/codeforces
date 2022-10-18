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
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
            p[i]--;
        }
        vector<int> c(n);
        vector<int> a;
        long long ans = 1;
        for (int i = 0; i < n; i++) {
            if (c[i]) {
                continue;
            }
            int x = i;
            string t;
            do {
                t += s[x];
                c[x] = 1;
                x = p[x];
            } while (x != i);
            debug(t);
            int k = (int) t.size();
            for (int j = 1; j < k; j++) {
                string u = t;
                rotate(u.begin(), u.begin() + j, u.end());
                if (t == u) {
                    k = j;
                    break;
                }
            }
            ans = lcm(ans, k);
        }
        cout << ans << '\n';
    }
    return 0;
}