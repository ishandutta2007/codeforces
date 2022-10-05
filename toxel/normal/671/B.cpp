#include<bits/stdc++.h>

const int N = 500010;
typedef long long ll;

int c[N];

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    ll sum = 0;
    for (int i = 0; i < n; ++ i){
        scanf("%d", &c[i]);
        sum += c[i];
    }
    ll min = sum / n, max = min + (sum % n != 0);
    ll left = 0, right = min;
    while (left < right){
        ll mid = left + right + 1 >> 1;
        ll sum = 0;
        for (int i = 0; i < n; ++ i){
            sum += std::max(0ll, mid - c[i]);
        }
        if (sum <= k){
            left = mid;
        }
        else{
            right = mid - 1;
        }
    }
    ll ans = left;
    left = max, right = sum;
    while (left < right){
        ll mid = left + right >> 1;
        ll sum = 0;
        for (int i = 0; i < n; ++ i){
            sum += std::max(0ll, c[i] - mid);
        }
        if (sum <= k){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    printf("%lld\n", left - ans);
    return 0;
}