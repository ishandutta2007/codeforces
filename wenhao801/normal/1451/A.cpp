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

const int MAXN = 101000;
int p[MAXN], np[MAXN], top;
void genp () {
    int i, j;
    for (i = 2; i <= 100000; i++) {
        if (!np[i]) p[++top] = i;
        for (j = 1; j <= top; j++) {
            if (i * p[j] > 100000) break;
            np[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

int main () {
    int T = read();
    while (T--) {
        int n = read();
        int i, j;
        if (n == 1) puts("0");
        else if (n == 2 ) puts("1");
        else if (n == 3) puts("2");
        else if (n & 1) puts("3");
        else puts("2");
    }
    return 0;
}