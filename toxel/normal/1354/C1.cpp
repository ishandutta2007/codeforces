#include <bits/stdc++.h>

const double PI = std::acos(-1.0);

void solve(){
    int n;
    scanf("%d", &n);
    if (n % 2 == 0){
        double angle = 2 * PI / (2 * n) / 2;
        double ans = 1 / std::tan(angle);
        printf("%.15f\n", ans);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}