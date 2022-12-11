#include <bits/stdc++.h>

const int N = 100010;

int a[N];
int tmp[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        if (i % 2 == 0){
            tmp[cnt ++] = a[i];
        }
    }
    std::sort(tmp, tmp + cnt);
    cnt = 0;
    for (int i = 0; i < n; ++ i){
        if (i % 2 == 0){
            a[i] = tmp[cnt ++];
        }
    }
    cnt = 0;
    for (int i = 0; i < n; ++ i){
        if (i % 2 == 1){
            tmp[cnt ++] = a[i];
        }
    }
    std::sort(tmp, tmp + cnt);
    cnt = 0;
    for (int i = 0; i < n; ++ i){
        if (i % 2 == 1){
            a[i] = tmp[cnt ++];
        }
    }
    for (int i = 0; i < n - 1; ++ i){
        if (a[i] > a[i + 1]){
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