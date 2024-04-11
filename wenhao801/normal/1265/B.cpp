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
 
int n;
int a[200200] = {};
 
int main () {
    int T = read();
    while (T--) {
        n = read();
        int i, j;
        for (i = 1; i <= n; i++) { j = read(); a[j] = i; }
        int Max = 0, Min = n + 1;
        for (i = 1; i <= n; i++) {
            Max = max(Max, a[i]);
            Min = min(Min, a[i]);
            if (Max - Min == i - 1) putchar('1');
            else putchar('0');
        }
        putchar('\n');
    }
    return 0;
}