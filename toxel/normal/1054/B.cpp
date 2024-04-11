#include<bits/stdc++.h>

int main(){
    int max = -1;
    int n;
    scanf("%d", &n);
    for (int i = 1, x; i <= n; ++ i){
        scanf("%d", &x);
        if (x > max + 1){
            printf("%d\n", i);
            return 0;
        }
        max = std::max(max, x);
    }
    puts("-1");
    return 0;
}