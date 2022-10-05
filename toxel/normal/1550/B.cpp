#include <bits/stdc++.h>

const int N = 100010;

char s[N];

void solve(){
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    scanf("%s", s);
    if (b >= 0){
        printf("%d\n", n * (a + b));
    }
    else{
        int cnt = 1;
        for (int i = 0; i < n - 1; ++ i){
            cnt += s[i] != s[i + 1];
        }
        printf("%d\n", a * n + (cnt + 2) / 2 * b);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}