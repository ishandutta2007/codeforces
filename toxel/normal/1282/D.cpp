#include <bits/stdc++.h>

const int N = 310;

char s[N], ans[N];

int ask(){
    puts(s);
    fflush(stdout);
    int n;
    scanf("%d", &n);
    return n;
}

int main(){
    for (int i = 0; i < 300; ++ i){
        s[i] = 'a';
    }
    int num_a = 300 - ask();
    for (int i = 0; i < 300; ++ i){
        s[i] = 'b';
    }
    int num_b = 300 - ask();
    int n = num_a + num_b;
    for (int i = 0; i < n - 1; ++ i){
        for (int j = 0; j < n; ++ j){
            s[j] = 'a';
        }
        s[n] = '\0';
        s[i] = 'b';
        int ret = ask();
        if (ret == num_b - 1){
            ans[i] = 'b';
        }
        else{
            ans[i] = 'a';
        }
    }
    for (int i = 0; i < n - 1; ++ i){
        -- (ans[i] == 'a' ? num_a : num_b);
    }
    ans[n - 1] = num_a ? 'a' : 'b';
    puts(ans);
    return 0;
}