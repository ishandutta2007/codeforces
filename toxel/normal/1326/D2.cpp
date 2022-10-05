#include <bits/stdc++.h>

const int N = 2000010;

char s[N], t[N], tmp[N];
int p[N];

void solve(){
    scanf("%s", s);
    int n = strlen(s);
    int max = 0;
    for (int i = 0, j = n - 1; i <= j; ++ i, -- j){
        if (s[i] == s[j]){
            ++ max;
        }
        else{
            break;
        }
    }
    if (max >= n / 2){
        puts(s);
        return;
    }
    t[0] = '$', t[1] = '#';
    int cnt = 2;
    for (int i = max; i < n - max; ++ i){
        t[cnt ++] = s[i];
        t[cnt ++] = '#';
    }
    t[cnt] = '\0';
    int ans = 0;
    for (int i = 1, l = 0, r = -1; i < cnt; ++ i){
        int k = i > r ? 1 : std::min(p[l + r - i], r - i + 1);
        while (t[i + k] == t[i - k]){
            ++ k;
        }
        p[i] = k --;
        if (i + k > r){
            l = i - k, r = i + k;
        }
        if (p[i] == i || p[i] + i == cnt){
            ans = std::max(ans, p[i]);
        }
    }
    for (int i = 0; i < max; ++ i){
        putchar(s[i]);
    }
    for (int i = 1; i < cnt; ++ i){
        if (p[i] == i || p[i] + i == cnt){
            if (p[i] == ans){
                for (int j = i - p[i] + 1; j <= i + p[i] - 1; ++ j){
                    if (t[j] != '#'){
                        putchar(t[j]);
                    }
                }
                break;
            }
        }
    }
    for (int i = n - max; i < n; ++ i){
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