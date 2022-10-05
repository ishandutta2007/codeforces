#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

int b[N];

int main(){
    int n;
    scanf("%d", &n);
    std::map <int, ll> map;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &b[i]);
        map[i - b[i]] += b[i];
    }
    ll max = 0;
    for (auto u : map){
        max = std::max(max, u.second);
    }
    printf("%lld\n", max);
    return 0;
}