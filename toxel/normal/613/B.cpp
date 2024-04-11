#include<bits/stdc++.h>

const int N = 100010;
typedef long long ll;
typedef std::pair <int, int> pii;

int a[N], ans[N];
ll pre[N];
pii p[N];

int main(){
    int n, A, cf, cm;
    ll m;
    scanf("%d%d%d%d%lld", &n, &A, &cf, &cm, &m);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        p[i] = {a[i], i};
    }
    std::sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; ++ i){
        a[i] = p[i].first;
        pre[i] = pre[i - 1] + a[i];
    }
    ll max = -1, sit = -1;
    for (int i = 0; i <= n; ++ i){
        ll remain = m - (1ll * i * A - (pre[n] - pre[n - i]));
        if (remain < 0){
            continue;
        }
        int left = 0, right = A;
        while (left < right){
            int mid = left + right + 1 >> 1;
            int sit = std::lower_bound(a + 1, a + n - i + 1, mid) - a;
            if (remain < 1ll * mid * (sit - 1) - pre[sit - 1]){
                right = mid - 1;
            }
            else{
                left = mid;
            }
        }
        ll value = 1ll * left * cm + i * cf;
        if (max < value){
            max = value;
            sit = i;
        }
    }
    printf("%lld\n", max);
    ll remain = m - (1ll * sit * A - (pre[n] - pre[n - sit]));
    int left = 0, right = A;
    while (left < right){
        int mid = left + right + 1 >> 1;
        int sit1 = std::lower_bound(a + 1, a + n - sit + 1, mid) - a;
        if (remain < 1ll * mid * (sit1 - 1) - pre[sit1 - 1]){
            right = mid - 1;
        }
        else{
            left = mid;
        }
    }
    for (int i = 1; i <= n; ++ i){
        a[i] = std::max(a[i], left);
    }
    for (int i = n - sit + 1; i <= n; ++ i){
        a[i] = A;
    }
    for (int i = 1; i <= n; ++ i){
        ans[p[i].second] = a[i];
    }
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}