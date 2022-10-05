#include <bits/stdc++.h>

const int N = 200010;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int l = 0; l < n; ++ l){
        for (int r = l; r - l + 1 <= 7 && r < n; ++ r){
            bool flag = true;
            for (int i = l; i <= r; ++ i){
                for (int j = i + 1; j <= r; ++ j){
                    for (int k = j + 1; k <= r; ++ k){
                        if (a[i] <= a[j] && a[j] <= a[k]){
                            flag = false;
                            goto end;
                        }
                        if (a[i] >= a[j] && a[j] >= a[k]){
                            flag = false;
                            goto end;
                        }
                    }
                }
            }
            end:
            ans += flag;
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