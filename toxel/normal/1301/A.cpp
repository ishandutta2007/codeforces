#include <bits/stdc++.h>

const int N = 110;

char a[N], b[N], c[N];

void solve(){
    scanf("%s%s%s", a, b, c);
    int n = strlen(a);
    for (int i = 0; i < n; ++ i){
        if (a[i] != c[i] && b[i] != c[i]){
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}