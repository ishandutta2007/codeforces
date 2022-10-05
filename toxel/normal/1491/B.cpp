#include <bits/stdc++.h>

const int N = 110;

int a[N];

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int n, u, v;
        scanf("%d%d%d", &n, &u, &v);
        for (int i = 0; i < n; ++ i){
            scanf("%d", &a[i]);
        }
        bool flag = false;
        for (int i = 0; i < n - 1; ++ i){
            if (std::abs(a[i] - a[i + 1]) >= 2){
                flag = true;
                break;
            }
        }
        if (flag){
            puts("0");
            continue;
        }
        flag = false;
        for (int i = 1; i < n; ++ i){
            if (a[0] != a[i]){
                flag = true;
                break;
            }
        }
        if (flag){
            printf("%d\n", std::min(u, v));
        }
        else{
            printf("%d\n", v + std::min(u, v));
        }
    }
    return 0;
}