#include <bits/stdc++.h>

const int N = 500010;
using ll = long long;

std::vector <int> vec[N];
std::vector <int> id[N];
ll c[N], tot[N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++ i){
        scanf("%lld", &c[i]);
    }
    for (int i = 0, u, v; i < m; ++ i){
        scanf("%d%d", &u, &v);
        vec[v].emplace_back(u);
        tot[u] += c[v];
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++ i){
        std::sort(vec[i].begin(), vec[i].end());
        id[vec[i].size()].emplace_back(i);
        if (tot[i] > 0){
            ans = std::__gcd(ans, tot[i]);
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (id[i].empty()){
            continue;
        }
        std::sort(id[i].begin(), id[i].end(), [&](const int &p1, const int &p2){return vec[p1] < vec[p2];});
        int sz = id[i].size();
        for (int j = 0, k = 0; j < sz; j = k){
            while (k < sz && vec[id[i][j]] == vec[id[i][k]]){
                ++ k;
            }
            ll sum = 0;
            for (int u = j; u < k; ++ u){
                sum += c[id[i][u]];
            }
            ans = std::__gcd(ans, sum);
        }
    }
    printf("%lld\n", ans);
    for (int i = 0; i <= n; ++ i){
        std::vector <int>().swap(vec[i]);
        std::vector <int>().swap(id[i]);
        tot[i] = 0;
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