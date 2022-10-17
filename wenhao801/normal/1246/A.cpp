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

int main () {
    int n = read(), p = read();
    for (int i = 0; i <= 31; i++) {
        if (n - 1ll * p * i >= i && __builtin_popcount(n - p * i) <= i) { cout << i << endl; return 0; }
    }
    cout << -1;
    return 0;
}