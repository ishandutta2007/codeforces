#include<bits/stdc++.h>

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    for (int i = 0; i <= 10000; ++ i){
        int x = c - a * i;
        if (x >= 0 && x % b == 0){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}