#include <bits/stdc++.h>

using ll = long long;
const int N = 200010;
const int SIGMA = 10;

char s[N];
int cnt[N];

void solve(){
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < SIGMA; ++ i){
        cnt[i] = 0;
    }
    for (int i = 0; i < n; ++ i){
        ++ cnt[s[i] - '0'];
    }
    int ans = INT_MAX;
    for (int i = 0; i < SIGMA; ++ i){
        ans = std::min(ans, n - cnt[i]);
    }
    for (int i = 0; i < SIGMA; ++ i){
        for (int j = 0; j < SIGMA; ++ j){
            if (i == j){
                continue;
            }
            int ccnt = 0, cur = 0;
            for (int k = 0; k < n; ++ k){
                if (cur == 0 && s[k] == '0' + i){
                    cur ^= 1;
                    ++ ccnt;
                }
                if (cur == 1 && s[k] == '0' + j){
                    cur ^= 1;
                    ++ ccnt;
                }
            }
            ccnt = ccnt >> 1 << 1;
            ans = std::min(ans, n - ccnt);
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