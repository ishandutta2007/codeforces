#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <bitset>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int n, a[222];
bool isp (int x) { for (int i = 2; i * i <= x; i++) if (x % i == 0) return 0; return 1; }
int main () {
    int T = read();
    while (T--) {
        n = read(); int i, j, s = 0;
        for (i = 1; i <= n; i++) a[i] = read(), s += a[i];
        if (!isp(s)) { printf("%d\n", n); for (i = 1; i <= n; i++) cout << i << ' '; cout << endl; continue; }
        for (i = 1; i <= n; i++) if (!isp(s - a[i])) {
            cout << n - 1 << endl;
            for (j = 1; j <= n; j++) if (j != i) cout << j << ' '; cout << endl;
            break;
        }
    }
    return 0;
}