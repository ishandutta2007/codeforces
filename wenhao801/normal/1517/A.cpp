#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

#define ll long long

int main () {
    int T = read();
    while (T--) {
        ll x; cin >> x;
        if (x % 2050) { puts("-1"); continue; }
        x /= 2050;
        ll ans = 0;
        while (x) ans += x % 10, x /= 10;
        cout << ans << endl;
    }
    return 0;
}