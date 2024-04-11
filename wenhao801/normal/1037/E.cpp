#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>

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
int n, m, K; vector <pair <int, int>> E[MAXN];

int deg[MAXN];
struct node { int x; bool operator < (const node &t) const { return deg[x] == deg[t.x] ? (x < t.x) : (deg[x] < deg[t.x]); } };
set <node> s;

pair <int, int> e[MAXN];
int ans[MAXN], cur;

void foo(int x) { if (s.find({x}) != s.end()) s.erase({x}), --deg[x], s.insert({x}); }
void go() {
    while (!s.empty()) {
        int x = s.begin()->x;
        if (deg[x] < K) {
            s.erase({x});
            for (auto i: E[x]) if (i.second <= cur && s.find({i.first}) != s.end()) {
                foo(i.first);
            }
        }
        else break;
    }
}

int main() {
    n = read(), m = read(), K = read(); int i, j;
    for (i = 1; i <= m; i++) {
        int u = read(), v = read();
        e[i] = {u, v};
        E[u].push_back({v, i}), E[v].push_back({u, i}); ++deg[u], ++deg[v];
    }
    for (i = 1; i <= n; i++) s.insert({i});
    for (cur = m; cur >= 1; cur--) {
        go(); ans[cur] = s.size();
        
        if (s.find({e[cur].first}) != s.end() && s.find({e[cur].second}) != s.end()) foo(e[cur].first), foo(e[cur].second);
    }
    for (i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}