#include <bits/stdc++.h>

const int N = 200010;
using pii = std::pair <int, int>;
using ll = long long;

int a[N];
int cnt[N];

int main(){
    int n;
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    std::map <pii, int> map;
    int m;
    scanf("%d", &m);
    while (m --){
        int s, t, u;
        scanf("%d%d%d", &s, &t, &u);
        if (map.count({s, t})){
            int pos = map[{s, t}];
            map.erase({s, t});
            sum -= std::max(0, a[pos] - cnt[pos]);
            -- cnt[pos];
            sum += std::max(0, a[pos] - cnt[pos]);
        }
        if (u > 0){
            map[{s, t}] = u;
            int pos = u;
            sum -= std::max(0, a[pos] - cnt[pos]);
            ++ cnt[pos];
            sum += std::max(0, a[pos] - cnt[pos]);
        }
        printf("%lld\n", sum);
    }
    return 0;
}