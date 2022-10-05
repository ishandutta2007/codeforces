#include <bits/stdc++.h>

const int N = 1010;

char s[N];

int main(){
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i <= n; ++ i){
        int cnt1 = 0, cnt2 = 0;
        for (int j = 0; j < i; ++ j){
            cnt1 += s[j] == '(';
        }
        for (int j = i; j < n; ++ j){
            cnt2 += s[j] == ')';
        }
        if (cnt1 == cnt2){
            if (cnt1 == 0){
                puts("0");
                return 0;
            }
            puts("1");
            printf("%d\n", cnt1 * 2);
            for (int j = 0; j < i; ++ j){
                if (s[j] == '('){
                    printf("%d ", j + 1);
                }
            }
            for (int j = i; j < n; ++ j){
                if (s[j] == ')'){
                    printf("%d ", j + 1);
                }
            }
            return 0;
        }
    }
    return 0;
}