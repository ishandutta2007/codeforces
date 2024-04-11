#include <bits/stdc++.h>

const int N = 1000010;
using ll = long long;

int min[N];
std::vector <int> prime;

int main(){
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.push_back(i);
        }
        for (auto u : prime){
            if (i * u >= N){
                break;
            }
            min[i * u] = u;
            if (i % u == 0){
                break;
            }
        }
    }
    ll n;
    scanf("%lld", &n);
    if (n == 1){
        puts("1");
        return 0;
    }
    std::set <ll> set;
    for (auto u : prime){
        if (n % u == 0){
            set.insert(u);
            while (n % u == 0){
                n /= u;
            }
        }
    }
    if (n > 1){
        set.insert(n);
    }
    if ((int) set.size() >= 2){
        puts("1");
        return 0;
    }
    printf("%lld\n", *(set.begin()));
}