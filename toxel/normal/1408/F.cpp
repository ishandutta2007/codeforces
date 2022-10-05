#include <bits/stdc++.h>

using pii = std::pair <int, int>;

int main(){
    int n;
    scanf("%d", &n);
    int len = 1;
    while (len <= n){
        len <<= 1;
    }
    len >>= 1;
    std::vector<pii> ans;
    for (int i = 1; i < len; i <<= 1){
        for (int j = 1; j <= len; j += i << 1){
            for (int k = 0; k < i; ++ k){
                ans.emplace_back(j + k, j + k + i);
            }
        }
    }
    int diff = n - len + 1 - 1;
    for (int i = 1; i < len; i <<= 1){
        for (int j = 1; j <= len; j += i << 1){
            for (int k = 0; k < i; ++ k){
                ans.emplace_back(j + k + diff, j + k + i + diff);
            }
        }
    }
    printf("%d\n", int(ans.size()));
    for (auto u : ans){
        printf("%d %d\n", u.first, u.second);
    }
    return 0;
}