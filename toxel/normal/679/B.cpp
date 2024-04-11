#include<bits/stdc++.h>

typedef long long ll;

int root(ll n){
    int ret = std::max(0, (int) pow(n, 1.0 / 3) - 3);
    while (1ll * ret * ret * ret < n){
        ++ ret;
    }
    if (1ll * ret * ret * ret > n) -- ret;
    return ret;
}

typedef std::pair <int, ll> pil;

const int N = 1000;

int dp[N], max[N], sit[N];

pil solve(ll m){
    if (m < N){
        return {max[m], sit[m]};
    }
    int rt = root(m);
    pil p1 = solve(m - 1ll * rt * rt * rt);
    ++ p1.first;
    p1.second += 1ll * rt * rt * rt;
    pil p2 = solve(3ll * (rt - 1) * (rt - 1) + 3ll * (rt - 1));
    p2.second += 1ll * (rt - 1) * (rt - 1) * (rt - 1);
    ++ p2.first;
    return std::max(p1, p2);
}

int main(){
    for (int i = 1; i < N; ++ i){
        int rt = root(i);
        dp[i] = dp[i - rt * rt * rt] + 1;
        max[i] = std::max(max[i - 1], dp[i]);
        for (int j = i; j >= 0; -- j){
            if (dp[j] == max[i]){
                sit[i] = j;
                break;
            }
        }
    }
    ll m;
    scanf("%lld", &m);
    pil ans = solve(m);
    printf("%d %lld\n", ans.first, ans.second);
    return 0;
}