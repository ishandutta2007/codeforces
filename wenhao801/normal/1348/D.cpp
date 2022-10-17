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

int ans[33] = {}, top = 0;

int main () {
    int T = read();
    while (T--) {
        int n = read(); top = 0;
        while ((1 << top) - 1 <= n) ans[top] = 1 << top, top++; top--;
        if ((1 << top) - 1 != n) ans[top] = n + 1 - (1 << top), top++, sort(ans, ans + top);
        printf("%d\n", top - 1);
        for (int i = 1; i < top; i++) printf("%d ", ans[i] - ans[i - 1]); puts("");
    }
    return 0;
}