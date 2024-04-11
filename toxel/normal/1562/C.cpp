#include <bits/stdc++.h>

const int N = 100010;

char s[N];

void solve(){
    int n;
    scanf("%d%s", &n, s);
    int zero = -1;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '0'){
            zero = i + 1;
            break;
        }
    }
    if (zero == -1){
        printf("1 %d 2 %d\n", n - 1, n);
        return;
    }
    if (zero <= (n + 1) / 2){
        printf("%d %d %d %d\n", zero, n, zero + 1, n);
        return;
    }
    printf("1 %d 1 %d\n", zero, zero - 1);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}