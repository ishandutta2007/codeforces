#pragma GCC optimize(3)

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

#define ll long long
int n, K; bool vis[11][44]; vector <int> pos[11];
int cur[44];

bool solve (int now) {
    if (now > K) {
        int i, j;
        for (i = 1; i <= n; i++) if (cur[i] == -1) return 0;
        for (i = n; i >= 1; i--) if (!cur[i]) break;
        for (i; i >= 1; i--) if (cur[i]) break;
        return !i;
    }
    int tmp[44], i, j; bool ret = 1;
    for (i = 1; i <= n; i++) tmp[i] = cur[i];
    int cnt[2] = {};
    for (auto i: pos[now]) {
        if (cur[i] != -1) ++cnt[cur[i]];
        cur[i] = 0;
    }
    int rua = pos[now].size();
    for (auto i: pos[now]) {
        if (rua <= cnt[0]) break;
        if (cnt[1]) --cnt[1], cur[i] = 1;
        else ret &= solve(now + 1), cur[i] = 1;
        --rua;
    }
    ret &= solve(now + 1);
    for (i = 1; i <= n; i++) cur[i] = tmp[i];
    return ret;
}

int main () {
    n = read(), K = read(); int i, j;
    if (n == 1) { puts("ACCEPTED"); return 0; }
    for (i = 1; i <= K; i++) {
        j = read();
        while (j--) pos[i].push_back(read());
        reverse(pos[i].begin(), pos[i].end());
        for (j = 1; j <= n; j++) vis[i][j] = vis[i - 1][j];
        for (auto j: pos[i]) vis[i][j] = 1;
    }
    for (i = 1; i <= n; i++) cur[i] = -1;
    puts(solve(1) ? "ACCEPTED" : "REJECTED");
    return 0;
}