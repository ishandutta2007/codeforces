#include <bits/stdc++.h>

const int N = 200010;

char s[N];
int cnt[N][26];

int main(){
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++ i){
        memcpy(cnt[i], cnt[i - 1], sizeof(cnt[i]));
        ++ cnt[i][s[i] - 'a'];
    }
    int test;
    scanf("%d", &test);
    while (test --){
        int l, r;
        scanf("%d%d", &l, &r);
        if (l == r){
            puts("Yes");
            continue;
        }
        if (s[l] != s[r]){
            puts("Yes");
            continue;
        }
        int tot = 0;
        for (int i = 0; i < 26; ++ i){
            if (cnt[r][i] - cnt[l - 1][i] > 0){
                ++ tot;
            }
        }
        if (tot <= 2){
            puts("No");
            continue;
        }
        if (tot >= 3){
            puts("Yes");
            continue;
        }
    }
    return 0;
}