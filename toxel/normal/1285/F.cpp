#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;
std::mt19937 mt(19971109);

int cnt[N], mu[N], min[N];
std::vector <int> vec[N], fact[N];
std::vector <int> prime;

ll calc(int u, ll max){
    if (vec[u].empty()){
        return 0;
    }
    memset(cnt, 0, sizeof(cnt[0]) * (vec[u].back() + 1));
    int n = vec[u].size();
    ll num = 0;
    for (int i = n - 1, j = 0; i >= 0; -- i){
        while (j < n && 1ll * u * vec[u][i] * vec[u][j] <= max){
            for (auto v : fact[vec[u][j]]){
                ++ cnt[v];
            }
            ++ j;
        }
        for (auto v : fact[vec[u][i]]){
            num += mu[v] * cnt[v];
        }
    }
    return num;
}

ll check(int u, ll nowmax){
    if (vec[u].empty()){
        return nowmax;
    }
    ll total = calc(u, LLONG_MAX);
    if (calc(u, nowmax) == total){
        return nowmax;
    }
    ll left = nowmax + 1, right = ll(1e10);
    while (left < right){
        ll mid = (left + right) / 2;
        if (calc(u, mid) == total){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    mu[1] = 1;
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            mu[i] = -1;
            prime.emplace_back(i);
        }
        for (auto u : prime){
            if (i * u >= N) break;
            min[i * u] = u;
            if (i % u == 0){
                break;
            }
            mu[i * u] = -mu[i];
        }
    }
    int n;
    scanf("%d", &n);
    // n = 100000;
    for (int i = 0; i < n; ++ i){
        int x;
        scanf("%d", &x);
        //x = i + 1;
        ++ cnt[x];
    }
    for (int i = 1; i < N; ++ i){
        for (int j = i; j < N; j += i){
            if (cnt[j]){
                vec[i].emplace_back(j / i);
            }
            fact[j].emplace_back(i);
        }
    }
    memset(cnt, 0, sizeof(cnt));
    std::vector <int> order(N - 1);
    for (int i = 0; i < N - 1; ++ i){
        order[i] = i + 1;
    }
    std::shuffle(order.begin(), order.end(), mt);
    ll max = 0;
    for (auto u : order){
        max = std::max(max, check(u, max));
    }
    printf("%lld\n", max);
    return 0;
}