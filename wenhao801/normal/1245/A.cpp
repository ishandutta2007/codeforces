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
        int a = read(), b = read();
        int i, j = 0;
        for (i = 2; i <= min(a, b); i++) {
            if (a % i == 0 && b % i == 0) {puts("Infinite");j = 1; break;} 
        }
        if (j == 0) puts("Finite");
    }
    return 0;
}