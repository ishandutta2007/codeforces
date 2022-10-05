#include <bits/stdc++.h>

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i){
        int mod = (n - k) / 2 + 1;
        if (i % mod == mod - 1){
            putchar('0');
        }
        else{
            putchar('1');
        }
    }
    puts("");
    return 0;
}