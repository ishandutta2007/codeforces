#include <bits/stdc++.h>

const int N = 1010;

char s[N];
bool vis[N];

void solve(){
    memset(vis, 0, sizeof(vis));
    scanf("%s", s);
    int n = strlen(s);
    int pre = -1;
    for (int i = 0; i < n; ++ i){
        if (i == n - 1 || s[i] != s[i + 1]){
            if ((i - pre) % 2 == 1){
                vis[s[i]] = true;
            }
            pre = i;
        }
    }
    for (int i = 'a'; i <= 'z'; ++ i){
        if (vis[i]){
            putchar((char) i);
        }
    }
    puts("");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}