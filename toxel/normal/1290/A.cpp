#include <bits/stdc++.h>

const int N = 3510;

int a[N];

void solve(){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    k = std::min(m - 1, k);
    int left = m - 1 - k;
    int ans = 0;
    for (int i = 0; i <= k; ++ i){
        int min = INT_MAX;
        for (int j = 0; j <= left; ++ j){
            int l = i + j, r = k - i + left - j;
            min = std::min(min, std::max(a[l], a[n - 1 - r]));
        }
        ans = std::max(ans, min);
    }
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}