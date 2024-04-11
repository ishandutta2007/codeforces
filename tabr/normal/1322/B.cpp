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
    int n;
    cin >> n;
    vector<int> c(1 << 25);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        // ans ^= 2 * a;
        c[a]++;
    }
    for (int b = 24; b >= 0; b--) {
        long long t = 0;
        long long s = 0;
        for (int i = (1 << b); i < (1 << (b + 1)); i++) {
            s += c[i];
        }
        for (int i = 0; i < (1 << (b + 1)); i++) {
            if (b && ((1 << (b - 1)) & i)) {
                t += (s - c[i]) * c[i];
                t += c[i] * (c[i] - 1);
            } else {
                t += s * c[i];
            }
            s -= c[(1 << (b + 1)) - 1 - i];
            s += c[((1 << (b + 1)) + (1 << b) - 1 - i) % (1 << (b + 1))];
        }
        if (t / 2 % 2) {
            ans ^= 1 << b;
        }
        for (int i = 0; i < (1 << b); i++) {
            c[i] += c[i + (1 << b)];
        }
    }
    cout << ans << '\n';
    return 0;
}