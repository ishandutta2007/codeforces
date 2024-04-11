#include <bits/stdc++.h>

void solve(){
    int a[3];
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    int ans = 0;
    for (int i = 0; i < 1 << 8; ++ i){
        int cnt[3] = {};
        int ccnt = 0;
        for (int j = 1; j < 8; ++ j){
            if (i >> j & 1){
                ++ ccnt;
                for (int k = 0; k < 3; ++ k){
                    if (j >> k & 1){
                        ++ cnt[k];
                    }
                }
            }
        }
        if (cnt[0] <= a[0] && cnt[1] <= a[1] && cnt[2] <= a[2]){
            ans = std::max(ans, ccnt);
        }
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