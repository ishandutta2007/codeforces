#include <bits/stdc++.h>

const int N = 1000010;
const int moder1 = (int) 1e9 + 7;
const int moder2 = (int) 998244353;

std::string s[N];
char tmp[N];
std::vector <int> dp1[N], dp2[N], dp3[N], dp4[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%s", tmp);
        s[i] = tmp;
        dp1[i].resize(m);
        dp2[i].resize(m);
        dp3[i].resize(m);
        dp4[i].resize(m);
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (s[i][j] == '#'){
                continue;
            }
            if (!i && !j){
                dp1[i][j] = dp2[i][j] = 1;
                continue;
            }
            if (i){
                dp1[i][j] += dp1[i - 1][j];
                dp2[i][j] += dp2[i - 1][j];
            }
            if (j){
                dp1[i][j] += dp1[i][j - 1];
                dp2[i][j] += dp2[i][j - 1];
            }
            dp1[i][j] %= moder1;
            dp2[i][j] %= moder2;
        }
    }
    for (int i = n - 1; i >= 0; -- i){
        for (int j = m - 1; j >= 0; -- j){
            if (s[i][j] == '#'){
                continue;
            }
            if (i == n - 1 && j == m - 1){
                dp3[i][j] = dp4[i][j] = 1;
                continue;
            }
            if (i < n - 1){
                dp3[i][j] += dp3[i + 1][j];
                dp4[i][j] += dp4[i + 1][j];
            }
            if (j < m - 1){
                dp3[i][j] += dp3[i][j + 1];
                dp4[i][j] += dp4[i][j + 1];
            }
            dp3[i][j] %= moder1;
            dp4[i][j] %= moder2;
        }
    }
    if (!dp1[n - 1][m - 1] && !dp2[n - 1][m - 1]){
        puts("0");
        return 0;
    }
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (i == 0 && j == 0){
                continue;
            }
            if (i == n - 1 && j == m - 1){
                continue;
            }
            if (1ll * dp1[i][j] * dp3[i][j] % moder1 == dp1[n - 1][m - 1] && 1ll * dp2[i][j] * dp4[i][j] % moder2 == dp2[n - 1][m - 1]){
                puts("1");
                return 0;
            }
        }
    }
    puts("2");
    return 0;
}