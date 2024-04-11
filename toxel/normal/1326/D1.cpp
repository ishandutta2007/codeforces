#include <bits/stdc++.h>

const int N = 3000010;

char s[N], t[N], tmp[N];
int p[N];

void solve(){
    scanf("%s", s);
    int n = strlen(s);
    int max1 = 0;
    for (int i = 0, j = n - 1; i <= j; ++ i, -- j){
        if (s[i] == s[j]){
            ++ max1;
        }
        else{
            break;
        }
    }
    if (max1 >= n / 2){
        puts(s);
        return;
    }
    int cnt1 = 0;
    for (int i = max1; i < n - max1; ++ i){
        tmp[cnt1 ++] = s[i];
    }
    tmp[cnt1] = '\0';
    t[0] = '$';
    t[1] = '#';
    int cnt = 2;
    for (int i = 0; i < cnt1; ++ i){
        t[cnt ++] = tmp[i];
        t[cnt ++] = '#';
    }
    t[cnt] = '\0';
    int id, max2 = 0;
    int ans = 0;
    for (int i = 1; i < cnt; ++ i) {
        if (i < max2) {
            p[i] = std::min(p[2 * id - i], max2 - i);
        }
        else{
            p[i] = 1;
        }
        while (t[i - p[i]] == t[i + p[i]]){
            ++ p[i];
        }
        if (max2 < i + p[i]){
            id = i;
            max2 = i + p[i];
        }
        if (p[i] == i || p[i] + i == cnt){
            ans = std::max(ans, p[i]);
        }
    }
    for (int i = 0; i < max1; ++ i){
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
    for (int i = n - max1; i < n; ++ i){
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