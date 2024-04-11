#include<bits/stdc++.h>

const int N = 300010;
typedef long long ll;

ll a[N];
int cnt[N], pre[N];
int next[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
        cnt[i] = __builtin_popcountll(a[i]);
        pre[i + 1] = pre[i] + cnt[i];
    }
    int odd = 0, even = 0;
    for (int i = 0; i <= n; ++ i){
        odd += pre[i] & 1;
        even += !(pre[i] & 1);
    }
    next[n] = n;
    for (int i = n - 1; i >= 0; -- i){
        next[i] = cnt[i] ? i : next[i + 1];
    }
    ll ans = 1ll * odd * (odd - 1) / 2 + 1ll * even * (even - 1) / 2;
    for (int i = 0; i < n; ++ i){
        int max = 0, sum = 0;
        for (int j = i; j < n && sum <= 130; ++ j){
            if (!cnt[j]){
                j = next[j];
            }
            max = std::max(max, cnt[j]);
            sum += cnt[j];
            if (!(sum & 1) && max > sum >> 1){
                ans -= next[j + 1] - j;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}