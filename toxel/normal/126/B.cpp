#include <bits/stdc++.h>

const int N = 1000010;

char s[N];
int zs[N], fail[N];

void ex_kmp(char *s, int *zs){
    int n = strlen(s);
    for (int i = 1, l = 0, r = 0; i < n; ++ i){
        if (i <= r) zs[i] = std::min(zs[i - l], r - i + 1);
        while (i + zs[i] < n && s[i + zs[i]] == s[zs[i]]) ++ zs[i];
        if (i + zs[i] - 1 > r) l = i, r = i + zs[i] - 1;
    }
}

int main(){
    scanf("%s", s);
    int n = strlen(s);
    fail[0] = -1;
    for (int i = 0, j = -1; i < n; ++ i){
        while (j >= 0 && s[i] != s[j]) j = fail[j];
        fail[i + 1] = ++ j;
    }
    ex_kmp(s, zs);
    int max = 0;
    for (int i = 1; i < n - 1; ++ i){
        max = std::max(max, std::min(zs[i], n - i - 1));
    }
    int now = fail[n];
    while (now > max){
        now = fail[now];
    }
    if (now <= 0){
        puts("Just a legend");
        return 0;
    }
    for (int i = 0; i < now; ++ i){
        putchar(s[i]);
    }
    puts("");
    return 0;
}