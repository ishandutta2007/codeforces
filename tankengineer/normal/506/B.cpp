#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, m;

int fa[N];

int find(int u) {
    return u == fa[u] ? u : fa[u] = find(fa[u]);
}

void merge(int u, int v) {
    fa[u] = v;
}

int cnt[N], ord[N];

vector<pair<int, int> > e[N];

vector<int> edge[N];

int dgr[N];

int solve(vector<pair<int, int> > e, int n) {
    for (int i = 0; i < n; ++i) {
        edge[i].clear();
        dgr[i] = 0;
    }
    for (int i = 0; i < (int)e.size(); ++i) {
        edge[e[i].first].push_back(e[i].second);
        ++dgr[e[i].second];
    }
    int cnt = 0;
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (dgr[i] == 0) {
            q.push(i);
        }
    }
    while (q.size()) {
        ++cnt;
        int u = q.front();
        q.pop();
        for (int i = 0; i < (int)edge[u].size(); ++i) {
            int v = edge[u][i];
            if ((--dgr[v]) == 0) {
                q.push(v);
            }
        }
    }
    return cnt == n ? n - 1 : n;
}

const int M = 100005;

int u[M], v[M];

int main() {
    scanf("%d%d", &n, &m);    
    for (int i = 0; i < n; ++i) {
        fa[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", u + i, v + i);
        int uu = find(u[i]), vv = find(v[i]);
        if (uu != vv) {
            merge(uu, vv);
        }
    }
    for (int i = 0; i < n; ++i) {
        ord[i] = cnt[find(i)]++;
    } 
    for (int i = 0; i < m; ++i) {
        e[find(u[i])].push_back(make_pair(ord[u[i]], ord[v[i]]));
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (e[i].size()) {
            ans += solve(e[i], cnt[i]);
        }
    }
    printf("%d\n", ans); 
    return 0;
}