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

int a[10100];
int cnt[10010];
int ans[10010], top = 0;
int buc[10010], top2 = 0;

signed main () {
    int T = read();
    while (T--) {
        memset(cnt, 0, sizeof(cnt)); top = 0; top2 = 0;
        int n, k;
        n = read(), k = read();
        int i, j = 0;
        for (i = 1; i <= n; i++) { a[i] = read(); if (!cnt[a[i]]) buc[++top2] = a[i], cnt[a[i]] = 1; }
        
        if (top2 > k) { puts("-1"); continue; }
        for (i = 1; top2 < k; i++) if (!cnt[i]) buc[++top2] = i;
        j = 1; i = 1;
        while (j <= n) {
            ans[++top] = buc[i];
            if (buc[i] == a[j]) j++;
            i = i % top2 + 1;
        }
        printf("%lld\n", top);
        for (i = 1; i <= top; i++) printf("%lld ", ans[i]);
        puts("");
    }
    return 0;
}