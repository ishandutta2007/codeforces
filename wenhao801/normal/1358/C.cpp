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
    int T = read();
    while (T--) {
        int x = read(), y = read(), a = read(), b = read();
        long long n = abs(x - a)  +1, m = abs(y - b)+1;
        if (n > m) swap(n, m);
        cout << (n - 1) * (m - 1) + 1 << endl;
    }
    return 0;
}