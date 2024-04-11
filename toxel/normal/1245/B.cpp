#include <bits/stdc++.h>

const int N = 110;

char s[N];
char ans[N];
bool vis[N];

void solve(){
    int n, a, b, c;
    scanf("%d%d%d%d", &n, &a, &b, &c);
    scanf("%s", s);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; ++ i){
        if (s[i] == 'P'){
            if (c > 0){
                ans[i] = 'S';
                -- c;
                vis[i] = true;
            }
        }
        else if (s[i] == 'R'){
            if (b > 0){
                ans[i] = 'P';
                -- b;
                vis[i] = true;
            }
        }
        else{
            if (a > 0){
                ans[i] = 'R';
                -- a;
                vis[i] = true;
            }
        }
    }
    if (n - a - b - c < (n + 1) / 2){
        puts("NO");
        return;
    }
    for (int i = 0; i < n; ++ i){
        if (!vis[i]){
            if (a > 0){
                ans[i] = 'R';
                -- a;
            }
            else if (b > 0){
                ans[i] = 'P';
                -- b;
            }
            else{
                ans[i] = 'S';
                -- c;
            }
        }
    }
    puts("YES");
    ans[n] = '\0';
    puts(ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}