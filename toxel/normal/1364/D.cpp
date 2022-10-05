#include <bits/stdc++.h>

const int N = 100010;

std::vector<int> e[N];
int dis[N];
std::vector<int> stack, ring;
bool vis[N], instack[N];
int inv[N];

void tree(int u, int fa){
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dis[v] = dis[u] + 1;
        tree(v, u);
    }
}

void dfs(int u, int fa){
    if (!ring.empty()){
        return;
    }
    if (vis[u]){
        return;
    }
    vis[u] = true;
    instack[u] = true;
    stack.emplace_back(u);
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        if (instack[v]){
            while (stack.back() != v){
                ring.emplace_back(stack.back());
                stack.pop_back();
            }
            ring.emplace_back(v);
            return;
        }
        dfs(v, u);
        if (!ring.empty()){
            return;
        }
    }
    stack.pop_back();
    instack[u] = false;
}

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    if (m == n - 1){
        tree(1, 0);
        int cnt = 0;
        for (int i = 1; i <= n; ++ i){
            cnt += dis[i] & 1;
        }
        std::vector<int> vec;
        for (int i = 1; i <= n; ++ i){
            if (cnt >= n - cnt && (dis[i] & 1)){
                vec.emplace_back(i);
            }
            if (cnt < n - cnt && !(dis[i] & 1)){
                vec.emplace_back(i);
            }
        }
        int num = (k + 1) / 2;
        vec.resize(num);
        puts("1");
        for (int i = 0; i < num; ++ i){
            printf("%d%c", vec[i], " \n"[i == num - 1]);
        }
        return 0;
    }
    dfs(1, 0);
    int sz = ring.size();
    int l = 0, r = sz - 1;
    memset(inv, -1, sizeof(inv));
    for (int i = 0; i < sz; ++ i){
        inv[ring[i]] = i;
    }
    for (int i = l; i < r; ++ i){
        int min = INT_MAX;
        for (auto v : e[ring[i]]){
            if (inv[v] != -1 && inv[v] > i + 1 && inv[v] <= r){
                min = std::min(min, inv[v]);
            }
        }
        if (min != INT_MAX){
            l = i;
            r = min;
        }
    }
    if (r - l + 1 <= k){
        printf("2\n%d\n", r - l + 1);
        for (int i = l; i <= r; ++ i){
            printf("%d%c", ring[i], " \n"[i == r]);
        }
        return 0;
    }
    puts("1");
    int num = (k + 1) / 2;
    for (int i = 0, cur = l; i < num; ++ i, cur += 2){
        printf("%d%c", ring[cur], " \n"[i == num - 1]);
    }
    return 0;
}