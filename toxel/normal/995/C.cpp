#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pii;

inline ll sqr(int n){return 1ll * n * n;}

const int N = (int) 2e5 + 10;
const ll MAX = (ll) 1e12;

int x[N], y[N], ans[N];
std::vector <pii> e[N];

void dfs(int u){
    for (auto v : e[u]){
        ans[v.first] = ans[u] * v.second;
        dfs(v.first);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &x[i], &y[i]);
    }
    if (n == 1){
        puts("1");
        return 0;
    }
    int left = 0;
    for (int i = 0; i < n - 2; ++ i){
        std::vector <pii> type = {{left, i << 1 | 1}, {left, (i << 1) + 2}, {i << 1 | 1, (i << 1) + 2}};
        bool flag = false;
        for (auto u : type){
            for (int j = -1; j <= 1; j += 2){
                for (int k = -1; k <= 1; k += 2){
                    if (!flag && sqr(x[u.first] * j + x[u.second] * k) + sqr(y[u.first] * j + y[u.second] * k) <= MAX){
                        flag = true;
                        x[n + i] = x[u.first] * j + x[u.second] * k;
                        y[n + i] = y[u.first] * j + y[u.second] * k;
                        e[n + i].push_back({u.first, j});
                        e[n + i].push_back({u.second, k});
                        left = u.first == left ? u.second == (i << 1 | 1) ? (i << 1) + 2 : i << 1 | 1 : left;
                        break;
                    }
                }
            }
        }
    }
    if (sqr(x[left] + x[2 * n - 3]) + sqr(y[left] + y[2 * n - 3]) <= MAX){
        e[n + n - 2].push_back({left, 1});
        e[n + n - 2].push_back({2 * n - 3, 1});
    }
    else{
        e[n + n - 2].push_back({left, 1});
        e[n + n - 2].push_back({2 * n - 3, -1});
    }
    ans[n + n - 2] = 1;
    dfs(n + n - 2);
    for (int i = 0; i < n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    }
    return 0;
}