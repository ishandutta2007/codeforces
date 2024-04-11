#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int a[1000100];
int main () {
    int T = read();
    while (T--) {
        int x =read();
        int cnt = 0;
        int i;
        a[++cnt] = 0;
        for (i = 1; i <= sqrt(x); i++) {
            a[++cnt] = i; if (x / i != i) a[++cnt] = x / i;
        }
        sort(a + 1, a + cnt + 1); cout << cnt << endl;
        for (i = 1; i <= cnt; i++) printf("%d ", a[i]); cout << endl;
    }
    return 0;
}