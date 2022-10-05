#include <bits/stdc++.h>

const int N = 300010;

char s[N];

void solve(){
    int n, k;
    scanf("%d%d%s", &n, &k, s);
    for (int i = 0; i < k; ++ i){
        bool has0 = false, has1 = false;
        for (int j = i; j < n; j += k){
            if (s[j] == '0'){
                has0 = true;
            }
            if (s[j] == '1'){
                has1 = true;
            }
        }
        if (has0 && has1){
            puts("NO");
            return;
        }
        if (has0 || has1){
            for (int j = i; j < n; j += k){
                s[j] = has0 ? '0' : '1';
            }
        }
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < k; ++ i){
        cnt0 += s[i] == '0';
        cnt1 += s[i] == '1';
    }
    puts(cnt0 > k / 2 || cnt1 > k / 2 ? "NO" : "YES");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}