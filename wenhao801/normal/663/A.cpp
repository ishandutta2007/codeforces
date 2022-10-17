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

char a[100100]; int len;
int n, add, del;

void solve (int u, int v) {
    if (u < add || u > add * n || v > -del || v < -del * n) return;
    bool op = 0;
    u -= add, v += del;
    for (int i = 1; i <= len; i++) {
        if (a[i] == '?') {
            if (!op) {
                int tmp = min(u, n - 1);
                printf("%d", tmp + 1); u -= tmp;
            }
            else {
                int tmp = min(-v, n - 1);
                printf("%d", tmp + 1); v += tmp;
            }
        }
        else {
            putchar(a[i]);
            if (a[i] == '+') op = 0;
            if (a[i] == '-') op = 1;
        }
    }
    putchar('\n'); exit(0);
}

int main () {
    cin.getline(a + 1, 100100); len = strlen(a + 1);
    int i, j; add = 1, del = 0;
    for (i = 1; i <= len; i++) add += a[i] == '+', del += a[i] == '-';
    for (i = len; i >= 1; i--) if (a[i] == ' ') break;
    for (i++; i <= len; i++) n = n * 10 + a[i] - '0';
    if (n < -del * n + add || n > add * n - del) { puts("Impossible"); return 0; }
    puts("Possible");
    solve(n * add, n - n * add);
    solve(add, n - add);
    solve(n + del, -del);
    solve(n + del * n, -del * n);
    return 0;
}