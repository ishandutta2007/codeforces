#include <bits/stdc++.h>

const int N = 200010;

char s[N];
int ans[N];

void solve(){
    int n;
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++ i){
        ans[i] = n - i;
    }
    for (int i = 0, j = 0; i < n - 1; i = j){
        while (s[j] == s[i]){
            ++ j;
        }
        if (s[i] == '<'){
            std::reverse(ans + i, ans + j + 1);
        }
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    }
    memset(ans, 0, sizeof(int) * n);
    int cur = 0;
    for (int i = 0, j = 0; i < n - 1; i = j){
        while (s[j] == s[i]){
            ++ j;
        }
        if (s[i] == '<'){
            for (int k = i; k < j; ++ k){
                ans[k] = ++ cur;
            }
        }
    }
    cur = n;
    for (int i = 0; i < n; ++ i){
        if (!ans[i]){
            ans[i] = cur --;
        }
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n - 1]);
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