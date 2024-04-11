#include <bits/stdc++.h>

const int N = 110;

int a[N];

bool prime(int n){
    for (int i = 2; i * i <= n; ++ i){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

void solve(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    std::vector <int> result;
    if (!prime(sum)){
        for (int i = 0; i < n; ++ i){
            result.emplace_back(i);
        }
    }
    else{
        for (int i = 0; i < n; ++ i){
            if (!prime(sum - a[i])){
                for (int j = 0; j < n; ++ j){
                    if (i == j){
                        continue;
                    }
                    result.emplace_back(j);
                }
                break;
            }
        }
    }
    int sz = result.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; ++ i){
        printf("%d%c", result[i] + 1, " \n"[i == sz - 1]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}