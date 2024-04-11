#include<bits/stdc++.h>

typedef std::pair <int, int> pii;
typedef long long ll;
const int N = 200010;
const int MAX = 1 << 18;

int d, n, m;
pii p[N];
ll ans;
pii seg[MAX << 1];

void add(int sit, int value){
    seg[sit + MAX] = {value, sit};
    for (sit += MAX, sit >>= 1; sit; sit >>= 1){
        seg[sit] = std::min(seg[sit << 1], seg[sit << 1 | 1]);
    }
}

pii query(int l, int r){
    pii ret = {INT_MAX, INT_MAX};
    for (l += MAX, r += MAX + 1; l < r; l >>= 1, r >>= 1){
        if (l & 1) ret = std::min(ret, seg[l ++]);
        if (r & 1) ret = std::min(ret, seg[-- r]);
    }
    return ret;
}

int solve(int l, int r, int left, int target){
    pii pos = query(l, r);
    int sit = pos.second;
    if (l < sit){
        left = solve(l, sit - 1, left, p[sit].first);
    }
    if (target - p[sit].first <= n){
        int insert = std::max(0, target - p[sit].first - left);
        ans += 1ll * insert * pos.first;
        return left + insert - (target - p[sit].first);
    }
    int insert = n - left;
    ans += 1ll * insert * pos.first;
    return solve(sit + 1, r, n - (p[sit + 1].first - p[sit].first), target);
}

int main(){
    scanf("%d%d%d", &d, &n, &m);
    for (int i = 1; i <= m; ++ i){
        int x, y;
        scanf("%d%d", &x, &y);
        p[i] = {x, y};
    }
    std::sort(p + 1, p + m + 1);
    p[0] = {0, (int) 2e6};
    for (int i = 0; i <= m; ++ i){
        add(i, p[i].second);
    }
    for (int i = 1; i <= m; ++ i){
        if (p[i].first - p[i - 1].first > n){
            puts("-1");
            return 0;
        }
    }
    if (d - p[m].first > n){
        puts("-1");
        return 0;
    }
    solve(1, m, n - p[1].first, d);
    printf("%lld\n", ans);
    return 0;
}