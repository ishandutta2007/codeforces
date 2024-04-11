#include <bits/stdc++.h>

const int N = 100010;

int a[N];

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        a[i] = a[i] < k ? -1 : a[i] == k ? 0 : 1;
    }
    bool has0 = false;
    for (int i = 0; i < n; ++ i){
        if (a[i] == 0){
            has0 = true;
            break;
        }
    }
    if (!has0){
        puts("no");
        return;
    }
    if (n == 1){
        puts("yes");
        return;
    }
    if (n == 2){
        if (a[0] == -1 || a[1] == -1){
            puts("no");
            return;
        }
        puts("yes");
        return;
    }
    for (int i = 0; i < n - 2; ++ i){
        int cnt = 0;
        for (int j = 0; j < 3; ++ j){
            cnt += a[i + j] != -1;
        }
        if (cnt >= 2){
            puts("yes");
            return;
        }
    }
    puts("no");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}