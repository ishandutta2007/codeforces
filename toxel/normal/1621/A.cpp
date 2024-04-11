#include <bits/stdc++.h>

const int N = 50;

char s[N][N];

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    if (k > (n + 1) / 2){
        puts("-1");
        return;
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            s[i][j] = '.';
        }
        s[i][n] = '\0';
    }
    for (int i = 0; i < k; ++ i){
        s[2 * i][2 * i] = 'R';
    }
    for (int i = 0; i < n; ++ i){
        puts(s[i]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}