#include <bits/stdc++.h>

using ll = long long;
using pii = std::pair <ll, ll>;
const ll MAX = ll(3e16);

ll dis(pii p1, pii p2){
    return std::abs(p1.first - p2.first) + std::abs(p1.second - p2.second);
}

int main(){
    ll x0, y0, ax, ay, bx, by;
    scanf("%lld%lld%lld%lld%lld%lld", &x0, &y0, &ax, &ay, &bx, &by);
    ll xs, ys, t;
    scanf("%lld%lld%lld", &xs, &ys, &t);
    std::vector <pii> points;
    while (x0 <= MAX && y0 <= MAX){
        points.emplace_back(x0, y0);
        x0 = ax * x0 + bx;
        y0 = ay * y0 + by;
    }
    int n = points.size();
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j <= i; ++ j){
            for (int k = i; k < n; ++ k){
                ll tot = dis({xs, ys}, points[i]) + dis(points[i], points[j]) + dis(points[j], points[k]);
                ll tot1 = dis({xs, ys}, points[i]) + dis(points[i], points[k]) + dis(points[k], points[j]);
                tot = std::min(tot, tot1);
                if (tot <= t){
                    ans = std::max(ans, k - j + 1);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}