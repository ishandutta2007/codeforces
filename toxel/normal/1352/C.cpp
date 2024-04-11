#include <bits/stdc++.h>

using ll = long long;

void solve(){
    ll n, k;
    scanf("%lld%lld", &n, &k);
    ll left = 0, right = 1e10;
    while (left < right){
        ll mid = (left + right) / 2;
        if (mid - mid / n < k){
            left = mid + 1;
        }
        else{
            right = mid;
        }
    }
    printf("%lld\n", left);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}