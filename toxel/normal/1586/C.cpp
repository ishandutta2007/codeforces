#include <bits/stdc++.h>

const int N = 1000010;

char s[N];
std::string str[N];
int cnt[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%s", s);
        str[i] = s;
    }
    for (int i = 1; i < n; ++ i){
        for (int j = 1; j < m; ++ j){
            if (str[i - 1][j] == 'X' && str[i][j - 1] == 'X'){
                ++ cnt[j];
            }
        }
    }
    for (int i = 1; i < m; ++ i){
        cnt[i] += cnt[i - 1];
    }
    int test;
    scanf("%d", &test);
    while (test --){
        int l, r;
        scanf("%d%d", &l, &r);
        -- l, -- r;
        puts(cnt[r] - cnt[l] ? "NO" : "YES");
    }
    return 0;
}