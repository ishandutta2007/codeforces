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

const int MAXN = 200200;

int a[MAXN];
bool vis[MAXN];

int main () {
    int T = read();
    while (T--) {
        int n = read();
        int i, j; bool f = true;
        for (i = 0; i < n; i++) vis[i] = false;
        for (i = 0; i < n; i++) a[i] = ((read() % n) + n) % n;
        for (i = 0; i < n; i++) {
            if (vis[i]) continue;
            vis[i] = true;
            j = (i + a[i]) % n;
            while (!vis[j]) {
                vis[j] = true;
                j = (j + a[j]) % n;
            }
            if (j != i) f = false;
        }
        if (f) puts("YES"); else puts("NO");
    }
    return 0;
}