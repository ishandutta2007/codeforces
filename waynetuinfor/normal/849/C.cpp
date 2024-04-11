#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;

int32_t main() {
    int k; cin >> k;
    if (k == 0)return cout << "a" << endl, 0;
    int ch = 25;
    char cur = 'a';
    while (k > ch) {
        int d = 1, ans = 0; while (d < maxn) d <<= 1;
        while (d >>= 1) if (ans + d < maxn) {
            int ts = ans + d;
            if (ts * (ts + 1) / 2 <= k) ans += d;
        }
        for (int i = 0; i < ans + 1; ++i) cout << cur; ++cur; k -= ans * (ans + 1) / 2; --ch;
    }
    while (k) {
        cout << cur << cur; ++cur; --k;
    }
    return 0;
}