#include <bits/stdc++.h>

const int N = 110;

int a[N];

void solve(){
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        sum += a[i];
        if (sum == x){
            if (i == n - 1){
                puts("NO");
                return;
            }
            std::swap(a[i], a[i + 1]);
            break;
        }
    }
    puts("YES");
    for (int i = 0; i < n; ++ i){
        printf("%d%c", a[i], " \n"[i == n - 1]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}