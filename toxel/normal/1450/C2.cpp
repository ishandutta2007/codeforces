#include <bits/stdc++.h>

const int N = 310;

char s[N][N], target[N][N];

void solve(){
    memset(target, 0, sizeof(target));
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s[i]);
    }
    for (int mod = 0; mod < 3; ++ mod){
        for (int type = 0; type < 2; ++ type){
            int diff = 0, cnt = 0;
            for (int i = 0; i < n; ++ i){
                for (int j = 0; j < n; ++ j){
                    if (s[i][j] == '.'){
                        target[i][j] = '.';
                        continue;
                    }
                    ++ cnt;
                    if ((i + j) % 3 == mod){
                        target[i][j] = type ? 'X' : 'O';
                    }
                    else if ((i + j) % 3 == (mod + 1) % 3){
                        target[i][j] = type ? 'O' : 'X';
                    }
                    else{
                        target[i][j] = s[i][j];
                    }
                    if (s[i][j] != target[i][j]){
                        ++ diff;
                    }
                }
            }
            if (diff <= cnt / 3){
                for (int i = 0; i < n; ++ i){
                    puts(target[i]);
                }
                return;
            }
        }
    }
    assert(false);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}