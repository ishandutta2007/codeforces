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
int n, a[MAXN];

int s[MAXN], top;

bool att (int val) {
    int i, j; top = 0;
    for (i = 1; i <= n; i++) if (a[i] != val) s[++top] = a[i];
    for (i = 1; i <= top; i++) if (s[i] != s[top - i + 1]) return 0;
    return 1;
}

int main () {
    int T = read(); while (T--) {
        n = read(); int i, j;
        for (i = 1; i <= n; i++) a[i] = read();
        bool win = 1;
        for (i = 1; i <= n / 2; i++) if (a[i] != a[n - i + 1]) {
            win &= att(a[i]) || att(a[n - i + 1]);
            break;
        }
        puts(win ? "YES" : "NO");
    }
    return 0;
}