#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

#define ll long long
using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 100100;
const ll inf = 100000000000007ll;
struct node { int ls, rs; } t[MAXN << 2]; int top;

struct Edge { int nex, to, w; } edge[MAXN << 6];
int head[MAXN << 2], cnt = 0;
void add (int u, int v, int w) {
    edge[++cnt].to = v; edge[cnt].nex = head[u];
    head[u] = cnt; edge[cnt].w = w;
}

int n, Q, s, rUp, rDown;
int buildDown (int l, int r) {
    if (l == r) return l;
    int ret = ++top, mid = (l + r) >> 1;
    t[ret].ls = buildDown(l, mid); t[ret].rs = buildDown(mid + 1, r);
    add(ret, t[ret].ls, 0); add(ret, t[ret].rs, 0);
    return ret;
}
int buildUp (int l, int r) {
    if (l == r) return l;
    int ret = ++top, mid = (l + r) >> 1;
    t[ret].ls = buildUp(l, mid), t[ret].rs = buildUp(mid + 1, r);
    add(t[ret].ls, ret, 0); add(t[ret].rs, ret, 0);
    return ret;
}
void modify (int l, int r, int k, int w, int L, int R, int x, bool ud) {
    if (l <= L && R <= r) {
        if (ud) add(k, x, w); else add(x, k, w);
        return;
    }
    int mid = (L + R) >> 1;
    if (l <= mid) modify(l, r, k, w, L, mid, t[x].ls, ud);
    if (mid < r) modify(l, r, k, w, mid + 1, R, t[x].rs, ud);
}

struct bibo { int pos; ll dis; bool operator < (const bibo &x) const { return dis > x.dis; } };
priority_queue <bibo> q;
bool vis[MAXN << 2]; ll dis[MAXN << 2];
void dijkstra () {
    int i, j;
    for (i = 1; i <= top; i++) dis[i] = inf;
    dis[s] = 0; q.push({s, 0});
    while (!q.empty()) {
        int f = q.top().pos; q.pop();
        if (vis[f]) continue;
        vis[f] = true;
        for (i = head[f]; i; i = edge[i].nex) {
            j = edge[i].to;
            if (dis[j] > dis[f] + edge[i].w) {
                dis[j] = dis[f] + edge[i].w;
                q.push({j, dis[j]});
            }
        }
    }
}

int main () {
    n = read(), Q = read(), s = read();
    int i, j; top = n;
    rDown = buildDown(1, n), rUp = buildUp(1, n);
    while (Q--) {
        int type = read(), u = read();
        if (type == 1) { int v = read(), w = read(); add(u, v, w); }
        else {
            int l = read(), r = read(), w = read();
            if (type == 2) modify(l, r, u, w, 1, n, rDown, true);
            else modify(l, r, u, w, 1, n, rUp, false);
        }
    }
    dijkstra();
    for (i = 1; i <= n; i++) printf("%lld ", dis[i] == inf ? -1 : dis[i]);
    return 0;
}