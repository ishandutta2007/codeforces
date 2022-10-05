#include <bits/stdc++.h>

const int MAX = 10;
const int N = 300010;
typedef long long ll;

char s[N];

bool check(int i, int n){
    for (int j = 0; j < n; ++ j){
        for (int k = 1; j + 2 * k < n; ++ k){
            if ((i >> j & 1) == (i >> (j + k) & 1) && (i >> j & 1) == (i >> (j + 2 * k) & 1)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    /*for (int i = 0; i < 1 << MAX; ++ i){
        bool flag = false;
        for (int j = 0; j < MAX; ++ j){
            for (int k = 1; j + 2 * k < MAX; ++ k){
                if ((i >> j & 1) == (i >> (j + k) & 1) && (i >> j & 1) == (i >> (j + 2 * k) & 1)){
                    flag = true;
                }
            }
        }
        if (!flag){
            printf("%d\n", i);
            return 0;
        }
    }*/
    scanf("%s", s);
    int n = strlen(s);
    ll ans = 1ll * n * (n + 1) / 2;
    for (int i = 0; i < n; ++ i){
        for (int j = i; j < n && j < i + MAX - 1; ++ j){
            int state = 0;
            for (int k = i; k <= j; ++ k){
                state |= (s[k] - '0') << (k - i);
            }
            if (!check(state, j - i + 1)){
                -- ans;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}