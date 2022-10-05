#include <bits/stdc++.h>

const int N = 110;

bool prime[N];
char s[N];

void solve(){
    int n;
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++ i){
        if (!prime[s[i] - '0']){
            printf("1\n%d\n", s[i] - '0');
            return;
        }
    }
    for (int i = 0; i < n; ++ i){
        for (int j = i + 1; j < n; ++ j){
            int x = 10 * (s[i] - '0') + s[j] - '0';
            if (!prime[x]){
                printf("2\n%d\n", x);
                return;
            }
        }
    }
}

int main(){
    for (int i = 2; i < N; ++ i){
        prime[i] = true;
        for (int j = 2; j < i; ++ j){
            if (i % j == 0){
                prime[i] = false;
            }
        }
    }
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}