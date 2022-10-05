#include <bits/stdc++.h>

const int N = 60;

char s[N][N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    int cnt0 = 0;
    for (int i = 0; i < n; ++ i){
        int len = strlen(s[i]);
        if (len % 2 == 1){
            printf("%d\n", n);
            return;
        }
        for (int j = 0; j < len; ++ j){
            cnt0 += s[i][j] == '0';
        }
    }
    printf("%d\n", n - cnt0 % 2);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}