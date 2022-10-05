#include <bits/stdc++.h>

const int N = 200010;
const int M = 26;

char s[N];
int cnt[M];

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    int ans = 0;
    for (int u = 0, v = k - 1; u <= v; ++ u, -- v){
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n / k; ++ i){
            ++ cnt[s[i * k + u] - 'a'];
            if (u != v){
                ++ cnt[s[i * k + v] - 'a'];
            }
        }
        int sum = std::accumulate(cnt, cnt + M, 0);
        sum -= *std::max_element(cnt, cnt + M);
        ans += sum;
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