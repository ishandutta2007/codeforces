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

int n;

//int ans[200200] = {};
//bool f[200200] = {};

void sol2 () {
    if (n % 2 == 0) { puts("NO"); return; }
    int i, j;
    puts("YES");
    int now = 0;
    for (i = 1; i <= n; i++) {
        if (i % 2) now++;
        else now += 3;
        printf("%lld ", now);
    }
    now = -1;
    for (i = n + 1; i <= n * 2; i++) {
        if (((n % 2) + i) % 2) now += 3;
        else now++;
        printf("%lld ", now);
    }
    return;
}

signed main () {
    n = read();
    //if (n % 2 == 0) 
     sol2(); return 0;
     /*
    int p = n * (2 * n + 1) / 2; // p, p + 1
    int i, j;
    int s = 0;
    for (i = 1; i < n; i++) {
        if (i % 2) ans[i] = i;
        else ans[i] = n * 2 + 2 - i;
        f[ans[i]] = true;
        s += ans[i];
    }
    bool fl = false;
    for (i = n; i <= 2 * n; i++) {
        if (f[p + (1 - (i % 2)) - s + ans[i - n]]) { puts("NO"); return 0; }
        ans[i] = p + (1 - (i % 2)) - s + ans[i - n];
        f[p + (1 - (i % 2)) - s + ans[i - n]] = true;
        s -= ans[i - n];
        s += ans[i];
    }
    if (ans[n + 1] != 2) puts("NO");
    else  {
        puts("YES");
        for (i = 1; i <= 2 * n; i++) printf("%lld ", ans[i]);
    }*/
    return 0;
}