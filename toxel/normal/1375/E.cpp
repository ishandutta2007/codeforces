#include <bits/stdc++.h>

const int N = 1010;
using pii = std::pair <int, int>;

int a[N], p[N], inv[N];

int main(){
    int n;
    scanf("%d", &n);
    std::map <int, int> map;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        ++ map[a[i]];
    }
    std::set <pii> set;
    for (int i = 0; i < n; ++ i){
        for (int j = i + 1; j < n; ++ j){
            if (a[i] > a[j]){
                set.insert({i, j});
            }
        }
    }
    int pre = 0;
    for (auto &u : map){
        pre = u.second = pre + u.second;
    }
    for (int i = n - 1; i >= 0; -- i){
        p[i] = map[a[i]] --;
        inv[p[i]] = i;
    }
    std::vector<pii> ans;
    for (int i = 0; i < n; ++ i){
        for (int j = 1; j <= n - i - 1; ++ j){
            if (inv[j] > inv[j + 1]){
                if (set.count({inv[j + 1], inv[j]})){
                    ans.emplace_back(inv[j + 1], inv[j]);
                }
                std::swap(inv[j], inv[j + 1]);
            }
        }
    }
    int sz = ans.size();
    printf("%d\n", sz);
    for (auto u : ans){
        printf("%d %d\n", u.first + 1, u.second + 1);
    }
    return 0;
}