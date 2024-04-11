#include <bits/stdc++.h>

int main(){
    int n;
    scanf("%d", &n);
    printf("%d\n", 3 * n + 4);
    for (int i = 0; i <= n; ++ i){
        printf("%d %d\n", 0 + i, 0 + i);
        printf("%d %d\n", 1 + i, 0 + i);
        printf("%d %d\n", 0 + i, 1 + i);
    }
    printf("%d %d\n", n + 1, n + 1);
    return 0;
}