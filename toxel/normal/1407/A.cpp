#include <bits/stdc++.h>

const int N = 100010;

int a[N];

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int n;
        scanf("%d", &n);
        int cnt = 0;
        for (int i = 0; i < n; ++ i){
            scanf("%d", &a[i]);
            cnt += a[i] == 0;
        }
        if (cnt >= n / 2){
            printf("%d\n", n / 2);
            for (int i = 0; i < n / 2; ++ i){
                printf("%d%c", 0, " \n"[i == n / 2 - 1]);
            }
        }
        else{
            int num = n / 2;
            if (num & 1){
                ++ num;
            }
            printf("%d\n", num);
            for (int i = 0; i < num; ++ i){
                printf("%d%c", 1, " \n"[i == num - 1]);
            }
        }
    }
    return 0;
}