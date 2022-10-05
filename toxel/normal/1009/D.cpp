#include<bits/stdc++.h>

typedef std::pair <int, int> pii;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    if (n - 1 > m){
        puts("Impossible");
        return 0;
    }
    std::vector <pii> vec;
    for (int i = 1; i <= n; ++ i){
        for (int j = i + 1; j <= n; ++ j){
            if (std::__gcd(i, j) != 1){
                continue;
            }
            vec.push_back({i, j});
            if (vec.size() == m){
                break;
            }
        }
        if (vec.size() == m){
            break;
        }
    }
    if (vec.size() < m){
        puts("Impossible");
        return 0;
    }
    puts("Possible");
    for (auto u : vec){
        printf("%d %d\n", u.first, u.second);
    }
    return 0;
}