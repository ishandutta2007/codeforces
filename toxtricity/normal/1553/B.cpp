#include <bits/stdc++.h>

const int N = 1010;

char s[N], t[N];

void solve(){
    scanf("%s%s", s, t);
    int n = strlen(s), m = strlen(t);
    for (int i = 0; i < n; ++ i){
        for (int j = i; j < n; ++ j){
            for (int k = 0; k <= j; ++ k){
                if (j - i + j - k + 1 != m){
                    continue;
                }
                bool flag = true;
                for (int u = i; u <= j; ++ u){
                    if (s[u] != t[u - i]){
                        flag = false;
                        break;
                    }
                }
                for (int u = j - 1; u >= k; -- u){
                    if (s[u] != t[(j - 1) - u + (j - i + 1)]){
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    puts("YES");
                    return;
                }
            }
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