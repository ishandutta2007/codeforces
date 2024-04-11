#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

ll pre[N], a[N];

void solve(){
    int n, s;
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
    ll max = -1, pos = -1;
    for (int i = 0; i <= n; ++ i){
        int left = 0, right = n;
        while (left < right){
            int mid = (left + right + 1) / 2;
            if (pre[mid] - (mid >= i ? a[i] : 0) > s){
                right = mid - 1;
            }
            else{
                left = mid;
            }
        }
        ll value = left - (left >= i);
        if (value > max){
            max = value;
            pos = i;
        }
    }
    printf("%lld\n", pos);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}