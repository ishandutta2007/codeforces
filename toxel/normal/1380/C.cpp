#include <bits/stdc++.h>

const int N = 100010;

int a[N];

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        int n, x;
        scanf("%d%d", &n, &x);
        for (int i = 0; i < n; ++ i){
            scanf("%d", &a[i]);
        }
        std::sort(a, a + n);
        int cnt = 0, next = n;
        for (int i = n - 1; i >= 0; -- i){
            if (1ll * a[i] * (next - i) >= x){
                ++ cnt;
                next = i;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}