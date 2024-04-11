#include <bits/stdc++.h>

const int N = 200010;
const int M = 1000010;
using ll = long long;

int min[M];
std::vector <int> prime;
ll a[N];
ll ans = LLONG_MAX;
int n;

ll calc(ll x){
    ll sum = 0;
    for (int i = 0; i < n; ++ i){
        if (a[i] < x){
            sum += x - a[i];
            continue;
        }
        sum += std::min(a[i] % x, x - a[i] % x);
    }
    return sum;
}

void solve(ll x){
    if (x < 2){
        return;
    }
    for (auto u : prime){
        if (x < u){
            break;
        }
        if (x % u == 0){
            ans = std::min(ans, calc(u));
            while (x % u == 0){
                x /= u;
            }
        }
    }
    if (x > 1){
        ans = std::min(ans, calc(x));
    }
}

int main(){
    srand((unsigned) time(nullptr));
    for (int i = 2; i < M; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.emplace_back(i);
        }
        for (auto u : prime){
            if (i * u >= M) break;
            min[i * u] = u;
            if (i % u == 0){
                break;
            }
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
    }
    std::mt19937 rnd(rand());
    for (int i = 0; i < 30; ++ i){
        int pos = rnd() % n;
        solve(a[pos] - 1);
        solve(a[pos]);
        solve(a[pos] + 1);
    }
    printf("%d\n", ans);
    return 0;
}