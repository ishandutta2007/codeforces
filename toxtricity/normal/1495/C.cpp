#include <bits/stdc++.h>

const int N = 510;

char s[N][N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    for (int i = n % 3 == 1 ? 0 : 1; i < n; i += 3){
        for (int j = 0; j < m; ++ j){
            s[i][j] = 'X';
        }
    }
    for (int i = n % 3 == 1 ? 0 : 1; i < n; i += 3){
        if (i + 3 < n){
            bool flag = false;
            for (int j = 0; j < m; ++ j){
                if (s[i + 1][j] == 'X' || s[i + 2][j] == 'X'){
                    s[i + 1][j] = s[i + 2][j] = 'X';
                    flag = true;
                    break;
                }
            }
            if (!flag){
                s[i + 1][0] = s[i + 2][0] = 'X';
            }
        }
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