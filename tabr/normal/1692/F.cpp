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
        vector<int> c(10);
        for (int i = 0; i < n; i++) {
            c[a[i] % 10]++;
        }
        vector<int> b;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < min(3, c[i]); j++) {
                b.emplace_back(i);
            }
        }
        n = (int) b.size();
        string ans = "NO";
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if ((b[i] + b[j] + b[k]) % 10 == 3) {
                        ans = "YES";
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}