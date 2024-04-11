#include <bits/stdc++.h>

const int N = 100010;
using pii = std::pair <int, int>;

int l[N], r[N], c[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d%d", &l[i], &r[i], &c[i]);
    }
    std::map <pii, int> map;
    std::map <int, int> map1, map2;
    int ll = INT_MAX, rr = INT_MIN;
    for (int i = 0; i < n; ++ i){
        ll = std::min(ll, l[i]);
        rr = std::max(rr, r[i]);
        pii p = {l[i], r[i]};
        if (map.count(p)){
            map[p] = std::min(map[p], c[i]);
        }
        else{
            map[p] = c[i];
        }
        if (map1.count(l[i])){
            map1[l[i]] = std::min(map1[l[i]], c[i]);
        }
        else{
            map1[l[i]] = c[i];
        }
        if (map2.count(r[i])){
            map2[r[i]] = std::min(map2[r[i]], c[i]);
        }
        else{
            map2[r[i]] = c[i];
        }
        int ans = INT_MAX;
        if (map.count({ll, rr})){
            ans = std::min(ans, map[{ll, rr}]);
        }
        ans = std::min(ans, map1[ll] + map2[rr]);
        printf("%d\n", ans);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}