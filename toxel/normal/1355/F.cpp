#include <bits/stdc++.h>

using ll = long long;
const int MAX = int(1e9);
const ll MMAX = 1ll * MAX * MAX;
const int SPLIT1 = 321;
const int SPLIT2 = 629;
const int N = SPLIT2;

std::vector<int> min, prime;

/*int count(int n){
    int cnt = 0;
    for (auto u : prime){
        cnt += u <= n;
    }
    return cnt;
}*/

ll ask(ll n){
    printf("? %lld\n", n);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}

void init() {
    min.resize(N);
    for (int i = 2; i < N; ++i) {
        if (!min[i]) {
            min[i] = i;
            prime.push_back(i);
        }
        for (auto u : prime) {
            if (i * u >= N) {
                break;
            }
            min[i * u] = u;
            if (i % u == 0) {
                break;
            }
        }
    }
}

void solve(){
    int sz = prime.size();
    std::vector<int> fact;
    bool asked = false;
    for (int i = 0, j = 0; i < sz; i = j){
        ll prod = 1;
        while (j < sz && prod <= MMAX / prime[j]){
            prod *= prime[j];
            ++ j;
        }
        int value = ask(prod);
        for (int k = i; k < j; ++ k){
            if (value % prime[k] == 0){
                fact.emplace_back(prime[k]);
            }
        }
        if (prime[j - 1] >= SPLIT1){
            if (int(fact.size()) == 0){
                puts("! 8");
                return;
            }
            else if (int(fact.size()) == 1 && !asked){
                asked = true;
                if (ask(fact[0] * fact[0]) == fact[0]){
                    puts("! 8");
                    return;
                }
            }
            else if (int(fact.size()) >= 3){
                break;
            }
        }
    }
    int x = 1;
    for (int i = 0; i < int(fact.size()); i += 2){
        ll prod1 = 1, prod2 = 1;
        while (prod1 * fact[i] <= MAX){
            prod1 *= fact[i];
        }
        while (i + 1 < int(fact.size()) && prod2 * fact[i + 1] <= MAX){
            prod2 *= fact[i + 1];
        }
        x *= ask(prod1 * prod2);
    }
    int ans = 0;
    for (int i = 1; i * i <= x; ++ i){
        if (x % i == 0){
            ++ ans;
            if (i * i != x){
                ++ ans;
            }
        }
    }
    printf("! %d\n", ans * 2);
    fflush(stdout);
}

int main(){
    init();
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}