#include <bits/stdc++.h>

const int N = 110;

char s[N][N];
char name[N];
int num[N];

void solve(){
    int r, c, k;
    scanf("%d%d%d", &r, &c, &k);
    for (int i = 0; i < r; ++ i){
        scanf("%s", s[i]);
    }
    int cnt = 0;
    for (int i = 0; i < r; ++ i){
        for (int j = 0; j < c; ++ j){
            cnt += s[i][j] == 'R';
        }
    }
    for (int i = 0; i < k; ++ i){
        num[i] = cnt / k + (i < cnt % k);
    }
    int now = 0, id = 0;
    for (int i = 0; i < r; ++ i){
        if (i % 2 == 0){
            for (int j = 0; j < c; ++ j){
                char tmp = s[i][j];
                s[i][j] = name[id];
                if (tmp == 'R'){
                    ++ now;
                    if (now == num[id] && id < k - 1){
                        now = 0;
                        ++ id;
                    }
                }
            }
        }
        else{
            for (int j = c - 1; j >= 0; -- j){
                char tmp = s[i][j];
                s[i][j] = name[id];
                if (tmp == 'R'){
                    ++ now;
                    if (now == num[id] && id < k - 1){
                        now = 0;
                        ++ id;
                    }
                }
            }
        }
    }
    for (int i = 0; i < r; ++ i){
        puts(s[i]);
    }
}

int main(){
    for (int i = 0; i < 26; ++ i){
        name[i] = i + 'a';
        name[i + 26] = i + 'A';
    }
    for (int i = 0; i < 10; ++ i){
        name[i + 52] = i + '0';
    }
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}