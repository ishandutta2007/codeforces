#include <bits/stdc++.h>

const int N = 110;

char s[N];

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        for (int i = 0; i < 2 * n; i += 2){
            putchar(s[i]);
        }
        puts("");
    }
    return 0;
}