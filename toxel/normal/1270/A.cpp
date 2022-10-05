#include <bits/stdc++.h>

void solve(){
    int n, t1, t2;
    scanf("%d%d%d", &n, &t1, &t2);
    bool first = false, second = false;
    for (int i = 0, x; i < t1; ++ i){
        scanf("%d", &x);
        if (x == n){
            first = true;
        }
    }
    for (int i = 0, x; i < t2; ++ i){
        scanf("%d", &x);
        if (x == n){
            second = true;
        }
    }
    puts(first ? "YES" : "NO");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}