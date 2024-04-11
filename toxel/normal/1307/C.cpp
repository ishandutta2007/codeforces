#include <bits/stdc++.h>

const int N = 100010;
const int M = 26;
using ll = long long;

char s[N];
int pre[N][M];
ll cnt[M][M];

int main(){
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++ i){
        memcpy(pre[i], pre[i - 1], sizeof(pre[i]));
        ++ pre[i][s[i] - 'a'];
        for (int j = 0; j < M; ++ j){
            cnt[s[i] - 'a'][j] += pre[i - 1][j];
        }
    }
    ll ans = 0;
    for (int i = 0; i < M; ++ i){
        ans = std::max(ans, ll(pre[n][i]));
        for (int j = 0; j < M; ++ j){
            ans = std::max(ans, cnt[i][j]);
        }
    }
    printf("%lld\n", ans);
    return 0;
}