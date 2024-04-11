#include <bits/stdc++.h>

const int BIT = 13;
using ll = long long;

ll ans[BIT];

ll ask(const std::vector <int> &vec){
    int n = vec.size();
    if (n == 0){
        return 0;
    }
    printf("? %d", n);
    for (auto u : vec){
        printf(" %d", u + 1);
    }
    puts("");
    fflush(stdout);
    ll ans;
    scanf("%lld", &ans);
    return ans;
}

int main(){
    std::vector <int> vec;
    for (int i = 0; i < 1 << 13; ++ i){
        if (__builtin_popcount(i) == BIT / 2){
            vec.emplace_back(i);
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < BIT; ++ i){
        std::vector<int> to_ask;
        for (int j = 0; j < n; ++ j){
            if (vec[j] >> i & 1){
                to_ask.emplace_back(j);
            }
        }
        ans[i] = ask(to_ask);
    }
    putchar('!');
    for (int i = 0; i < n; ++ i){
        ll ret = 0;
        for (int j = 0; j < BIT; ++ j){
            if (!(vec[i] >> j & 1)){
                ret |= ans[j];
            }
        }
        printf(" %lld", ret);
    }
    puts("");
    return 0;
}