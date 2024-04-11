#include <bits/stdc++.h>

void solve(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if (m <= n / k){
        printf("%d\n", m);
        return;
    }
    int x = n / k;
    int y = (m - x + k - 2) / (k - 1);
    printf("%d\n", x - y);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}