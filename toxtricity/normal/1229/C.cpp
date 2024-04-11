#include <bits/stdc++.h>

const int N = 100010;
typedef long long ll;

std::vector <int> big[N];
int smallsz[N];

ll comb(int n){
    return 1ll * n * (n - 1) / 2;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i){
        int u, v;
        scanf("%d%d", &u, &v);
        if (u > v){
            std::swap(u, v);
        }
        ++ smallsz[v];
        big[u].push_back(v);
    }
    /*int n = 400;
    for (int i = 1; i < n; ++ i){
        for (int j = i + 1; j <= n; ++ j){
            int u = i, v = j;
            if (u > v){
                std::swap(u, v);
            }
            ++ smallsz[v];
            big[u].push_back(v);
        }
    }*/
    ll ans = 0;
    for (int i = 1; i <= n; ++ i){
        ans += comb(smallsz[i] + big[i].size());
        ans -= comb(smallsz[i]) + comb(big[i].size());
    }
    printf("%lld\n", ans);
    int test;
    scanf("%d", &test);
    while (test --){
        int u;
        scanf("%d", &u);
        for (auto v : big[u]){
            ans += comb(smallsz[v]) + comb(big[v].size());
            -- smallsz[v];
            big[v].push_back(u);
            ans -= comb(smallsz[v]) + comb(big[v].size());
        }
        ans += comb(smallsz[u]) + comb(big[u].size());
        smallsz[u] += big[u].size();
        std::vector <int>().swap(big[u]);
        ans -= comb(smallsz[u]) + comb(big[u].size());
        printf("%lld\n", ans);
    }
    return 0;
}