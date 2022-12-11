#include<bits/stdc++.h>

const int N = 200010;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    int minus = 0, zero = 0;
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        minus += a[i] < 0;
        zero += a[i] == 0;
    }
    if (zero >= 1){
        int sit = 0;
        if (minus & 1){
            for (int i = 1; i <= n; ++ i){
                if (a[i] >= 0) continue;
                if (!sit || a[sit] < a[i]){
                    sit = i;
                }
            }
        }
        int pre = 0, cnt = 0;
        for (int i = 1; i <= n; ++ i){
            if (a[i] && i != sit) continue;
            if (pre){
                printf("1 %d %d\n", pre, i);
                ++ cnt;
            }
            pre = i;
        }
        if (cnt < n - 1){
            printf("2 %d\n", pre);
        }
        pre = 0;
        for (int i = 1; i <= n; ++ i){
            if (!a[i] || i == sit) continue;
            if (pre){
                printf("1 %d %d\n", pre, i);
            }
            pre = i;
        }
        return 0;
    }
    if (minus & 1){
        int sit = 0;
        for (int i = 1; i <= n; ++ i){
            if (a[i] > 0) continue;
            if (!sit || a[sit] < a[i]){
                sit = i;
            }
        }
        printf("2 %d\n", sit);
        int pre = 0;
        for (int i = 1; i <= n; ++ i){
            if (i == sit) continue;
            if (pre){
                printf("1 %d %d\n", pre, i);
            }
            pre = i;
        }
        return 0;
    }
    for (int i = 1; i < n; ++ i){
        printf("1 %d %d\n", i, i + 1);
    }
    return 0;
}