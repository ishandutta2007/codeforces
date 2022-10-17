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

int n; char a[5050];
int f[26][5050][26], buc[26];

int main () {
    scanf("%s", a); n = strlen(a);
    int i, j, k;
    for (i = 0; i < n; i++) {
        ++buc[a[i] - 'a'];
        for (j = 1; j < n; j++) {
            ++f[a[i] - 'a'][j][a[(i + j) % n] - 'a'];
        }
    }
    double ans = 0;
    for (i = 0; i < 26; i++) if (buc[i]) {
        int mx = 0;
        for (j = 1; j < n; j++) {
            int cnt = 0;
            for (k = 0; k < 26; k++) if (f[i][j][k] == 1) ++cnt;
            mx = max(mx, cnt);
        }
        ans += 1.0 * mx / n;
    }
    printf("%.8lf\n", ans);
    return 0;
}