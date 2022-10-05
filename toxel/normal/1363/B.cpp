#include <bits/stdc++.h>

const int N = 1010;

char s[N];

void solve(){
    scanf("%s", s);
    int n = strlen(s);
    int ans = INT_MAX;
    for (int i = 0; i <= n; ++ i){
        int cnt = 0;
        for (int j = 0; j < i; ++ j){
            if (s[j] != '0'){
                ++ cnt;
            }
        }
        for (int j = i; j < n; ++ j){
            if (s[j] != '1'){
                ++ cnt;
            }
        }
        ans = std::min(ans, cnt);
    }
    for (int i = 0; i <= n; ++ i){
        int cnt = 0;
        for (int j = 0; j < i; ++ j){
            if (s[j] != '1'){
                ++ cnt;
            }
        }
        for (int j = i; j < n; ++ j){
            if (s[j] != '0'){
                ++ cnt;
            }
        }
        ans = std::min(ans, cnt);
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}