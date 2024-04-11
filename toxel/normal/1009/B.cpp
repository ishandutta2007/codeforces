#include<bits/stdc++.h>

const int N = 100010;

char s[N], ans[N];

int main(){
    scanf("%s", s);
    int n = strlen(s);
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '0' || s[i] == '2'){
            ans[cnt ++] = s[i];
        }
    }
    bool flag = false;
    for (int i = 0; i < cnt; ++ i){
        if (!flag && ans[i] == '2'){
            for (int i = 0; i < n - cnt; ++ i){
                putchar('1');
            }
            flag = true;
        }
        putchar(ans[i]);
    }

    if (!flag){
        for (int i = 0; i < n - cnt; ++ i){
            putchar('1');
        }
    }
    putchar('\n');
    return 0;
}