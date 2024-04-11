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
        int n, r, b;
        cin >> n >> r >> b;
        string ans;
        for (int i = 0; i <= b; i++) {
            ans += string(r * (i + 1) / (b + 1) - r * i / (b + 1), 'R');
            if (i < b) {
                ans += "B";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}