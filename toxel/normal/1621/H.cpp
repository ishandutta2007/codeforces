//
// Created by  on 2022/1/6.
//

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define endl dont_use_endl

using ll = int64_t;
using i128 = __int128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;

const int N = 200010;
const int SIGMA = 26;

std::vector <pii> e[N];
int col[N];
ll dep[N], last[N][SIGMA];
int pass[SIGMA], fine[N];
ll basic[N][SIGMA];
int state[N];
int T;
std::vector <int> vec[N];
std::set <int> set[N];

ll get(ll len){
    return (len + T - 1) / T;
}

void dfs(int u, int fa){
    ll start = 0;
    for (int i = 0; i < col[u]; ++ i){
        if (last[u][i] == -1){
            continue;
        }
        ll end = last[u][i];
        basic[u][i] = get(end - start);
        ll target = get(dep[u] - start) - get(dep[u] - end);
        ll diff = basic[u][i] - target;
        assert(0 <= diff && diff <= 1);
        state[u] |= diff << i;
        start = end;
    }
    set[u].emplace(state[u]);
    last[u][col[u]] = std::max(last[u][col[u]], dep[u]);
    for (auto [v, w] : e[u]){
        if (v == fa){
            continue;
        }
        dep[v] = dep[u] + w;
        memcpy(last[v], last[u], sizeof(last[u]));
        dfs(v, u);
        if (col[v] == col[u]){
            for (auto x : vec[v]){
                set[u].emplace(x);
            }
        }
    }
    for (auto x : set[u]){
        vec[u].emplace_back(x);
    }
}

void solve(){
    int n;
    std::cin >> n;
    for (int i = 0; i < n - 1; ++ i){
        int u, v, t;
        std::cin >> u >> v >> t;
        e[u].emplace_back(v, t);
        e[v].emplace_back(u, t);
    }
    int k;
    std::cin >> k;
    std::string str;
    std::cin >> str;
    for (int i = 1; i <= n; ++ i){
        col[i] = str[i - 1] - 'A';
    }
    for (int i = 0; i < k; ++ i){
        std::cin >> pass[i];
    }
    for (int i = 0; i < k; ++ i){
        std::cin >> fine[i];
    }
    std::cin >> T;
    memset(last, -1, sizeof(last));
    dfs(1, 0);
    int test;
    std::cin >> test;
    while (test --){
        int type;
        std::cin >> type;
        if (type == 1){
            std::string i;
            int c;
            std::cin >> i >> c;
            pass[i[0] - 'A'] = c;
        }
        else if (type == 2){
            std::string i;
            int c;
            std::cin >> i >> c;
            fine[i[0] - 'A'] = c;
        }
        else if (type == 3){
            int u;
            std::cin >> u;
            std::vector <ll> sub(k);
            ll sum = 0;
            for (int i = 0; i < col[u]; ++ i){
                if (last[u][i] == -1){
                    continue;
                }
                ll big = std::min(i128(basic[u][i]) * fine[i], i128(pass[i]));
                ll small = std::min(i128(basic[u][i] - 1) * fine[i], i128(pass[i]));
                sum += big;
                sub[i] = big - small;
            }
            ll sub_max = 0;
            for (auto v : vec[u]){
                ll sum1 = 0;
                for (int i = 0; i < col[u]; ++ i){
                    if (v >> i & 1){
                        sum1 += sub[i];
                    }
                }
                sub_max = std::max(sub_max, sum1);
            }
            std::cout << sum - sub_max << '\n';
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test = 1;
    // std::cin >> test;
    while (test --){
        solve();
    }
    return 0;
}