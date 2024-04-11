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

int n, k;
int a[3030];
int b[3030] = {};
char s[3030] = {};

int ans[3030][3030] = {};

int main () {
    n = read(), k = read();
    scanf("%s", s + 1);
    int i, j;
    for (i = 1, j = 0; i <= n; i++) if (s[i] == 'R') a[i] = a[i - 1] + 1, j++; else a[i] = a[i - 1] - 1;
    for (i = 1; i <= n - j; i++) b[i] = b[i - 1] - 1; for (i; i <= n; i++) b[i] = b[i - 1] + 1;
    bool f = false;
    for (i = 1; i <= n; i++) if (a[i] != b[i]) f = true;
    if (!f) { puts("-1"); return 0; }
    for (j = 1; j <= k; j++) {
        bool f = false;
        for (i = 1; i <= n; i++) if (a[i] != b[i]) f = true;
        if (!f) break;
        for (i = 1; i < n; i++) {
            if (a[i] == b[i]) continue;
            if (a[i] > a[i + 1] && a[i] > a[i - 1]) a[i] -= 2, ans[j][++ans[j][0]] = i, i++;
        }
    }
    f = false;
    for (i = 1; i <= n; i++) if (a[i] != b[i]) f = true;
    if (f) puts("-1");
    else {
        int sum = 0;
        for (i = 1; i <= k && ans[i][0]; i++) sum += ans[i][0];
        if (sum < k) { puts("-1"); return 0; }
        for (i = 1; i <= k; i++) if (!ans[i][0]) {sum = i - 1; break;}
        i = 1;
        while (sum < k) {
            k--;
            printf("1 %d\n", ans[i][ans[i][0]]);
            ans[i][0]--;
            if (!ans[i][0]) i++, j = ans[i][ans[i][0]], sum--;
        }
        if (!ans[i][0]) i++, sum--;
        for (i; true; i++) {
            if (!ans[i][0]) break;
            printf("%d", ans[i][0]);
            for (j = 1; j <= ans[i][0]; j++) printf(" %d", ans[i][j]);
            puts("");
        }
    }
    return 0;
}