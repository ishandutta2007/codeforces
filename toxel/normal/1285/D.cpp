#include <bits/stdc++.h>

const int N = 100010;

int a[N];

int solve(std::vector <int> vec, int bit){
    if (bit == 0){
        bool has0 = false, has1 = false;
        for (auto u : vec){
            if (u == 0){
                has0 = true;
            }
            else{
                has1 = true;
            }
        }
        if (has0 && has1){
            return 1;
        }
        return 0;
    }
    std::vector <int> nvec[2];
    for (auto u : vec){
        int x = u >> bit & 1;
        nvec[x].emplace_back(u ^ x << bit);
    }
    if (!nvec[0].empty() && !nvec[1].empty()){
        return 1 << bit ^ std::min(solve(nvec[0], bit - 1), solve(nvec[1], bit - 1));
    }
    if (!nvec[0].empty()){
        return solve(nvec[0], bit - 1);
    }
    if (!nvec[1].empty()){
        return solve(nvec[1], bit - 1);
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    std::vector <int> vec;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        vec.emplace_back(a[i]);
    }
    printf("%d\n", solve(vec, 29));
}