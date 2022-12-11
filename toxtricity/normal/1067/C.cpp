#include<bits/stdc++.h>

int main(){
    int n;
    scanf("%d", &n);
    if (n <= 10){
        for (int i = 0; i < n; ++ i){
            printf("%d %d\n", 0, i);
        }
        return 0;
    }
    for (int i = 0; i < n / 3 + (n % 3 > 1); ++ i){
        printf("0 %d\n", i << 1 | 1);
    }
    for (int i = 0; i < n / 3 + (n % 3 > 0); ++ i){
        printf("1 %d\n", i << 1);
    }
    for (int i = 0; i < n / 3 + (n % 3 > 2); ++ i){
        printf("2 %d\n", i << 1 | 1);
    }
    return 0;
}