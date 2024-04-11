#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 100100, LIM = 5050;
int p[MAXN], np[MAXN], top;
void genp () {
    int i, j;
    for (i = 2; i <= LIM; i++) {
        if (!np[i]) p[++top] = i;
        for (j = 1; j <= top; j++) {
            if (i * p[j] > LIM) break;
            np[i * p[j]]  = 1;
            if (i % p[j] == 0) break;
        }
    }
}

int base = 998244353, mod = 1e9 + 7;
map <int, bool> Hash;

int main () {
    genp(); int T = read();
    while (T--) {
        int n = read(), i, j = read(), ans = 0;
        for (i = 1; i <= n; i++) {
            int x = read(), cur = 0;
            for (j = 1; j <= top && p[j] * p[j] <= x; j++) if (x % p[j] == 0) {
                bool qwq = 0;
                while (x % p[j] == 0) qwq ^= 1, x /= p[j];
                if (qwq) cur = (1ll * cur * base + p[j]) % mod; //, printf("! %d\n", p[j]);
            }
            if (x != 1) cur = (1ll * cur * base + x) % mod; //, printf("! %d\n", x);
            if (Hash.count(cur)) ++ans, Hash.clear();
            Hash[cur] = 1;
        }
        ++ans; Hash.clear();
        printf("%d\n", ans);
    }
    return 0;
}