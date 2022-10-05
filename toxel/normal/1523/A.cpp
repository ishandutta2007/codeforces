#include <bits/stdc++.h>

const int N = 100010;

char s[N];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    m = std::min(n, m);
    scanf("%s", s);
    for (int i = 0; i < m; ++ i){
        std::vector <int> push;
        for (int j = 0; j < n; ++ j){
            int sum = (j > 0 && s[j - 1] == '1') + (j < n - 1 && s[j + 1] == '1');
            if (s[j] == '0' && sum == 1){
                push.emplace_back(j);
            }
        }
        for (auto u : push){
            s[u] = '1';
        }
    }
    puts(s);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}