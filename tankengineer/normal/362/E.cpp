#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define next NEXT

int n;

const int N = 50, M = N * N * 4;

int top, to[M], head[N], next[M], cap[M], len[M];

const int INF = 1000000007;
int dis[N], fa[N];
bool inque[N];

int source, target;

bool mincost(int &flow, int &left) {
    for (int i = 0; i < n; ++i) {
        inque[i] = false;
        dis[i] = INF;
    }
    dis[source] = 0;
    inque[source] = true;
    queue<int> q;
    q.push(source);
    while (q.size()) {
        int u = q.front();
        q.pop();
        inque[u] = false;
        for (int j = head[u]; ~j; j = next[j]) {
            if (cap[j] == 0) {
                continue;
            }
            int v = to[j], nd = dis[u] + len[j];
            if (dis[v] > nd) {
                dis[v] = nd;
                fa[v] = j;
                if (!inque[v]) {
                    q.push(v);
                    inque[v] = true;
                }
            }
        }
    }
    if (dis[target] > left) {
        return false;
    }
    int c = dis[target], p = dis[target] ? left / dis[target] : INF, u = target;
    while (u != source) {
        p = min(p, cap[fa[u]]);
        u = to[fa[u] ^ 1];
    }
    flow += p, left -= p * dis[target];
    u = target;
    while (u != source) {
        cap[fa[u]] -= p, cap[fa[u] ^ 1] += p;
        u = to[fa[u] ^ 1];
    }
    return true;
}

void addedge(int u, int v, int c, int l) {
    to[top] = v, next[top] = head[u], head[u] = top, cap[top] = c, len[top] = l, top++;
}

int main() {
    memset(head, -1, sizeof(head));
    int k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int c;
            scanf("%d", &c);
            if (c) {
                addedge(i, j, c, 0);
                addedge(j, i, 0, 0);
                addedge(i, j, INF, 1);
                addedge(j, i, 0, -1);
            }
        }
    }
    source = 0, target = n - 1;
    int flow = 0;
    while (mincost(flow, k)) {
        continue;
    }
    printf("%d\n", flow);
    return 0;
}