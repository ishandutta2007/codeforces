#include <bits/stdc++.h>

const int N = 100010;
const int moder = (int) 1e9 + 7;
typedef long long ll;

ll gcd(ll x, ll y){
    if (x == 0){
        return y;
    }
    if (y == 0){
        return x;
    }
    return std::__gcd(x, y);
}

ll x[N];
std::vector <int> e[N];
int ans = 0;

void dfs(int u, int fa, std::map <ll, int> map){
    std::map <ll, int> nmap;
    nmap[x[u]] = 1;
    for (auto p : map){
        nmap[gcd(p.first, x[u])] += p.second;
    }
    for (auto p : nmap){
        ans = (ans + (p.first % moder) * p.second) % moder;
    }
    for (auto v : e[u]){
        if (v == fa){
            continue;
        }
        dfs(v, u, nmap);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%lld", &x[i]);
    }
    for (int i = 0, u, v; i < n - 1; ++ i){
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0, std::map <ll, int>());
    printf("%d\n", ans);
    return 0;
}