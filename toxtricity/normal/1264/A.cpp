#include <bits/stdc++.h>

const int N = 400010;

int p[N];

void solve(){
    int n;
    scanf("%d", &n);
    int g = 0, s = 0, b = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &p[i]);
    }
    int i = 0;
    while (i < n - 1 && p[i] == p[i + 1]) {
        ++i;
    }
    int j = i + 1;
    while (j < n - 1 && (p[j] == p[j + 1] || j - i <= i + 1)){
        ++ j;
    }
    int k = j + 1;
    while (k < n){
        while (k < n - 1 && (p[k] == p[k + 1] || k - j <= i + 1)){
            ++ k;
        }
        if (k + 1 <= n / 2){
            g = i + 1, s = j - i, b = k - j;
        }
        ++ k;
    }
    printf("%d %d %d\n", g, s, b);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}