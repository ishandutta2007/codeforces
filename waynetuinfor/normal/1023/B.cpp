#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k; cin >> n >> k;
    if (k > 2 * n) return cout << 0 << endl, 0;
    if (k <= n) return cout << (k - 1) / 2 << endl, 0;
    int d = 60;
    long long l = 0;
    while (d--) if (l + (1ll << d) <= n) {
        long long x = l + (1ll << d);
        long long y = k - x;
        if (y > n) l = x;
    }
    ++l;
    long long r = l;
    d = 60;
    while (d--) if (r + (1ll << d) <= n) {
        long long x = r + (1ll << d);
        long long y = k - x;
        if (y <= n && y >= x) r = x;
    }
    long long fin = max(0ll, r - l + 1);
    if (k % 2 == 0 && k / 2 <= n) --fin;
    cout << fin << endl;
}