#include<bits/stdc++.h>

int main(){
    int a;
    scanf("%d", &a);
    if (a == 1){
        puts("1 1\n1");
        return 0;
    }
    printf("%d %d\n", (a - 1) * 2, 2);
    puts("1 2");
    return 0;
}