#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1001000;
int n, c, a[MAXN], b[MAXN];

int main () {
    int T = read();
    while (T--) {
        int i, j, k; n = read(), c = read();
        for (i = 1; i <= n; i++) a[i] = read(), ++b[a[i]];
        for (i = 1; i <= c; i++) b[i] += b[i - 1];
        bool ans = 1;
        for (i = 1; i <= c; i++) if (b[i] - b[i - 1] > 0) {
            for (j = i, k = 1; j <= c; j += i, k++) {
                if (b[min(j + i - 1, c)] - b[j - 1] > 0 && b[k] - b[k - 1] == 0) { ans = 0; break; } 
            }
            if (!ans) break;
        }
        puts(ans ? "Yes" : "No");
        for (i = 1; i <= c; i++) b[i] = 0;
    }
    return 0;
}