#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

vector<int> edge[N], edge2[N];

int n, m;

bool vis[N];

int vis2[N], stamp;

bool hasCircle;

bool check(int u) {
     vis2[u] = stamp;
     bool ret = false;
     for (int i = 0; i < (int)edge[u].size(); ++i) {
         int v = edge[u][i];
         if (!vis2[v]) {
            ret |= check(v);
         } else if (vis2[v] == stamp) {
            ret = true;
         }
     }
     vis2[u] = -1;
     return ret;
}

int dfs(int u) {
    vis[u] = true;
    int ret = 1;
    for (int i = 0; i < (int)edge2[u].size(); ++i) {
        int v = edge2[u][i];
        if (!vis[v]) {
           ret += dfs(v);
        }
    }
    if (!vis2[u]) {
       ++stamp;
       hasCircle |= check(u);
    }
    return ret;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        edge[u].push_back(v);
        edge2[u].push_back(v);
        edge2[v].push_back(u);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) {
           continue;
        }
        hasCircle = false;
        int s = dfs(i);
        ans += s - 1 + hasCircle;
    }
    printf("%d\n", ans);
    return 0;
}