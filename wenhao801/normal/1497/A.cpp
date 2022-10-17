#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

int n, a[101], vis[101];

int main () {
    int T = read();
    while (T--) {
        n = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read(), vis[i] = 0;
        sort(a + 1, a + n +1);
        i = 1, j = 0;
        while (i <= n) {
            if (a[i] != j) break;
            vis[i] = 1; cout << j << ' ';
            while (i <= n && a[i] == j) ++i;
            ++j;
        }
        for (i = 1; i <= n; i++) if (!vis[i]) cout << a[i] << ' ';
        cout << endl;
    }
    return 0;
}