#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

#define ll long long
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}
const int MAXN = 200200, mod = 1e9 + 7;
int n, b[MAXN]; ll sb[MAXN];
int f[MAXN];

map <ll, int> s;

int main () {
    int T = read();
    while (T--) {
        s.clear();
        n = read(); int i, j;
        for (i = 1; i <= n; i++) b[i] = read(), sb[i] = sb[i - 1] + b[i];
        f[0] = 1; s[0] = 1; int as = 1, ans = 1;
        for (i = 1; i <= n; i++) {
            f[i] = (as - s[sb[i - 1]]) % mod;
            as = (as + f[i]) % mod; ans = (ans + f[i]) % mod; s[sb[i - 1]] = (s[sb[i - 1]] + f[i]) % mod;
        }
        printf("%d\n", (ans + mod) % mod);
    }
    return 0;
}