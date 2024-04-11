#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

int n, K, ans; bool vis[505];
vector <int> E[505], dis[505];
queue <int> q;

void query (int diff) {
    int add = (K + diff) >> 1, dec = K - add, i; putchar('?');
    for (i = 1; i <= n; i++) {
        if (dec && vis[i]) printf(" %d", i), vis[i] = 0, --dec;
        else if (add && !vis[i]) printf(" %d", i), vis[i] = 1, --add;
    }
    puts(""); fflush(stdout);
    ans ^= read();
}

int main () {
    n = read(), K = read(); int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= min(i, K); j++) if (n - i >= K - j) E[i].push_back(i - j + (K - j));
    }
    dis[0].push_back(0); q.push(0);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto v: E[x]) {
            if (dis[v].empty()) {
                dis[v] = dis[x];
                dis[v].push_back(v);
                q.push(v);
            }
        }
    }
    if (dis[n].empty()) { puts("-1"); return 0; }
    for (i = 0; i < dis[n].size() - 1; i++) query(dis[n][i + 1] - dis[n][i]);
    printf("! %d\n", ans);
    return 0;
}