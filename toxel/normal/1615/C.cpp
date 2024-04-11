#include <bits/stdc++.h>

const int N = 200010;

char a[N], b[N];

void solve(){
    int n;
    scanf("%d", &n);
    scanf("%s%s", a, b);
    int cnta = 0, cntb = 0;
    for (int i = 0; i < n; ++ i){
        cnta += a[i] == '1';
        cntb += b[i] == '1';
    }
    if (cnta == 0 && cntb == 0){
        puts("0");
        return;
    }
    if (cnta == 0 || cntb == 0){
        puts("-1");
        return;
    }
    int ans = INT_MAX;
    if (cnta == cntb){
        int cnt = 0;
        for (int i = 0; i < n; ++ i){
            if (a[i] != b[i]){
                ++ cnt;
            }
        }
        ans = std::min(ans, cnt);
    }
    if (n - cnta + 1 == cntb){
        int cnt = 0;
        for (int i = 0; i < n; ++ i){
            if (a[i] == b[i]){
                ++ cnt;
            }
        }
        for (int i = 0; i < n; ++ i){
            if (a[i] == '1'){
                if (b[i] == '1'){
                    ans = std::min(ans, cnt - 1 + 1);
                }
                else{
                    ans = std::min(ans, cnt + 1 + 1);
                }
            }
        }
    }
    if (ans == INT_MAX){
        ans = -1;
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