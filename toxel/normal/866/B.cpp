#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;
typedef std::pair <int, int> pii;

int s[N], a[N], b[N];
int n, S;

ll solve(ll suma, ll sumb){
    if (suma == 0){
        ll ans = 0;
        for (int i = 0; i < n; ++ i){
            ans += 1ll * b[i] * s[i];
        }
        return ans;
    }
    if (sumb == 0){
        ll ans = 0;
        for (int i = 0; i < n; ++ i){
            ans += 1ll * a[i] * s[i];
        }
        return ans;
    }
    ll ans = 0, tot = 0;
    std::multiset <pii> set;
    for (int i = 0; i < n; ++ i){
        ans += 1ll * s[i] * a[i];
        tot += s[i];
        set.insert({a[i] - b[i], s[i]});
    }
    ll mintot = tot - sumb * S - suma * S;
    tot -= suma * S;
    for (auto u : set){
        int x;
        if (u.first >= 0){
            x = std::max(0ll, std::min((ll) u.second, tot));
        }
        else{
            x = std::min((ll) u.second, tot - mintot);
        }
        tot -= x;
        ans -= 1ll * u.first * x;
    }
    return ans;
}

int main(){
    scanf("%d%d", &n, &S);
    ll sum = 0, suma = 0, sumb = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d%d%d", &s[i], &a[i], &b[i]);
        if (a[i] > b[i]){
            suma += s[i];
        }
        else{
            sumb += s[i];
        }
        sum += s[i];
    }
    sum = (sum + S - 1) / S;
    suma = (suma + S - 1) / S;
    sumb = (sumb + S - 1) / S;
    if (sum == suma + sumb){
        ll ans = 0;
        for (int i = 0; i < n; ++ i){
            ans += 1ll * s[i] * std::max(a[i], b[i]);
        }
        printf("%lld\n", ans);
        return 0;
    }
    printf("%lld\n", std::max(solve(suma - 1, sumb), solve(suma, sumb - 1)));
    return 0;
}