#include<bits/stdc++.h>

const int N = 300010;
typedef long long ll;
typedef std::pair <ll, ll> pii;

ll t[N], w[N];
pii p[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld%lld", &t[i], &w[i]);
    }
    for (int i = 0; i < n; ++ i){
        p[i] = {t[i], w[i]};
    }
    std::sort(p + 1, p + n, std::greater <pii>());
    int now = 1;
    int ans = INT_MAX, cnt = 0;
    std::multiset <ll> set;
    while (true){
        while (now < n && p[now].first > p[0].first){
            set.insert(p[now].second - p[now].first);
            ++ now;
        }
        ans = std::min(ans, now - cnt);
        if (set.empty() || *(set.begin()) + 1 > p[0].first){
            break;
        }
        ++ cnt;
        p[0].first -= *(set.begin()) + 1;
        set.erase(set.begin());
    }
    printf("%d\n", ans);
    return 0;
}