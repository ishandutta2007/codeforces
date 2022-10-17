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

const int mod = 1e9 + 7;
int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod, y >>= 1;
    }return ret;
}

int main () {
    int n = read();
    int ans = 1;
    for (int i = 1; i <= n; i++) ans = 1ll * ans * i % mod;
    ans = (ans - qpow(2, n-1)) % mod;
    printf("%d\n", (ans + mod) % mod);
    return 0;
}