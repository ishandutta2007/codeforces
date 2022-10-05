#include <bits/stdc++.h>

const int N = 100010;

char s[N], t[N];

void solve(){
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    strcpy(t, s);
    std::sort(t, t + n);
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        ans += s[i] != t[i];
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}