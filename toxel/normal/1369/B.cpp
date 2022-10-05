#include <bits/stdc++.h>

const int N = 100010;

char s[N];

void solve(){
    int n;
    scanf("%d%s", &n, &s);
    int begin = -1, end = -1;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '1'){
            begin = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; -- i){
        if (s[i] == '0'){
            end = i;
            break;
        }
    }
    if (begin == -1 || end == -1 || begin == end + 1){
        puts(s);
        return;
    }
    for (int i = 0; i < begin; ++ i){
        putchar('0');
    }
    putchar('0');
    for (int i = end + 1; i < n; ++ i){
        putchar('1');
    }
    puts("");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}