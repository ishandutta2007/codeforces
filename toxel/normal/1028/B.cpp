#include<bits/stdc++.h>

int main(){
    const int N = 1500;
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < N; ++ i){
        putchar('1');
    }
    puts("");
    for (int i = 0; i < N - 1; ++ i){
        putchar('8');
    }
    putchar('9');
    puts("");
    return 0;
}