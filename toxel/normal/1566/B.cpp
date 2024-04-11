#include <bits/stdc++.h>

const int N = 100010;

char s[N];

void solve(){
    scanf("%s", s);
    int n = strlen(s);
    bool flag = true;
    for (int i = 0; i < n; ++ i){
        if (s[i] != '1'){
            flag = false;
            break;
        }
    }
    if (flag){
        puts("0");
        return;
    }
    int first0 = -1, last0 = -1;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '0'){
            first0 = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; -- i){
        if (s[i] == '0'){
            last0 = i;
            break;
        }
    }
    for (int i = first0; i <= last0; ++ i){
        if (s[i] == '1'){
            puts("2");
            return;
        }
    }
    puts("1");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}