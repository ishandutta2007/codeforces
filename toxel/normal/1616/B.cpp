#include <bits/stdc++.h>

const int N = 100010;

char s[N];

void solve(){
    int n;
    scanf("%d%s", &n, s);
    int cur = 0;
    bool has_small = false;
    for (int i = 1; i < n; ++ i){
        if (s[i] < s[i - 1]){
            cur = i;
            has_small = true;
        }
        else if (s[i] == s[i - 1]){
            if (!has_small){
                break;
            }
            cur = i;
        }
        else{
            break;
        }
    }
    for (int i = 0; i <= cur; ++ i){
        putchar(s[i]);
    }
    for (int i = cur; i >= 0; -- i){
        putchar(s[i]);
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