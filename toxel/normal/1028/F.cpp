#include<bits/stdc++.h>

typedef long long ll;
typedef std::pair <int, int> pii;
inline ll sqr(int x){return 1ll * x * x;}

pii gcd(pii x, pii y){
    int u = x.first + y.first, v = x.second + y.second;
    int ggcd = std::__gcd(u, v);
    return {u / ggcd, v / ggcd};
}

int main(){
    int test;
    scanf("%d", &test);
    std::map <ll, std::set <pii>> map;
    std::map <pii, int> Hash;
    std::map <pii, int> Hash2;
    int cnt = 0;
    while (test --){
        int type;
        scanf("%d", &type);
        if (type == 1){
            int x, y;
            scanf("%d%d", &x, &y);
            ll dis = sqr(x) + sqr(y);
            auto &set = map[dis];
            for (auto u : set){
                ++ Hash[gcd(u, {x, y})];
            }
            set.insert({x, y});
            ++ Hash2[gcd({x, y}, {x, y})];
            ++ cnt;
        }
        else if (type == 2){
            int x, y;
            scanf("%d%d", &x, &y);
            ll dis = sqr(x) + sqr(y);
            auto &set = map[dis];
            set.erase({x, y});
            for (auto u : set){
                -- Hash[gcd(u, {x, y})];
            }
            -- Hash2[gcd({x, y}, {x, y})];
            -- cnt;
        }
        else if (type == 3){
            int x, y;
            scanf("%d%d", &x, &y);
            int gcd = std::__gcd(x, y);
            x /= gcd, y /= gcd;
            printf("%d\n", cnt - 2 * Hash[{x, y}] - Hash2[{x, y}]);
        }
    }
    return 0;
}