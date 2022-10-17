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

bool a[11] = {};

bool judge (int x) {
    int i, j;
    for (i = 0; i <= 9; i++) a[i] = false;
    while (x) {
        if (a[x % 10]) return false;
        a[x % 10] = true;
        x /= 10;
    }
    return true;
}

int main () {
    int l = read(), r = read();
    int i, j;
    for (i = l; i <= r; i++)
        if (judge(i)) { printf("%d\n", i); return 0; }
    puts("-1");
    return 0;
}