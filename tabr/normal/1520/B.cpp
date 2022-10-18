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
        int ans = 0;
        for (int i = 1; i < 10; i++) {
            for (int j = 1; j < 10; j++) {
                int a = stoi(string(i, (char)('0' + j)));
                if (a <= n) {
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}