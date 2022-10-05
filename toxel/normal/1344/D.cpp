#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

int a[N];
int ans[N];
bool addable[N];

ll calc(ll k, int n){
    memset(addable, 0, sizeof(addable));
    ll sum = 0;
    auto calc_delta = [&](int i, ll x){
        return k - a[i] + 3 * x * x - 3 * x + 1;
    };
    for (int i = 0; i < n; ++ i){
        ll left = 0, right = a[i];
        while (left < right){
            ll mid = (left + right + 1) / 2;
            ll delta = calc_delta(i, mid);
            if (delta < 0){
                left = mid;
            }
            else{
                right = mid - 1;
            }
        }
        ans[i] = left;
        sum += ans[i];
        if (0 <= ans[i] + 1 && ans[i] + 1 <= a[i]){
            if (calc_delta(i, ans[i] + 1) == 0){
                addable[i] = true;
            }
        }
    }
    return sum;
}

int main(){
    int n;
    ll k;
    scanf("%d%lld", &n, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    ll left = -4e18, right = 4e18;
    while (left < right){
        ll mid = (left + right) >> 1;
        if (calc(mid, n) < k){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    calc(left, n);
    ll total = 0;
    for (int i = 0; i < n; ++ i){
        total += ans[i];
    }
    for (int i = 0; i < n; ++ i){
        if (addable[i] && total < k){
            ++ total;
            ++ ans[i];
        }
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n - 1]);
    }
    return 0;
}