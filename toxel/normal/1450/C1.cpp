#include <bits/stdc++.h>

const int N = 310;

char s[N][N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    int cnt[3] = {};
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (s[i][j] == 'X'){
                ++ cnt[(i + j) % 3];
            }
        }
    }
    int pos = std::min_element(cnt, cnt + 3) - cnt;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            if ((i + j) % 3 == pos && s[i][j] == 'X'){
                s[i][j] = 'O';
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