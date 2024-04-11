#include <bits/stdc++.h>

int main(){
    int n, s;
    scanf("%d%d", &n, &s);
    if (n * 2 > s){
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i = 0; i < n - 1; ++ i){
        printf("%d ", 2);
    }
    printf("%d\n", s - 2 * (n - 1));
    puts("1");
    return 0;
}