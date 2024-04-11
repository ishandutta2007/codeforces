#include <bits/stdc++.h>

const int N = 100010;

int r[N][5];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j < 5; ++ j){
            scanf("%d", &r[i][j]);
        }
    }
    int pos = 0;
    for (int i = 1; i <= n; ++ i){
        int cnt = 0;
        for (int j = 0; j < 5; ++ j){
            cnt += r[i][j] < r[pos][j];
        }
        if (cnt >= 3 || pos == 0){
            pos = i;
        }
    }
    for (int i = 1; i <= n; ++ i){
        if (i == pos){
            continue;
        }
        int cnt = 0;
        for (int j = 0; j < 5; ++ j){
            cnt += r[pos][j] < r[i][j];
        }
        if (cnt < 3){
            puts("-1");
            return;
        }
    }
    printf("%d\n", pos);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}