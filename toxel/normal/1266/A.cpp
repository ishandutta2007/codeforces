#include <bits/stdc++.h>

const int N = 110;

char s[N];

void solve(){
    scanf("%s", s);
    int n = strlen(s), sum = 0;
    for (int i = 0; i < n; ++ i){
        sum += s[i] - '0';
    }
    if (sum % 3 != 0){
        puts("cyan");
        return;
    }
    std::sort(s, s + n);
    if (s[0] != '0'){
        puts("cyan");
        return;
    }
    if (n == 1){
        puts("red");
        return;
    }
    for (int i = 1; i < n; ++ i){
        if ((s[i] - '0') % 2 == 0){
            puts("red");
            return;
        }
    }
    puts("cyan");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}