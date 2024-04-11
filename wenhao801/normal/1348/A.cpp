#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

signed main () {
    int T = read();
    while (T--) {
        int n = read();
        int i, j;
        int s = 1ll << n;
        for (i = 1; i < n / 2; i++) s += 1ll << i;
        for (i = n / 2; i < n; i++) s -= 1ll << i;
        cout << s << endl;
    }
    return 0;
}