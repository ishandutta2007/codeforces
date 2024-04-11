#include <bits/stdc++.h>

const int N = 200010;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n - 1; ++ i){
        if (std::abs(a[i] - a[i + 1]) >= 2){
            puts("YES");
            printf("%d %d\n", i + 1, i + 2);
            return;
        }
    }
    puts("NO");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}