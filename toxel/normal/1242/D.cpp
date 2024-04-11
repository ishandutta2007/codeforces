#include <bits/stdc++.h>

using ll = long long;

ll calc(ll n, ll k){
    if (n == 0){
        return k * (k + 1) / 2;
    }
    ll pos = calc(n / k, k);
    ll l = n * k + n / k + 1, r = l + k;
    ll sum = (l + r - 1) * k / 2;
    if (pos < r){
        sum += std::min(r - pos, k);
    }
    return sum;
}

ll solve(ll n, ll k){
    ll round = (n - 1) / (k * k + 1);
    ll pos = calc(round, k);
    if (pos == n){
        return (round + 1) * (k + 1);
    }
    else{
        ll sum = round + (pos < n);
        return (n - sum - 1) / k + n - sum;
    }
}

const int N = 1010;

int vis[N];
int id[N];

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        ll n, k;
        scanf("%lld%lld", &n, &k);
        printf("%lld\n", solve(n, k));
    }
    return 0;
}