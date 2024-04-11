#include <bits/stdc++.h>

const int N = 100010;

char s[N];

int main(){
    int n;
    scanf("%d%s", &n, s);
    for (auto u : s){
        if (u == 'n'){
            printf("1 ");
        }
    }
    for (auto u : s){
        if (u == 'z'){
            printf("0 ");
        }
    }
    puts("");
    return 0;
}