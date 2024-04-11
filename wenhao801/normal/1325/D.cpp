#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
#define int long long
bool a[101], b[101];
signed main () {
    int u, v;
    cin >> u >> v;
    if (u > v) { puts("-1"); return 0; }
    if (u == 0 && v == 0) { puts("0"); return 0; }
    if (u == v) { printf("1\n%lld", u); return 0; }
    if ((v - u) % 2) { puts("-1"); return 0; }
    int i, j;
    for (i = 0, j = u; i <= 70; i++) a[i] = j & 1, j >>= 1;
    for (i = 0, j = v; i <= 70; i++) b[i] = j & 1, j >>= 1;
    int x = 0, y = 0;
    bool f = false;
    for (i = 70; i >= 0; i--) {
        if (!a[i] && b[i]) {
            if (f) x += 1ll << i, y += 1ll << i;
            f = true;
        }
        else if (!a[i] && !b[i]) {
            if (f) x += 1ll << i, y += 1ll << i;
            f = false;
        }
        else if (a[i] && b[i]) {
            if (f) break;
            x += 1ll << i;
        }
        else {
            x += 1ll << i; f = true;
        }
    }
    if (x + y == v && (x ^ y) == u) {
        printf("2\n%lld %lld\n", x, y);
        return 0;
    }
    printf("3\n%lld %lld %lld\n", u, (v - u) / 2, (v - u) / 2);
    return 0;
}