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
        int x = read(), i;
        for ( i = 1; i * (i + 1) < x * 2; i++);
        if (i * (i + 1) / 2 == x + 1) printf("%d\n", i + 1);
        else printf("%d\n", i);
    }
    return 0;
}