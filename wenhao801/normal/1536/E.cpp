#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int mod = 1e9 + 7;
int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod; y >>= 1;
    }
    return ret;
}

char s[2020];

int main () {
    int T = read();
    while (T--) {
        int n = read(), m = read(), ans = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%s", s + 1);
            for (int j = 1; j <= m; j++) ans += s[j] == '#';
        }
        if (ans == n * m) printf("%d\n", (qpow(2, ans) + mod - 1) % mod);
        else printf("%d\n", qpow(2, ans));
    }
    return 0;
}