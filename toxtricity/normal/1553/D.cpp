#include <bits/stdc++.h>

const int N = 100010;

char s[N], t[N];

void solve(){
    scanf("%s%s", s, t);
    int n = strlen(s), m = strlen(t);
    int cur = (n + m) % 2;
    for (int i = 0, j = 0; i < n; ++ i){
        if (cur == i % 2 && s[i] == t[j]){
            ++ j;
            if (j == m){
                puts("YES");
                return;
            }
            cur ^= 1;
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