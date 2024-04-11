#include <bits/stdc++.h>

const int N = 100;

char s[N][N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    bool valid = true;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            char real = (i + j) % 2 ? 'R' : 'W';
            if (s[i][j] != '.' && real != s[i][j]){
                valid = false;
                break;
            }
        }
    }
    if (valid){
        puts("YES");
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                char real = (i + j) % 2 ? 'R' : 'W';
                putchar(real);
            }
            puts("");
        }
        return;
    }
    valid = true;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            char real = (i + j) % 2 ? 'W' : 'R';
            if (s[i][j] != '.' && real != s[i][j]){
                valid = false;
                break;
            }
        }
    }
    if (valid){
        puts("YES");
        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < m; ++ j){
                char real = (i + j) % 2 ? 'W' : 'R';
                putchar(real);
            }
            puts("");
        }
        return;
    }
    puts("NO");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}