#include <bits/stdc++.h>

const int N = 300010;

char s[N];

void solve(){
    int n;
    scanf("%d%s", &n, s);
    bool fl1 = true, fl2 = true;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '<'){
            fl1 = false;
        }
        if (s[i] == '>'){
            fl2 = false;
        }
    }
    if (fl1 || fl2){
        printf("%d\n", n);
        return;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        cnt += s[i] == '-' || s[(i + 1) % n] == '-';
    }
    printf("%d\n", cnt);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}