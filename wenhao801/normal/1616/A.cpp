#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
} map <int, int> vis;

int main () {
    int T = read();
    while (T--) {
        int n = read(), i, ans = 0;
        for (i = 1; i <= n; i++) ++vis[abs(read())];
        for (auto i: vis) ans += min(2 - (i.first == 0), i.second);
        printf("%d\n", ans); vis.clear();
    }
    return 0;
}