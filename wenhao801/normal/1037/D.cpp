#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200200;
int n; vector <int> E[MAXN], ch[MAXN];
int a[MAXN], pos[MAXN];

int dep[MAXN], b[MAXN];
void dfs(int x, int fa) {
    dep[x] = dep[fa] + 1; ++b[dep[x]];
    for (auto i: E[x]) if (i != fa) ch[x].push_back(i), dfs(i, x);
}

bool vis[MAXN];
queue <int> q;

void fail() { puts("No"); exit(0); }

int main() {
    n = read(); int i, j;
    for (i = 1; i < n; i++) {
        int u = read(), v = read();
        E[u].push_back(v), E[v].push_back(u);
    }
    for (i = 1; i <= n; i++) a[i] = read(), pos[a[i]] = i;
    dfs(1, 0);
    q.push(1);
    int it = 1; if (a[1] != 1) fail();
    while (!q.empty()) {
        int x = q.front(); q.pop();
        vector <int> tmp;
        for (int i = 0; i < ch[x].size(); i++) ++it, tmp.push_back(a[it]), q.push(a[it]);
        sort(tmp.begin(), tmp.end()); sort(ch[x].begin(), ch[x].end());
        if (tmp != ch[x]) fail();
    }
    puts("Yes");
    return 0;
}