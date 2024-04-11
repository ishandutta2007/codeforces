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

int n;

char a[MAXN];
int fa[MAXN] = {};
bool t[MAXN] = {};

int getfa (int x) { if (fa[x] == x) return x; return fa[x] = getfa(fa[x]); }

int main () {
    n = read();
    int i, j;
    for (i = 1; i <= n + 26; i++) fa[i] = i;
    for (i = 1; i <= n; i++) {
        scanf("%s", a + 1);
        int l = strlen(a + 1);
        for (j = 1; j <= l; j++) {
            fa[getfa(i)] = getfa(a[j] - 'a' + 1 + n);
            //printf("connect(%d %d)\n", i, a[j] - 'a' + 1);
        }
    }
    for (i = 1; i <= n; i++) t[getfa(i)] = true;
    int ans = 0;
    for (i = 1; i <= n + 26; i++) ans += t[i]; printf("%d\n", ans);
    return 0;
}