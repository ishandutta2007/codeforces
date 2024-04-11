#include<bits/stdc++.h>

typedef long long ll;

const ll N = 500010;

char s[N];
ll pre[N], suf[N];

int main(){
    ll n, a, b, t;
    scanf("%lld%lld%lld%lld", &n, &a, &b, &t);
    scanf("%s", s + 1);
    ll now = 1 + (s[1] == 'w' ? b : 0);
    for (ll i = 1; i <= n; ++ i){
        pre[i] = pre[i - 1] + 1 + (i == 1 ? 0 : a) + (s[i] == 'w' ? b : 0);
    }
    for (ll i = n; i; -- i){
        suf[i] = suf[i + 1] + a + 1 + (s[i] == 'w' ? b : 0);
    }
    ll max = 0;
    for (ll i = 1; i <= n; ++ i){
        if (pre[i] <= t){
            max = std::max(max, i);
        }
    }
    for (ll i = 2; i <= n; ++ i){
        if (suf[i] + now <= t){
            max = std::max(max, n - i + 1);
        }
    }
    ll left = 1, right = 2;
    while (true){
        while (right <= n && pre[left] + suf[right] + (left - 1) * a > t){
            ++ right;
        }
        if (right > n) break;
        max = std::max(max, left + n - right + 1);
        ++ left;
        if (left == right){
            ++ right;
        }
    }
    left = n - 1, right = n;
    while (true){
        while (left >= 1 && pre[left] + suf[right] + (n - right + 1) * a > t){
            -- left;
        }
        if (left < 1) break;
        max = std::max(max, left + n - right + 1);
        -- right;
        if (left == right){
            -- left;
        }
    }
    printf("%lld\n", max);
    return 0;
}