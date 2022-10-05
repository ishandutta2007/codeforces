#include <bits/stdc++.h>

const int N = 2010;

std::bitset <N> set[N], set1[N];
int fa[N];
char s[N];
bool vis[N], vis1[N];

int find(int u){
    return fa[u] == u ? u : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v){
        return;
    }
    fa[u] = v;
}

void solve(){
    memset(vis, 0, sizeof(vis));
    memset(vis1, 0, sizeof(vis1));
    int cnt = 0, cnt1 = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        set[i].reset();
        fa[i] = i;
    }
    for (int i = 0; i < m; ++ i){
        set1[i].reset();
        scanf("%s", s);
        for (int j = 0; j < n; ++ j){
            set[j][i] = set1[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < m; ++ i){
        if (set1[i].count() == 1){
            int pos = set1[i]._Find_first();
            set[pos][i] = false;
            vis1[i] = true;
            ++ cnt1;
        }
    }
    using pii = std::pair <int, int>;
    std::queue <pii> queue;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (i == j){
                continue;
            }
            if ((set[i] & set[j]) == set[j]){
                queue.emplace(i, j);
            }
        }
    }
    std::vector <pii> edge;
    while (cnt1 < m){
        pii p = {-1, -1};
        while (!queue.empty()){
            pii u = queue.front();
            queue.pop();
            if (vis[u.first] || vis[u.second]){
                continue;
            }
            if ((set[u.first] & set[u.second]) != set[u.second]){
                continue;
            }
            p = u;
            break;
        }
        if (p.first == -1){
            puts("NO");
            return;
        }
        vis[p.second] = true;
        edge.push_back(p);
        unite(p.first, p.second);
        ++ cnt;
        for (int pos = set[p.second]._Find_first(); pos < N; pos = set[p.second]._Find_next(pos)){
            set1[pos][p.second] = false;
            if (set1[pos].count() == 1){
                int pos1 = set1[pos]._Find_first();
                set[pos1][pos] = false;
                vis1[pos] = true;
                ++ cnt1;
                for (int i = 0; i < n; ++ i){
                    if (vis[i] || i == pos1){
                        continue;
                    }
                    if ((set[i] & set[pos1]) == set[pos1]){
                        queue.emplace(i, pos1);
                    }
                }
            }
        }
    }
    for (int i = 1; i < n; ++ i){
        if (find(i) != find(0)){
            edge.emplace_back(i, 0);
            unite(i, 0);
        }
    }
    puts("YES");
    for (auto u : edge){
        printf("%d %d\n", u.first + 1, u.second + 1);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}