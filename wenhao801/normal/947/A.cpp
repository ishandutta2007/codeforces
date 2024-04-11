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

const int MAXN = 1001000;
int n; bool pr[MAXN]; int p[MAXN], top;

int main () {
    n = read(); int i, j;
    for (i = 2; i <= n; i++) pr[i] = 1;
    for (i = 2; i <= n; i++) {
        if (!pr[i]) continue;
        p[++top] = i;
        for (j = i + i; j <= n; j += i) pr[j] = 0;
    }
    int L = n;
    for (i = 1; i <= top; i++) if (n % p[i] == 0) {
        L = min(L, max(n - p[i] + 1, p[i] + 1));
    }
    int ans = n;
    for (i = L; i <= n; i++) {
        int now = i;
        for (j = 1; p[j] <= 1000 && j <= top; j++) if (now % p[j] == 0) {
            while (now % p[j] == 0) now /= p[j];
            ans = min(ans, max(i - p[j] + 1, p[j] + 1));
        }
        if (now != 1) ans = min(ans, max(i - now + 1, now + 1));
    }
    cout << ans << endl;
    return 0;
}