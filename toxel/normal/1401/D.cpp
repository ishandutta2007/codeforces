#include <bits/stdc++.h>

const int N = 100010;
const int moder = int(1e9) + 7;
using ll = long long;

std::vector<int> e[N];
std::vector<ll> ans;
int sz[N];

void dfs(int u, int fa, int n){
    sz[u] = 1;
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u, n);
        sz[u] += sz[v];
        ans.emplace_back(1ll * sz[v] * (n - sz[v]));
    }
}

void solve(){
    for (int i = 0; i < N; ++ i){
        e[i].clear();
    }
    ans.clear();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1, 0, n);
    std::sort(ans.begin(), ans.end());
    int m;
    scanf("%d", &m);
    std::vector<int> vec(m);
    for (int i = 0; i < m; ++ i){
        scanf("%d", &vec[i]);
    }
    std::sort(vec.begin(), vec.end(), std::greater<>());
    int ret = 0;
    for (int i = 0; i < n - 1; ++ i){
        int left = n - 1 - i;
        int coe = 0;
        if (int(vec.size()) < left){
            coe = 1;
        }
        else if (i == n - 2){
            coe = 1;
            for (auto u : vec){
                coe = 1ll * coe * u % moder;
            }
        }
        else{
            coe = vec.back();
            vec.pop_back();
        }
        ret = (ret + ans[i] % moder * coe) % moder;
    }
    printf("%d\n", ret);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}