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
        int n = read();
        int od1 = 0, od2 = 0;
        int ev = 0;
        for (int i = 1; i <= n; i++) {
            int x = read();
            if (x % 2 == 0) ev = i;
            else if (od1 == 0) od1 = i;
            else od2 = i;
        }
        if (ev) { printf("1\n%d\n", ev);}
        else if (od1 && od2) {
            printf("2\n%d %d\n", od1, od2);
        }
        else puts("-1");
    }
    return 0;
}