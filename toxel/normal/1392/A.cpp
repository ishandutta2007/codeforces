#include <bits/stdc++.h>

const int N = 200010;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    bool flag = false;
    for (int i = 0; i < n; ++ i){
        if (a[i] != a[0]){
            flag = true;
            break;
        }
    }
    if (flag){
        puts("1");
    }
    else{
        printf("%d\n", n);
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