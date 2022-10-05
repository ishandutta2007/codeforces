#include <bits/stdc++.h>

const int N = 200010;
using ll = long long;

int a[N], t[N];
std::map <int, std::vector <int>> map;

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &t[i]);
    }
    for (int i = 0; i < n; ++ i){
        map[a[i]].emplace_back(t[i]);
    }
    std::multiset <int> set;
    int cur_time = 0;
    ll ans = 0, sum = 0;
    while (!map.empty() || !set.empty()){
        decltype(map.begin()) u;
        if (set.empty()){
            u = map.begin();
        }
        else{
            ++ cur_time;
            u = map.find(cur_time);
        }
        if (u != map.end()){
            cur_time = u -> first;
            for (auto v : u -> second){
                sum += v;
                set.insert(v);
            }
            map.erase(u);
        }
        auto v = std::prev(set.end());
        sum -= *v;
        set.erase(v);
        ans += sum;
    }
    printf("%lld\n", ans);
    return 0;
}