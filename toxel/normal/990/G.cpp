#include<bits/stdc++.h>

const int N = 200010;
typedef long long ll;
typedef std::pair <int, int> pii;

std::vector <int> e[N], vec[N], pvec[N];
std::vector <int> prime;
int min[N], mu[N], v[N], cnt[N], ccnt[N];
ll ans[N];
bool vis[N];
pii p[N];

void addedge(int u, int v){
    e[u].push_back(v);
    e[v].push_back(u);
}

int dfs(int u){
    vis[u] = true;
    int ret = 1;
    for (auto v : e[u]){
        if (vis[v]) continue;
        ret += dfs(v);
    }
    return ret;
}

int main(){
    //freopen("data.txt", "r", stdin);
    mu[1] = 1;
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            mu[i] = -1;
            prime.push_back(i);
        }
        for (int j = 0, k; j < prime.size() && i * prime[j] < N; ++ j){
            min[k = i * prime[j]] = prime[j];
            if (i % prime[j] == 0){
                mu[k] = 0;
                break;
            }
            mu[k] = -mu[i];
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &v[i]);
        ++ ccnt[v[i]];
    }
    for (int i = 1; i < N; ++ i){
        for (int j = i; j < N; j += i){
            cnt[i] += ccnt[j];
        }
    }
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        p[i] = {u, v};
        int x = std::__gcd(::v[u], ::v[v]);
        vec[x].push_back(i);
    }
    for (int i = 1; i < N; ++ i){
        for (int j = i; j < N; j += i){
            for (auto u : vec[j]){
                vis[p[u].first] = false;
                vis[p[u].second] = false;
                e[p[u].first].clear();
                e[p[u].second].clear();
            }
        }
        for (int j = i; j < N; j += i){
            for (auto u : vec[j]){
                addedge(p[u].first, p[u].second);
            }
        }
        for (int j = i; j < N; j += i){
            for (auto u : vec[j]){
                if (!vis[p[u].first]){
                    int x = dfs(p[u].first);
                    ans[i] += 1ll * x * (x + 1) >> 1;
                    cnt[i] -= x;
                }
                if (!vis[p[u].second]){
                    int x = dfs(p[u].second);
                    ans[i] += 1ll * x * (x + 1) >> 2;
                    cnt[i] -= x;
                }
            }
        }
        ans[i] += cnt[i];
    }
    for (int i = 1; i < N; ++ i){
        for (int j = i << 1; j < N; j += i){
            ans[i] += ans[j] * mu[j / i];
        }
    }
    for (int i = 1; i < N; ++ i){
        if (ans[i]){
            printf("%d %lld\n", i, ans[i]);
        }
    }
    return 0;
}