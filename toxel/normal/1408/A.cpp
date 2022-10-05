#include<bits/stdc++.h>

const int N = 110;

int a[N], b[N], c[N];
int ans[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &c[i]);
    }
    ans[0] = a[0];
    for (int i = 1; i < n - 1; ++ i){
        if (a[i] != ans[i - 1]){
            ans[i] = a[i];
        }
        else{
            ans[i] = b[i];
        }
    }
    if (a[n - 1] != ans[n - 2] && a[n - 1] != ans[0]){
        ans[n - 1] = a[n - 1];
    }
    else if (b[n - 1] != ans[n - 2] && b[n - 1] != ans[0]){
        ans[n - 1] = b[n - 1];
    }
    else{
        ans[n - 1] = c[n - 1];
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n - 1]);
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