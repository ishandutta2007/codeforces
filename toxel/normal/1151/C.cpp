#include <bits/stdc++.h>

typedef long long ll;
const int moder = (int) 1e9 + 7;

int sum(ll l, ll r){
    ll cnt = (r - l) / 2 + 1;
    l += r;
    if (l % 2 == 0){
        l >>= 1;
    }
    else{
        cnt >>= 1;
    }
    l %= moder, cnt %= moder;
    return 1ll * l * cnt % moder;
}

int main(){
    ll begin[2] = {};
    ll now = 0, left = 1;
    ll l, r;
    scanf("%lld%lld", &l, &r);
    int ans = 0;
    for (int i = 0; ; ++ i, now ^= 1){
        ll right = left + (1ll << i) - 1;
        ll end = begin[now] + (1ll << i) - 1;
        ll l1 = std::max(l, left), r1 = std::min(r, right);
        if (l1 <= r1){
            ll tmpl = begin[now] + l1 - left, tmpr = begin[now] + r1 - left;
            if (now){
                ans += sum(2 * tmpl + 2, 2 * tmpr + 2);
            }
            else{
                ans += sum(2 * tmpl + 1, 2 * tmpr + 1);
            }
            ans -= ans >= moder ? moder : 0;
        }
        begin[now] = end + 1;
        left = right + 1;
        if (left > r){
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}