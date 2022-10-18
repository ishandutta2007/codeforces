#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        ll a, b, n;
        cin >> a >> b >> n;
        int c = 0;
        while (a <= n && b <= n) {
            c++;
            if (a > b) {
                swap(a, b);
            }
            a += b;
        }
        cout << c << '\n';
    }
    return 0;
}