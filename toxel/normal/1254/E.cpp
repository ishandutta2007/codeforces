#include <bits/stdc++.h>

const int N = 500010;
const int moder = (int) 1e9 + 7;
using pii = std::pair <int, int>;

int fac[N];
std::vector <int> e[N];
int a[N], dep[N], fa[N];
std::vector <pii> after[N];
int begin[N], end[N];
int next[N];
bool vis[N], deg_0[N];

void dfs(int u, int fa){
    ::fa[u] = fa;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

int main(){
    fac[0] = 1;
    for (int i = 1; i < N; ++ i){
        fac[i] = 1ll * i * fac[i - 1] % moder;
    }
    int n;
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    dfs(1, 0);
    int sum = 0;
    for (int i = 1; i <= n; ++ i){
        if (a[i] == i){
            puts("0");
            return 0;
        }
        if (a[i] == 0){
            continue;
        }
        int u = i, v = a[i];
        if (dep[u] < dep[v]){
            std::swap(u, v);
        }
        std::vector <int> left, right;
        while (dep[u] > dep[v]){
            left.push_back(u);
            u = fa[u];
        }
        while (u != v){
            left.push_back(u);
            right.push_back(v);
            u = fa[u], v = fa[v];
        }
        left.push_back(u);
        for (int j = (int) right.size() - 1; j >= 0; -- j){
            left.push_back(right[j]);
        }
        sum += (int) left.size() - 1;
        if (sum > 2 * n - 2){
            puts("0");
            return 0;
        }
        if (left[0] != i){
            std::reverse(left.begin(), left.end());
        }
        if (begin[left[0]] && begin[left[0]] != left[1]){
            puts("0");
            return 0;
        }
        begin[left[0]] = left[1];
        if (end[left.back()] && end[left.back()] != left[(int) left.size() - 2]){
            puts("0");
            return 0;
        }
        end[left.back()] = left[(int) left.size() - 2];
        for (int j = 1, sz = (int) left.size(); j < sz - 1; ++ j){
            after[left[j]].push_back({left[j - 1], left[j + 1]});
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; ++ i){
        for (auto p : after[i]){
            if (next[p.first] && next[p.first] != p.second){
                puts("0");
                return 0;
            }
            if (p.second == begin[i]){
                puts("0");
                return 0;
            }
            next[p.first] = p.second;
            deg_0[p.second] = true;
        }
        if (next[end[i]]){
            puts("0");
            return 0;
        }
        int cnt = 0, total = 0;
        for (auto v : e[i]){
            if (deg_0[v]){
                continue;
            }
            int x = v;
            int last = 0, now_cnt = 0;
            while (true){
                last = x;
                vis[x] = true;
                ++ now_cnt;
                x = next[x];
                if (x == 0){
                    break;
                }
                if (vis[x]){
                    puts("0");
                    return 0;
                }
            }
            if (v == begin[i] && last == end[i] && now_cnt != (int) e[i].size()){
                puts("0");
                return 0;
            }
            ++ cnt;
            total += now_cnt;
        }
        if (total != (int) e[i].size()){
            puts("0");
            return 0;
        }
        ans = 1ll * ans * fac[std::max(0, cnt - (begin[i] != 0) - (end[i] != 0))] % moder;
        for (auto v : e[i]){
            next[v] = 0;
            vis[v] = deg_0[v] = false;
        }
    }
    printf("%d\n", ans);
    return 0;
}