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

int a[101] = {};
bool f[101] = {};
int main () {
    int T = read();
    while (T--) {
        int n = read();
        int i, j;
        for (i = 1; i<= n; i++) a[i]=  read(), f[i] = false;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n && i != a[j]; j++);
            int t = j;
            for (j = t; j >= 2; j--) if (!f[j] && a[j] < a[j -1]) {swap(a[j], a[j - 1]); f[j] = true;} else break;
        }
        for (i = 1; i <= n; i++) printf("%d ", a[i]); putchar('\n');
    }
    return 0;
}