#include <bits/stdc++.h>

void solve(){
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    if (x > y){
        std::swap(x, y);
    }
    int max;
    if (y == n){
        max = std::min(n, x + 1);
    }
    else{
        max = std::max(0, x + y - n) + 1;
    }
    int min;
    if (x + y > n + 1){
        min = n;
    }
    else{
        min = x + y - 2 + 1;
    }
    printf("%d %d\n", max, min);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}