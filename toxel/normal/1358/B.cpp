#include <bits/stdc++.h>

const int N = 100010;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    for (int i = n - 1; i >= 0; -- i){
        if (i + 1 >= a[i]){
            printf("%d\n", i + 2);
            return;
        }
    }
    puts("1");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}