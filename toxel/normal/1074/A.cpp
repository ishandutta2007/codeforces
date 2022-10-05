#include<bits/stdc++.h>

const int N = 100010;

int a[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    n = std::unique(a, a + n) - a;
    std::map <int, int> map;
    for (int i = 0; i < m; ++ i){
        int x1, x2, y;
        scanf("%d%d%d", &x1, &x2, &y);
        if (x1 == 1){
            ++ map[x2];
        }
    }
    int now = 0;
    for (auto &u : map){
        now += u.second;
        u.second = now;
    }
    int ans = INT_MAX;
    for (int i = 0; i <= n; ++ i){
        auto u = map.lower_bound(i == n ? 1000000000 : a[i]);
        int x = i;
        if (u != map.begin()){
            x += now - (-- u) -> second;
        }
        else{
            x += now;
        }
        ans = std::min(ans, x);
    }
    printf("%d\n", ans);
    return 0;
}