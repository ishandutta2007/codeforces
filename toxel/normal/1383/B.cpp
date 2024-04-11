#include <bits/stdc++.h>

const int N = 100010;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        sum ^= a[i];
    }
    if (sum == 0){
        puts("DRAW");
        return;
    }
    for (int i = 30; i >= 0; -- i){
        if (sum >> i & 1){
            int cnt = 0;
            for (int j = 0; j < n; ++ j){
                if (a[j] >> i & 1){
                    ++ cnt;
                }
            }
            if (cnt % 8 == 1){
                puts("WIN");
                return;
            }
            if (cnt % 8 == 7){
                puts(n & 1 ? "LOSE" : "WIN");
                return;
            }
            if (cnt % 8 == 3){
                puts(n & 1 ? "LOSE" : "WIN");
                return;
            }
            if (cnt % 8 == 5){
                puts("WIN");
                return;
            }
        }
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