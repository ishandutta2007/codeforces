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
int n, a[MAXN]; char s[MAXN];
int ans[MAXN];

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    scanf("%s", s + 1); sort(a + 1, a + n + 1);
    int l = 1, r = n;
    for (i = n; i > 1; i--) {
        if (s[i] != s[i - 1]) ans[i] = r--;
        else ans[i] = l++;
    }
    ans[1] = l;
    for (i = 1; i <= n; i++) printf("%d %c\n", a[ans[i]], ((s[1] == 'L') ^ (ans[i] & 1) ^ (ans[1] & 1)) ? 'L' : 'R');
    return 0;
}