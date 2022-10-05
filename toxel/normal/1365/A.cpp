#include <bits/stdc++.h>

const int N = 60;

int a[N][N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            scanf("%d", &a[i][j]);
        }
    }
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; ++ i){
        int cnt = 0;
        for (int j = 0; j < m; ++ j){
            cnt += a[i][j];
        }
        if (cnt == 0){
            ++ cnt1;
        }
    }
    for (int j = 0; j < m; ++ j){
        int cnt = 0;
        for (int i = 0; i < n; ++ i){
            cnt += a[i][j];
        }
        if (cnt == 0){
            ++ cnt2;
        }
    }
    int x = std::min(cnt1, cnt2);
    puts(x & 1 ? "Ashish" : "Vivek");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}