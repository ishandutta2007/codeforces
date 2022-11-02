#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std;

#define tm abracadabra

const int N = 500500;
const int K = 20;

struct Query {
    int t, x, y;
    Query() {}
    Query(int t, int x, int y) : t(t), x(x), y(y) {}
};

int n, m, pred[N], root[N], cnt, pr[N][K], tm, tin[N], tout[N], dep[N], ver[N], first[N], last[N];
vector<int> g[N];
Query q[N];

void dfs(int x, int px) {
    pr[x][0] = px;
    for (int i = 1; i < K; i++) {
        if (pr[x][i - 1] == -1) {
            pr[x][i] = -1;
        } else {
            pr[x][i] = pr[pr[x][i - 1]][i - 1];
        }
    }
    tin[x] = tm++;
    for (int i = 0; i < g[x].size(); i++) {
        dep[g[x][i]] = dep[x] + 1;
        dfs(g[x][i], x);
    }
    tout[x] = tm++;
}

int fs(int x) {
    if (pred[x] != x) {
        pred[x] = fs(pred[x]);
    }
    return pred[x];
}

void uni(int x, int y) {
    x = fs(x);
    y = fs(y);
    if (x != y) {
        pred[x] = y;
    }
}

int find_lab(int x) {
    int y = x;
    for (int i = K - 1; i >= 0; i--) {
        if (pr[y][i] != -1) {
            int z = pr[y][i];
            if (fs(z) == fs(y)) {
                y = z;
            }
        }
    }
    return y;
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        root[i] = true;
        pred[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int t, x, y;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d", &x, &y);
            --x;
            --y;
            g[y].push_back(x);
            root[x] = false;
            q[i] = Query(t, x, y);
        } else {
            if (t == 2) {
                scanf("%d", &x);
                --x;
                q[i] = Query(t, x, cnt++);
            } else {
                scanf("%d%d", &x, &y);
                --x;
                --y;
                q[i] = Query(t, x, y);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (root[i]) {
            dfs(i, -1);
        }
    }
    for (int i = 0; i < m; i++) {
        if (q[i].t == 1) {
            uni(q[i].x, q[i].y);
        } else {
            if (q[i].t == 2) {
                last[q[i].y] = dep[q[i].x];
                first[q[i].y] = dep[find_lab(q[i].x)];
                ver[q[i].y] = q[i].x;
            } else {
                int x = q[i].x, nom = q[i].y;
                if ((dep[x] >= first[nom]) && (dep[x] <= last[nom]) && (tin[ver[nom]] >= tin[x]) && (tout[ver[nom]] <= tout[x])) {
                    puts("YES");
                } else {
                    puts("NO");
                }
            }
        }
    }
}