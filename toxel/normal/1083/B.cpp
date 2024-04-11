#include<bits/stdc++.h>

const int N = 500010;
typedef long long ll;
const ll INF = 1e10;

char s[N], t[N];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s%s", s, t);
    ll now = 0;
    ll ans = 0;
    for (int i = 0; i < n; ++ i){
        now = std::min(now * 2 + t[i] - s[i], INF);
        ans += std::min(now + 1, (ll) k);
    }
    printf("%lld\n", ans);
    return 0;
}