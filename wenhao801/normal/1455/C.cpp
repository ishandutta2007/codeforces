#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}
int main () {
    int t = read();
    while (t--) {
        int x = read(), y = read();
        printf("%d %d\n", x - 1, y);
    }
    return 0;
}