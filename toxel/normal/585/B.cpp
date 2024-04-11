#include<bits/stdc++.h>

const int N = 3;
const int M = 1001;

char s[N][M];
bool arr[N][M];

bool isupper(char ch){
    return ch >= 'A' && ch <= 'Z';
}

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    memset(s, 0, sizeof(s));
    for (int i = 0; i < N; ++ i){
        scanf("%s", s[i]);
    }
    memset(arr, 0, sizeof(arr));
    int sit = 0;
    for (int i = 0; i < N; ++ i){
        if (s[i][0] == 's'){
            sit = i;
            break;
        }
    }
    if (isupper(s[sit][1])){
        puts("NO");
        return;
    }
    for (int i = -1; i <= 1; ++ i){
        int newsit = sit + i;
        if (newsit >= 0 && newsit <= 2 && !isupper(s[newsit][1])){
            arr[newsit][1] = true;
        }
    }
    for (int i = 1; i < M - 1; i += N){
        for (int j = 0; j < N; ++ j){
            if (!arr[j][i]) continue;
            bool flag = true;
            for (int k = 1; k <= N; ++ k){
                if (isupper(s[j][i + k])){
                    flag = false;
                    break;
                }
            }
            if (!flag) continue;
            for (int k = -1; k <= 1; ++ k){
                int newsit = j + k;
                if (newsit < 0 || newsit >= 3) continue;
                if (!isupper(s[newsit][i + N])){
                    arr[newsit][i + N] = true;
                }
            }
        }
    }
    if (arr[0][M - 1] || arr[1][M - 1] || arr[2][M - 1]){
        puts("YES");
    }
    else{
        puts("NO");
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