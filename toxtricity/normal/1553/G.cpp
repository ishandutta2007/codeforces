#include <bits/stdc++.h>

const int N = 1000010;

int a[N];
int min[N];
std::vector <int> prime;
std::vector <int> vec[N];
int fa[N];
std::vector <int> available[N];
std::vector <int> primes[N];
int inv[N], invp[N];

int find(int u){
    return fa[u] == u ? fa[u] : (fa[u] = find(fa[u]));
}

void unite(int u, int v){
    u = find(u), v = find(v);
    if (u == v) return;
    fa[u] = v;
}

int main(){
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.emplace_back(i);
        }
        for (auto u : prime){
            if (i * u >= N) break;
            min[i * u] = u;
            if (i % u == 0) break;
        }
    }
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        inv[a[i]] = i;
        fa[i] = i;
    }
    for (int i = 1; i <= n; ++ i){
        int x = a[i];
        while (x > 1){
            int tmp = min[x];
            vec[tmp].emplace_back(i);
            while (x % tmp == 0){
                x /= tmp;
            }
        }
    }
    for (auto u : prime){
        if (vec[u].empty()){
            continue;
        }
        int sz = vec[u].size();
        for (int i = 0; i < sz - 1; ++ i){
            unite(vec[u][i], vec[u][i + 1]);
        }
    }
    for (int i = 1; i <= n; ++ i){
        int x = a[i];
        while (x > 1){
            int tmp = min[x];
            primes[find(i)].emplace_back(tmp);
            invp[tmp] = find(i);
            while (x % tmp == 0){
                x /= tmp;
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (find(i) != i){
            continue;
        }
        std::sort(primes[i].begin(), primes[i].end());
        primes[i].erase(std::unique(primes[i].begin(), primes[i].end()), primes[i].end());
        for (auto u : primes[i]){
            for (int j = u; j < N; j += u){
                if (inv[j - 1] != 0){
                    int x = i, y = find(inv[j - 1]);
                    available[x].emplace_back(y);
                    available[y].emplace_back(x);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        std::vector <int> factor;
        int x = a[i] + 1;
        while (x > 1){
            int tmp = min[x];
            factor.emplace_back(tmp);
            while (x % tmp == 0){
                x /= tmp;
            }
        }
        int sz = factor.size();
        for (int i = 0; i < sz; ++ i){
            for (int j = i + 1; j < sz; ++ j){
                int x = invp[factor[i]], y = invp[factor[j]];
                if (x != 0 && y != 0){
                    available[x].emplace_back(y);
                    available[y].emplace_back(x);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++ i){
        std::sort(available[i].begin(), available[i].end());
        available[i].erase(std::unique(available[i].begin(), available[i].end()), available[i].end());
    }
    while (q --){
        int s, t;
        scanf("%d%d", &s, &t);
        if (find(s) == find(t)){
            puts("0");
            continue;
        }
        s = find(s), t = find(t);
        auto u = std::lower_bound(available[s].begin(), available[s].end(), t);
        if (u != available[s].end() && *u == t){
            puts("1");
        }
        else{
            puts("2");
        }
    }
    return 0;
}