#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}


char a[222];
int main() {
    int T = read(); while (T--) {
        int n = read(); scanf("%s", a + 1);
        sort(a + 1, a + n + 1);
        printf("%s\n", a + 1);
    }
    return 0;
}