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

const int MAXN = 100100;
const long long mod = 1e9 + 7;

long long fib[MAXN] = {};
char a[MAXN] = {};
long long ans = 1;

signed main () {
    fib[1] = 1, fib[2] = 2;
    int i, j;
    for (i = 3; i <= 100000; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    scanf("%s", a + 1);
    int l = strlen(a + 1);
    int cnt = 0;
    int state = 0;
    char S[3] = {}; S[0] = 'u'; S[1] = 'n';
    a[++l] = '#';
    for (i = 1; i <= l; i++) {
        if ((a[i] != 'u' && a[i] != 'n') || (a[i] == S[1 - state])) {
            state = 1 - state;
            if (cnt != 0) ans = (ans * fib[cnt]) % mod;
            cnt = 0;
            if (a[i] == 'w' || a[i] == 'm') { ans = 0; break; }
        }
        if (a[i] == S[state]) {
            cnt++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}