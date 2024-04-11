#include <bits/stdc++.h>

const int N = 1000010;
using ll = long long;

int a[N], b[N];

int main(){
    int n;
    scanf("%d", &n);
    ll sum = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        sum += a[i];
    }
    ll x = sum;
    std::vector <ll> prime;
    for (ll i = 2; i * i <= x; ++ i){
        if (x % i == 0){
            prime.push_back(i);
            while (x % i == 0){
                x /= i;
            }
        }
    }
    if (x > 1){
        prime.push_back(x);
    }
    ll ans = LLONG_MAX;
    std::vector <int> vec;
    for (auto u : prime){
        for (int i = 0; i < n; ++ i){
            b[i] = a[i] % u;
        }
        ll ret = 0;
        ll sum = 0;
        for (int i = 0, j = 0; i < n; i = j){
            while (j < n && sum < u){
                sum += b[j];
                vec.push_back(b[j]);
                ++ j;
            }
            if (j == n && sum < u){
                break;
            }
            vec.back() -= sum - u;
            -- j;
            b[j] -= vec.back();
            if (b[j] == 0){
                ++ j;
            }
            int sz = vec.size();
            int mid;
            sum = 0;
            for (int k = 0; k < sz; ++ k){
                sum += vec[k];
                if (sum >= (u + 1) / 2){
                    mid = k;
                    break;
                }
            }
            for (int k = 0; k < sz; ++ k){
                if (k < mid){
                    ret += 1ll * vec[k] * (mid - k);
                }
                else if (k > mid){
                    ret += 1ll * vec[k] * (k - mid);
                }
            }
            sum = 0;
            vec.clear();
        }
        ans = std::min(ans, ret);
    }
    printf("%lld\n", ans == LLONG_MAX ? -1ll : ans);
    return 0;
}