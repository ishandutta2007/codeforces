#include <bits/stdc++.h>

const int N = 110;

int p[N], c[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &p[i], &c[i]);
    }
    for (int i = 0; i < n; ++ i){
        if (p[i] < c[i]){
            puts("NO");
            return;
        }
    }
    for (int i = 1; i < n; ++ i){
        if (p[i] < p[i - 1] || c[i] < c[i - 1]){
            puts("NO");
            return;
        }
        if (p[i] - p[i - 1] < c[i] - c[i - 1]){
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