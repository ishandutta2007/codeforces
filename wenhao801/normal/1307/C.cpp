#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define int long long
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

char a[100010] = {};

signed main () {
    scanf("%s", a + 1);
    int l = strlen(a + 1);
    int i, j; int ans = 0;
    for (i = 1; i <= 26; i++) for (j = 1; j <= 26; j++) {
        int k;
        int cnt = 0; int rua = 0;
        for (k = 1; k <= l; k++) {
            if (a[k] - 'a' + 1 == i) rua++;
            if (a[k] - 'a' + 1 == j) cnt += rua + (i == j ? (-1) : 0);
        }
        ans = max(ans, cnt);
        //printf("%d %d %d\n", cnt, i, j);
    }
    for (i = 1; i <= 26; i++) {
        int cnt = 0;
        for (j = 1; j <= l; j++) if (i == a[j] - 'a' + 1) cnt++;
        ans = max(ans, cnt);
    }
    printf("%lld\n", ans);
    return 0;
}