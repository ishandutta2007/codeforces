#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

char s[N];
int pre[N][2];
ll cost[N][2];

int main(){
    int x, y;
    scanf("%s%d%d", s, &x, &y);
    int n = strlen(s);
    int cnt[2] = {};
    ll total = 0;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '?'){
            continue;
        }
        if (s[i] == '0'){
            total += 1ll * y * cnt[1];
        }
        else{
            total += 1ll * x * cnt[0];
        }
        ++ cnt[s[i] - '0'];
    }
    for (int i = 0; i < n; ++ i){
        pre[i + 1][0] = pre[i][0];
        pre[i + 1][1] = pre[i][1];
        ++ pre[i + 1][s[i] - '0'];
    }
    for (int i = 0; i < n; ++ i){
        cost[i][0] = 1ll * pre[i][1] * y + 1ll * (pre[n][1] - pre[i + 1][1]) * x;
        cost[i][1] = 1ll * pre[i][0] * x + 1ll * (pre[n][0] - pre[i + 1][0]) * y;
    }
    int from = 0, to = 1;
    if (x < y){
        std::swap(from, to);
    }
    int cnt1 = 0;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '?'){
            total += cost[i][from];
            ++ cnt1;
        }
    }
    ll ans = total;
    int cur = 0;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '?'){
            ++ cur;
            total += cost[i][to] - cost[i][from];
            ll c = 1ll * cur * (cnt1 - cur) * std::min(x, y);
            ans = std::min(ans, total + c);
        }
    }
    printf("%lld\n", ans);
    return 0;
}