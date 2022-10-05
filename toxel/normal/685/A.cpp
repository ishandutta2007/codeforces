#include<bits/stdc++.h>

typedef long long ll;

char s[10];

int digit(int n){
    -- n;
    int digit = 0;
    while (n){
        ++ digit;
        n /= 7;
    }
    return std::max(1, digit);
}

int solve(int n, int m){
    int digit1 = digit(n), digit2 = digit(m);
    if (digit1 + digit2 > 7){
        return 0;
    }
    int cnt = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            int x1 = i, len = 0;
            while (x1){
                s[len ++] = '0' + x1 % 7;
                x1 /= 7;
            }
            while (len < digit1){
                s[len ++] = '0';
            }
            int x2 = j;
            while (x2){
                s[len ++] = '0' + x2 % 7;
                x2 /= 7;
            }
            while (len < digit1 + digit2){
                s[len ++] = '0';
            }
            bool flag = true;
            for (int u = 0; u < len; ++ u){
                for (int v = u + 1; v < len; ++ v){
                    if (s[u] == s[v]){
                        flag = false;
                    }
                }
            }
            cnt += flag;
        }
    }
    return cnt;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    return printf("%d\n", solve(n, m)), 0;
}