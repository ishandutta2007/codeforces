#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 8192, inf = 1e9 + 7;
int n; vector <int> pos[MAXN];
int ans[MAXN], tmp[MAXN];

int main () {
    n = read(); int i, j;
    for (i = 1; i < MAXN; i++) ans[i] = inf;
    for (i = 1; i <= n; i++) {
        int x = read();
        pos[x].push_back(i);
    }
    for (i = 1; i < MAXN; i++) {
        memcpy(tmp, ans, sizeof ans);
        for (j = 0; j < MAXN; j++) {
            auto res = lower_bound(pos[i].begin(), pos[i].end(), ans[j]);
            if (res != pos[i].end()) tmp[i ^ j] = min(tmp[i ^ j], *res);
        }
        memcpy(ans, tmp, sizeof ans);
    }
    int cnt = 0; for (i = 0; i < MAXN; i++) cnt += ans[i] != inf;
    printf("%d\n", cnt);
    for (i = 0; i < MAXN; i++) if (ans[i] != inf) printf("%d ", i);
    return 0;
}