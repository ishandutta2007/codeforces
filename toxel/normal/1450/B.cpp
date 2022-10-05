#include <bits/stdc++.h>

const int N = 110;
int x[N], y[N];

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &x[i], &y[i]);
    }
    for (int i = 0; i < n; ++ i){
        bool flag = true;
        for (int j = 0; j < n; ++ j){
            if (std::abs(x[i] - x[j]) + std::abs(y[i] - y[j]) > k){
                flag = false;
                break;
            }
        }
        if (flag){
            puts("1");
            return;
        }
    }
    puts("-1");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}