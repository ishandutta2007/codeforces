#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define lint long long

inline lint read () {
    lint ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}
int gcd (int x, int y) { if (!y) return x; return gcd(y, x % y); }

int main () {
    int T = read();
    while (T--) {
        lint x = read(), y = read(), k = read();
        int rua = gcd(x, y); x /= rua, y /= rua;
        if (x > y) swap(x, y);
        if (1 + (k - 1) * x < y) puts("REBEL"); else puts("OBEY");
    }
    return 0;
}