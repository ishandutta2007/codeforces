#include <bits/stdc++.h>

const int N = 310;

int a[N][N];

void solve(){
    memset(a, 0, sizeof(a));
    int n, k;
    scanf("%d%d", &n, &k);
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            if (cnt == k){
                goto print;
            }
            ++ cnt;
            a[j][(i + j) % n] = 1;
        }
    }
    print:
    int x = (k + n - 1) / n, y = k / n;
    printf("%d\n", 2 * (x - y));
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            printf("%d", a[i][j]);
        }
        puts("");
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