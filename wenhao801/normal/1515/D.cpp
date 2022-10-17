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

const int MAXN = 200200;
int n, l, r, a[MAXN];

int main () {
    int T = read();
    while (T--) {
        n = read(), l = read(), r = read(); int i, j;
        for (i = 1; i <= l; i++) ++a[read()];
        for (i = 1; i <= r; i++) --a[read()];
        int sp = 0, sn = 0, canp = 0, cann = 0;
        for (i = 1; i <= n; i++) {
            if (a[i] > 0) sp += a[i], canp += a[i] / 2;
            else sn += -a[i], cann += (-a[i]) / 2;
        }
        if (sp < sn) swap(sp, sn), swap(canp, cann);
        int remp = sp - 2 * canp, remn = sn - 2 * cann;
        int ans = sn;
        if (sp - sn <= 2 * canp) ans += (sp - sn) >> 1;
        else ans += (sp - sn) / 2 + (sp - sn - 2 * canp) / 2;
        cout << ans << endl;
        for (i = 1; i <= n; i++) a[i] = 0;
    }
    return 0;
}