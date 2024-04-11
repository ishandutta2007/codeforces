#include<bits/stdc++.h>

typedef long long ll;

int main(){
    ll n, k;
    scanf("%lld%lld", &n, &k);
    ll right = k - 1 >> 1;
    ll left = 1;
    right = std::min(right, n);
    right = std::min(right, k - 1);
    left = std::max(left, k - n);
    if (left > right){
        puts("0");
        return 0;
    }
    printf("%lld\n", right - left + 1);
    return 0;
}