#include <bits/stdc++.h>

void solve(){
    int a, b;
    scanf("%d%d", &a, &b);
    int left = 0, right = std::min(a, b);
    while (left < right){
        int mid = (left + right + 1) / 2;
        if (a + b - 2 * mid >= mid){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }
    printf("%d\n", left);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}