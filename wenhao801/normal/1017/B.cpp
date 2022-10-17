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

const int MAXN = 100100;
int n; char a[MAXN], b[MAXN];

int main () {
    n = read(); int i, j;
    scanf("%s", a + 1); scanf("%s", b + 1);
    int cnt00 = 0, cnt = 0; long long ans = 0;
    for (i = 1; i <= n; i++) cnt += a[i] == '0', cnt00 += a[i] == '0' && b[i] == '0';
    for (i = 1; i <= n; i++) if (a[i] == '1') {
        if (b[i] == '0') ans += cnt; else ans += cnt00;
    }
    cout << ans;
    return 0;
}