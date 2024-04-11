#include <bits/stdc++.h>

const int N = 1000010;

char s[N];
int x[N];

void solve(){
    scanf("%s", s);
    int n = strlen(s);
    int cur = 0, now = 0;
    long long ans = n;
    for (int i = 0; i < n; ++ i){
        cur += s[i] == '+' ? 1 : -1;
        x[i] = cur;
        if (cur < now){
            ans += 1ll * (i + 1) * (now - cur);
            now = cur;
        }
    }
    printf("%lld\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}