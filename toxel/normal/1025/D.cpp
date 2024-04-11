#include<bits/stdc++.h>

const int N = 710;

bool dp[N][N][2];
int a[N];
int gcd[N][N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            gcd[i][j] = std::__gcd(a[i], a[j]);
        }
    }
    for (int len = 0; len < n; ++ len){
        for (int i = 0; i + len < n; ++ i){
            for (int j = i; j <= i + len; ++ j){
                bool leftok = j == i || dp[i][j - 1][1];
                bool rightok = j == i + len || dp[j + 1][i + len][0];
                if (!leftok || !rightok) continue;
                if (i == 0 && len == n - 1){
                    puts("Yes");
                    return 0;
                }
                if (i > 0 && gcd[i - 1][j] > 1){
                    dp[i][i + len][0] = true;
                }
                if (i + len < n - 1 && gcd[i + len + 1][j] > 1){
                    dp[i][i + len][1] = true;
                }
            }
        }
    }
    puts("No");
    return 0;
}