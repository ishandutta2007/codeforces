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
        long long a, b, x;
        cin >> a >> b >> x;
        if (a > b) {
            swap(a, b);
        }
        a = min(a, b - a);
        string ans = (b == x ? "YES" : "NO");
        while (a != 0) {
            if (b >= x && (b - x) % a == 0) {
                ans = "YES";
                break;
            }
            b %= a;
            swap(a, b);
        }
        cout << ans << '\n';
    }
    return 0;
}