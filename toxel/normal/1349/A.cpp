#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    std::map <int, std::vector <int>> map;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        int x = a[i];
        for (int j = 2; j * j <= x; ++ j){
            if (x % j == 0){
                int cnt = 0;
                while (x % j == 0){
                    x /= j;
                    ++ cnt;
                }
                map[j].emplace_back(cnt);
            }
        }
        if (x > 1){
            map[x].emplace_back(1);
        }
    }
    ll ans = 1;
    for (const auto &p : map){
        if (int(p.second.size()) <= n - 2){
            continue;
        }
        else if (int(p.second.size()) == n - 1){
            std::vector<int> vec = p.second;
            std::sort(vec.begin(), vec.end());
            for (int i = 0; i < vec[0]; ++ i){
                ans *= p.first;
            }
        }
        else{
            std::vector<int> vec = p.second;
            std::sort(vec.begin(), vec.end());
            for (int i = 0; i < vec[1]; ++ i){
                ans *= p.first;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}