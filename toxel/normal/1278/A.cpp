#include <bits/stdc++.h>

const int N = 210;

int cnt[N];
char s[N], t[N];

void solve(){
    scanf("%s", s);
    scanf("%s", &t);
    int n = strlen(s), m = strlen(t);
    if (n > m){
        puts("NO");
        return;
    }
    for (int i = 0; i <= m - n; ++ i){
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < n; ++ j){
            ++ cnt[s[j]];
            -- cnt[t[i + j]];
        }
        bool flag = true;
        for (int j = 0; j < N; ++ j){
            if (cnt[j]){
                flag = false;
                break;
            }
        }
        if (flag){
            puts("YES");
            return;
        }
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