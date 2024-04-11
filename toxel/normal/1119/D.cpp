#include <bits/stdc++.h>

const int N = 100010;
typedef long long ll;
typedef std::pair <ll, int> pii;

ll s[N];
ll diff[N];
ll ans[N];
pii p[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%lld", &s[i]);
    }
    std::sort(s + 1, s + n + 1);
    for (int i = 1; i < n; ++ i){
        diff[i] = s[i + 1] - s[i];
    }
    std::sort(diff + 1, diff + n);
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; ++ i){
        ll l, r;
        scanf("%lld%lld", &l, &r);
        p[i] = {r - l + 1, i};
    }
    std::sort(p + 1, p + q + 1);
    ll now = 0, cnt = n;
    for (int i = 1, j = 1; i <= q; ++ i){
        now += cnt * (p[i].first - p[i - 1].first);
        while (j < n && diff[j] < p[i].first){
            now += diff[j] - p[i].first;
            -- cnt;
            ++ j;
        }
        ans[p[i].second] = now;
    }
    for (int i = 1; i <= q; ++ i){
        printf("%lld%c", ans[i], " \n"[i == q]);
    }
    return 0;
}