#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int MAXN = 111111;
int f[MAXN][2], fa[MAXN], dep[MAXN], head[MAXN], po[MAXN];
int dep2[MAXN], dep1[MAXN];
int bad[MAXN];
int tot;
struct Edge{
    int to, nxt;
}nod[MAXN * 2];

void add(int x, int y) {
    nod[++tot].nxt = head[x];
    head[x] = tot;
    nod[tot].to = y;
}

void chkmax(int &x, int y) { 
    x = max(x, y);
}
void dfs(int x) {
    for (int p = head[x]; p; p = nod[p].nxt) {
        if (!dep[nod[p].to]) {
            dep[nod[p].to] = dep[x] + 1;
            dfs(nod[p].to);
        }
    }
}

void re_dfs(int x) {
    for (int p = head[x]; p; p = nod[p].nxt) {
        if (!dep1[nod[p].to]) {
            dep1[nod[p].to] = dep1[x] + 1;
            re_dfs(nod[p].to);
        }
    }
}

void re_dfs2(int x) {
    for (int p = head[x]; p; p = nod[p].nxt) {
        if (!dep2[nod[p].to]) {
            dep2[nod[p].to] = dep2[x] + 1;
            re_dfs2(nod[p].to);
        }
    }
}   

int main() {
    int n, m, distance;
    scanf("%d%d%d", &n, &m, &distance);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &po[i]);
        bad[po[i]] = 1;
    }
    
    for (int i = 1; i <= n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    
    dep[0] = 0;
    dep[1] = 1;
    dfs(1);
    int best = 0;
    for (int i = 1; i <= m; i++) {
        if (dep[po[i]] > dep[best]) {
            best = po[i];
        }
    }
    dep1[best] = 1;
    
    re_dfs(best);
    
    dep1[0] = 0;
    best = 0;
    for (int i = 1; i <= m; i++) {
        if (dep1[po[i]] > dep1[best]) best = po[i];
    }
    dep2[best] = 1;
    re_dfs2(best);
    
    int ans = 0;
    
    for (int i = 1; i <= n; i++) {
        if (dep1[i] - 1 <= distance && dep2[i] - 1 <= distance) ans++;
    }
    
    cout << ans << endl;
    return 0;
}