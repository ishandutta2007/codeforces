#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 10000, M = 2000, RN = N + M + 2, RM = (N + M * 11) << 1, INF = 1000000000;

int top, to[RM], head[RN], next[RM], cap[RM];

void addedge(int u, int v, int c) {
//cout << u << ' ' << v << ' ' << c << endl;
    to[top] = v, next[top] = head[u], cap[top] = c, head[u] = top++;
}

int source, target;

bool over;

int dis[RN], gap[RN + 2];

int go(int u, int delta) {
    if (u == target) {
        return delta;
    }
    
    int t = delta, tmp, mindis = RN;
    bool flag = false;
    
    for (int j = head[u]; ~j; j = next[j]) {
        if (cap[j]) {
            int v = to[j];
            mindis = min(mindis, dis[v]);
            if (dis[v] == dis[u] - 1) {
                flag = true;
                tmp = min(t, cap[j]);
                tmp = go(v, tmp);
                t -= tmp, cap[j] -= tmp, cap[j ^ 1] += tmp;
                if (over || delta == 0) {
                    return delta - t;
                }
            }
        }
    }
    
    if (!flag) {
        --gap[dis[u]];
        if (dis[u] > dis[target] && dis[u] < dis[source] && gap[dis[u]] == 0) {
            over = true;
        }
        ++gap[dis[u] = mindis + 1];
    }
    
    return delta - t;
}

int flow(int n) {
    for (int i = 0; i < n; ++i) {
        dis[i] = 0;
    }
    int f = 0; 
    over = false;
    while (dis[source] < n && !over) {
        f += go(source, INF);
    }
    return f;
}

int n, m, g;

int dog[N];

int main() {
//freopen("E2.in", "r", stdin);
    memset(head, -1, sizeof(head));
    scanf("%d%d%d", &n, &m, &g);
    int sum = 0;
    source = 0, target = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", dog + i);
    }
    for (int i = 0; i < n; ++i) {
        int c; 
        scanf("%d", &c);
        if (dog[i]) {
            addedge(i + 2, target, c);
            addedge(target, i + 2, 0);
        } else {
            addedge(source, i + 2, c);
            addedge(i + 2, source, 0);
        }
    }
    for (int i = 0; i < m; ++i) {
        int ag, w, k;
        scanf("%d%d%d", &ag, &w, &k);
        sum += w;
        int u = 2 + n + i;
        for (int j = 0; j < k; ++j) {
            int v;
            scanf("%d", &v);
            --v;
            addedge(u, v + 2, INF * (1 - ag));
            addedge(v + 2, u, INF * ag); 
        }
        int isfriend;
        scanf("%d", &isfriend);
        if (isfriend) {
            w += g;
        }
        if (ag) {
            addedge(u, target, w);
            addedge(target, u, 0);
        } else {
            addedge(source, u, w);
            addedge(u, source, 0);
        }
    }
    printf("%d\n", sum - flow(n + m + 2));
    return 0;
}