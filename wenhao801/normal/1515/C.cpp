#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int n, m, x, a[100100], ans[101000];

struct dat { long long cur; int id; bool operator < (const dat &tmp) const { return cur > tmp.cur; } };
priority_queue <dat> now;

int main () {
    int T = read();
    while (T--) {
        n = read(), m = read(), x = read();
        while (!now.empty()) now.pop();
        int i, j; puts("YES");
        for (i = 1; i <= n; i++) a[i] = read();
        // sort(a + 1, a + n + 1);
        for (i = 1; i <= m; i++) now.push({0, i});
        for (i = n; i >= 1; i--) {
            dat x = now.top(); now.pop();
            ans[i] = x.id; x.cur += a[i]; now.push(x);
        }
        for (i = 1; i <= n; i++) printf("%d ", ans[i]); puts("");
    }
    return 0;
}