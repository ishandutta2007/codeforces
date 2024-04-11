#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
int min[N];
std::vector <int> prime;
int a[N], min_fact[N];
ll lcm[N];
int oracle[N];

ll answer(int x, int y){
    return std::lcm(ll(oracle[x]), ll(oracle[y]));
}

ll ask(int x, int y){
    printf("? %d %d\n", x, y);
    fflush(stdout);
    ll ans;
    scanf("%lld", &ans);
    // ans = answer(x, y);
    return ans;
}

void answer(int n){
    printf("!");
    for (int i = 1; i <= n; ++ i){
        printf(" %d", a[i]);
    }
    puts("");
    fflush(stdout);
}

std::map <int, int> defactor(ll n){
    std::map <int, int> ret;
    for (auto u : prime){
        if (n == 1){
            break;
        }
        if (n % u == 0){
            while (n % u == 0){
                ++ ret[u];
                n /= u;
            }
        }
    }
    return ret;
}

void solve(){
    int n;
    scanf("%d", &n);
    /*int start;
    scanf("%d", &start);
    for (int i = 1; i <= n; ++ i){
        oracle[i] = start + i - 1;
    }*/
    memset(a, -1, sizeof(a));
    if (n == 3){
        std::set <ll> set;
        for (int i = 1; i <= n; ++ i){
            for (int j = i + 1; j <= n; ++ j){
                set.emplace(ask(i, j));
            }
        }
        int min = -1;
        for (int i = 1; ; ++ i){
            if (1ll * i * (i + 1) == *(std::prev(set.end()))){
                min = i - 1;
                break;
            }
        }
        for (int i = 1; i <= n; ++ i){
            a[i] = i - 1 + min;
        }
        do{
            bool flag = true;
            for (int i = 1; i <= n; ++ i){
                for (int j = i + 1; j <= n; ++ j){
                    if (std::lcm(ll(a[i]), ll(a[j])) != ask(i, j)){
                        flag = false;
                        break;
                    }
                }
            }
            if (flag){
                break;
            }
        }
        while (std::next_permutation(a + 1, a + n + 1));
        answer(n);
        return;
    }
    const int NUM = 80;
    const int ATTEMPT = 50;
    for (int i = 0; i < NUM; ++ i){
        int pos = rnd() % n + 1;
        std::map <int, int> fact;
        for (int j = 0; j < ATTEMPT; ++ j){
            int pos1;
            while (true){
                pos1 = rnd() % n + 1;
                if (pos1 != pos){
                    break;
                }
            }
            std::map <int, int> fact1 = defactor(ask(pos, pos1));
            if (j == 0){
                fact = fact1;
            }
            else{
                for (auto p : fact1){
                    if (fact.count(p.first)){
                        fact[p.first] = std::min(fact[p.first], p.second);
                    }
                }
                std::vector <int> to_erase;
                for (auto p : fact){
                    if (!fact1.count(p.first)){
                        to_erase.emplace_back(p.first);
                    }
                }
                for (auto u : to_erase){
                    fact.erase(u);
                }
            }
        }
        min_fact[pos] = fact.empty() ? INT_MAX : fact.begin() -> first;
        a[pos] = 1;
        for (auto p : fact){
            for (int j = 0; j < p.second; ++ j){
                a[pos] *= p.first;
            }
        }
    }
    int pos = 0;
    for (int i = 1; i <= n; ++ i){
        if (a[i] != -1 && min_fact[i] > min_fact[pos]){
            pos = i;
        }
    }
    while (true){
        if (!pos){
            while (true){
                pos = rnd() % n + 1;
                if (a[pos] != -1){
                    break;
                }
            }
        }
        int min = INT_MAX, max = 0;
        for (int i = 1; i <= n; ++ i){
            if (a[i] != -1){
                min = std::min(min, a[i]);
                max = std::max(max, a[i]);
            }
        }
        int len = max - min + 1;
        int l = min - (n - len), r = max + (n - len);
        l = std::max(1, l), r = std::min(N - 1, r);
        std::set <int> possible;
        for (int i = l; i <= r; ++ i){
            possible.emplace(i);
        }
        for (int i = 1; i <= n; ++ i){
            if (a[i] != -1){
                possible.erase(a[i]);
            }
        }
        std::map <ll, std::vector <int>> map;
        for (auto u : possible){
            map[std::lcm(ll(u), a[pos])].emplace_back(u);
        }
        for (int i = 1; i <= n; ++ i){
            if (i == pos){
                continue;
            }
            if (a[i] != -1){
                lcm[i] = std::lcm(ll(a[i]), ll(a[pos]));
                continue;
            }
            lcm[i] = ask(i, pos);
        }
        for (int i = 1; i <= n; ++ i){
            if (a[i] == -1 && (map[lcm[i]].size()) == 1){
                a[i] = map[lcm[i]][0];
            }
        }
        bool finished = true;
        for (int i = 1; i <= n; ++ i){
            if (a[i] == -1){
                finished = false;
                break;
            }
        }
        if (finished){
            break;
        }
        pos = -1;
    }
    answer(n);
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
    /*int x = rnd() % 1000 + 1;
    std::map <ll, int> map;
    for (int i = 1; i <= 200000; ++ i){
        ++ map[std::lcm(ll(x), ll(i))];
    }
    int ans = 0;
    for (auto p : map){
        if (p.second == 1){
            ++ ans;
        }
    }
    printf("%d\n", ans);
    printf("%d\n", x);
    while (x > 1){
        printf("%d\n", min[x]);
        x /= min[x];
    }*/
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}