#include <bits/stdc++.h>

int main(){
    int b, g, n;
    scanf("%d%d%d", &b, &g, &n);
    int cnt = 0;
    for (int i = 0; i <= b; ++ i){
        for (int j = 0; j <= g; ++ j){
            cnt += i + j == n;
        }
    }
    printf("%d\n", cnt);
    return 0;
}