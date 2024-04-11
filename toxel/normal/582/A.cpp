#include<bits/stdc++.h>

int main(){
    int n;
    scanf("%d", &n);
    std::vector <int> ans;
    std::multiset <int> set;
    for (int i = 0, x; i < n * n; ++ i){
        scanf("%d", &x);
        set.insert(x);
    }
    for (int i = 0; i < n; ++ i){
        int x = *(-- set.end());
        for (auto u : ans){
            int gcd = std::__gcd(u, x);
            auto v = set.lower_bound(gcd);
            set.erase(v);
            v = set.lower_bound(gcd);
            set.erase(v);
        }
        auto v = set.lower_bound(x);
        set.erase(v);
        ans.push_back(x);
    }
    for (auto u : ans){
        printf("%d ", u);
    }
    puts("");
    return 0;
}