#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;
using pii = std::pair <ll, ll>;

ll a[N], c[N];
ll pre_max[N];
pii p[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%lld%lld", &a[i], &c[i]);
        p[i] = {a[i], c[i]};
    }
    std::sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; ++ i){
        pre_max[i] = std::max(pre_max[i - 1], p[i].first + p[i].second);
    }
    int cur = 1;
    ll value = pre_max[1];
    ll sum = 0;
    for (int i = 2; i <= n; ++ i){
        if (value < p[i].first){
            sum += p[i].first - value;
        }
        value = pre_max[i];
    }
    for (int i = 1; i <= n; ++ i){
        sum += c[i];
    }
    printf("%lld\n", sum);
    return 0;
}