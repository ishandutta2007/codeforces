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
int dep[MAXN], val[MAXN];

int main () {
    int n = read(), i, j; dep[1] = 1, val[1] = 1;
    for (i = 2; i <= n; i++) {
        int x = read();
        dep[i] = dep[x] + 1, val[dep[i]] ^= 1;
    }
    int ans = 0; for (i = 1; i <= n; i++) ans += val[i];
    cout << ans << endl;
    return 0;
}