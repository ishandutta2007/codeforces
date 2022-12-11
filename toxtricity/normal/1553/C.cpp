#include <bits/stdc++.h>

const int N = 20;

char s[N];

void solve(){
    scanf("%s", s);
    int n = strlen(s);
    int ans = n;
    for (int i = 0; i < 1 << n; ++ i){
        bool flag = true;
        for (int j = 0; j < n; ++ j){
            if (s[j] != '?' && s[j] - '0' != (i >> j & 1)){
                flag = false;
                break;
            }
        }
        if (!flag){
            continue;
        }
        int cnt[2] = {};
        for (int j = 0; j < n; ++ j){
            cnt[j & 1] += i >> j & 1;
            int left[2] = {(9 - j) / 2, (10 - j) / 2};
            if (cnt[0] + left[0] < cnt[1] || cnt[1] + left[1] < cnt[0]){
                ans = std::min(ans, j + 1);
                break;
            }
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