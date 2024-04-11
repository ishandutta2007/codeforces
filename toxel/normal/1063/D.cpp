#include<bits/stdc++.h>

typedef long long ll;

ll divide(ll a, ll b){
    return a / b - ((a ^ b) < 0 && a % b);
}

ll solvele(ll a, ll b){
    return divide(b, a);
}

ll solvege(ll a, ll b){
    return divide(b + a - 1, a);
}

int main(){
    ll n, l, r, k;
    scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
    ll x = r - l + 1;
    if (x <= 0){
        x += n;
    }
    if (x == n){
        ll max = -1;
        for (ll i = 1; i * i <= k; ++ i){
            if (k % i == 0){
                if (i <= n << 1){
                    max = std::max(max, i - n);
                }
                if (k / i <= n << 1){
                    max = std::max(max, k / i - n);
                }
            }
        }
        for (ll i = 1; i * i <= k + 1; ++ i){
            if ((k + 1) % i == 0){
                if (n + 1 <= i && i <= n << 1){
                    max = std::max(max, i - n);
                }
                if (n + 1 <= (k + 1) / i && (k + 1) / i <= n << 1){
                    max = std::max(max, (k + 1) / i - n);
                }
            }
        }
        printf("%lld\n", max);
        return 0;
    }
    ll ans = -1;
    for (ll i = 1, j; i <= k; i = j + 1){
        ll t = k / i;
        j = k / t;
        ll min = std::max(0ll, i - n), max = j - n;
        max = std::min(max, solvele(t, k - t * n - x));
        min = std::max(min, solvege(t, k - t * n - 2 * x));
        max = std::min(max, solvele(t + 1, k - t * n - x + n - x));
        min = std::max(min, solvege(t + 1, k - t * n - x));
        if (min <= max){
            ans = std::max(ans, max);
        }
        min = std::max(0ll, i - n), max = j - n;
        max = std::min(max, solvele(t, k - t * n - x));
        min = std::max(min, solvege(t, k - t * n - 2 * x + 1));
        max = std::min(max, solvele(t + 1, k - t * n - x + n - x + 1));
        min = std::max(min, solvege(t + 1, k - t * n - x + 1));
        if (min <= max){
            ans = std::max(ans, max);
        }
    }
    ll min = std::max(0ll, k - n + 1), max = n;
    if (0 <= k - x && k - x <= x){
        max = std::min(max, solvele(1, k - x + n - x));
        min = std::max(min, solvege(1, k - x));
        if (min <= max){
            ans = std::max(ans, max);
        }
    }
    min = std::max(0ll, k - n + 1), max = n;
    if (1 <= k - x + 1 && k - x + 1 <= x){
        max = std::min(max, solvele(1, k - x + 1 + n - x));
        min = std::max(min, solvege(1, k - x + 1));
        if (min <= max){
            ans = std::max(ans, max);
        }
    }
    printf("%lld\n", ans);
    return 0;
}