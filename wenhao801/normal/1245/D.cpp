#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

#define Lint long long

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 2004000;

int n;

struct Edge {
    int nex;
    int to;
    Lint w;
} edge[MAXN << 1];
int head[MAXN << 1], cnt = 0;

void add (int u, int v, Lint w) {
    //printf("add(%d %d %d)\n", u, v, w);
    edge[++cnt].to = v;
    edge[cnt].nex = head[u];
    edge[cnt].w = w;
    head[u] = cnt;
    return;
}

struct node {
    Lint val;
    int num;
    int pre;
    bool operator < (const node &x) const {
        return val > x.val;
    }
};
priority_queue <node> q;

bool vis[MAXN] = {};

struct pos {
    int x;
    int y;
    int k;
} a[MAXN] = {};

int myabs (int x) { return x > 0 ? x : -x; }

Lint DIS (int x1, int y1, int x2, int y2) { return myabs(x1 - x2) + myabs(y1 - y2); }

void calc () {
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = i; j <= n; j++) {
            add(i, j, (Lint)(a[i].k + a[j].k) * DIS(a[i].x, a[i].y, a[j].x, a[j].y));
            add(j, i, (Lint)(a[i].k + a[j].k) * DIS(a[i].x, a[i].y, a[j].x, a[j].y));
        }
}

struct ANS {
    int u;
    int v;
} answer[MAXN];
int power[MAXN] = {};
int cnt1 = 0, cnt2 = 0;

int main () {
    n = read();
    int i, j;
    for (i = 1; i <= n; i++) a[i].x = read(), a[i].y = read();
    for (i = 1; i <= n; i++) {
        j = read();
        add(i, n + 1, j); add(n + 1, i, j);
    }
    for (i = 1; i <= n; i++)
        a[i].k = read();
    calc();
    n++;
    int now = 1;
    Lint ans = 0;
    memset(vis, false, sizeof(vis));
    q.push({0, 1, 0});

    while (!q.empty()) {
        node f = q.top();
        q.pop();
        if (vis[f.num]) continue;
        if (f.pre != 0) {
            if (f.num == n) {
                power[++cnt2] = f.pre;
            }
            else if (f.pre == n) {
                power[++cnt2] = f.num;
            }
            else answer[++cnt1].u = f.num, answer[cnt1].v = f.pre;
        }
        vis[f.num] = true;
        ans += (Lint)f.val;
        for (i = head[f.num]; i; i = edge[i].nex) {
            j = edge[i].to;
            if (!vis[j]) q.push({edge[i].w, j, f.num});
        }
    }
    printf("%lld\n%d\n", ans, cnt2);
    for (i = 1; i <= cnt2; i++) printf("%d ", power[i]);
    printf("\n%d\n", cnt1);
    for (i = 1; i <= cnt1; i++) printf("%d %d\n", answer[i].u, answer[i].v);
    return 0;
}