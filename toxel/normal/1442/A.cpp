#include <bits/stdc++.h>

const int N = 100010;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    int cur = 0;
    for (int i = n - 2; i >= 0; -- i){
        if (a[i] > a[i + 1]){
            cur += a[i] - a[i + 1];
        }
        if (a[i] < cur){
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
}