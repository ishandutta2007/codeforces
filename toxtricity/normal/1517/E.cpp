#include <bits/stdc++.h>

const int N = 200010;
const int moder = 998244353;
using ll = long long;

int a[N];
ll pre[N], pre1[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        pre[i] = pre[i - 1] + a[i];
        pre1[i] = pre1[i - 1];
        if (i % 2 == 1){
            pre1[i] += a[i];
        }
    }
    int ans = 1;
    for (int l = 1; l < n; ++ l){
        if (pre[l] > pre[n] - pre[l]){
            ++ ans;
        }
    }
    for (int l = 1; l < n; ++ l){
        for (int type = 0; type < 4; ++ type){
            if (l == 1 && (type & 1)){
                continue;
            }
            int left = 0, right = n;
            while (left < right){
                int mid = (left + right + 1) / 2;
                int real = l + 2 * mid - 1;
                if (real > n){
                    right = mid - 1;
                    continue;
                }
                if (real == n && (type >> 1)){
                    right = mid - 1;
                    continue;
                }
                ll lsum = pre[l];
                ll rsum = pre[n] - pre[real - 1];
                if (type & 1){
                    lsum -= a[1];
                    rsum += a[1];
                }
                if (type >> 1){
                    rsum -= a[n];
                    lsum += a[n];
                }
                ll sum1 = pre1[real - 1] - pre1[l]; // odd
                ll sum2 = pre[real - 1] - pre[l] - sum1; // even
                if (l % 2 == 0){
                    std::swap(sum1, sum2);
                }
                lsum += sum1;
                rsum += sum2;
                if (lsum < rsum){
                    left = mid;
                }
                else{
                    right = mid - 1;
                }
            }
            ans += left;
            ans -= ans >= moder ? moder : 0;
        }
    }
    ans %= moder;
    printf("%d\n", ans);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}