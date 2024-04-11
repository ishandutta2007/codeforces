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
 
const int mod = 998244353;
 
int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
 
int inv (int x) { return qpow(x, mod - 2); }
 
int n;
int a[200200] = {};
int ainv[200200] = {};
int E[200200] = {};
 
signed main () {
    n = read();
    int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    for (i = 1; i <= 10000; i++) ainv[i] = inv(i);
    for (i = 1; i <= n; i++) {
        E[i] = a[i] * ainv[100] % mod * (E[i - 1] + 1) % mod * 10000 % mod * ainv[a[i] * a[i]] % mod;
    }
    printf("%lld\n", E[n]);
    return 0;
}