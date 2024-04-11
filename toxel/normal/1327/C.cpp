#include <bits/stdc++.h>

int main(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++ i){
        int x, y;
        scanf("%d%d", &x, &y);
    }
    for (int i = 0; i < k; ++ i){
        int x, y;
        scanf("%d%d", &x, &y);
    }
    printf("%d\n", n * m + n + m - 3);
    for (int i = 0; i < n - 1; ++ i){
        putchar('U');
    }
    for (int i = 0; i < m - 1; ++ i){
        putchar('L');
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m - 1; ++ j){
            putchar(i & 1 ? 'L' : 'R');
        }
        if (i < n - 1){
            putchar('D');
        }
    }
    puts("");
    return 0;
}