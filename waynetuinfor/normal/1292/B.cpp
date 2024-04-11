#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x0, y0, ax, ay, bx, by;
    scanf("%lld%lld%lld%lld%lld%lld", &x0, &y0, &ax, &ay, &bx, &by);
    long long xs, ys, t;
    scanf("%lld%lld%lld", &xs, &ys, &t);
    long long x = x0, y = y0;
    vector<pair<long long, long long>> v;
    const long long kInf = 1'000'000'000'000'000'000;
    while (true) {
        v.emplace_back(x, y);
        if (x > kInf / ax || y > kInf / ay) break;
        x = ax * x + bx;
        y = ay * y + by;
        if (x > kInf || y > kInf) break;
    }
    int n = v.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        {
            long long dist = abs(v[i].first - xs) + abs(v[i].second - ys);
            if (dist <= t) ans = max(ans, 1);
            for (int j = i + 1; dist <= t && j < n; ++j) {
                dist += abs(v[j].first - v[j - 1].first) + abs(v[j].second - v[j - 1].second);
                if (dist <= t) ans = max(ans, j - i + 1);
            }
        }
        {
            long long dist = abs(v[i].first - xs) + abs(v[i].second - ys);
            if (dist <= t) ans = max(ans, 1);
            for (int j = i - 1; dist <= t && j >= 0; --j) {
                dist += abs(v[j].first - v[j + 1].first) + abs(v[j].second - v[j + 1].second);
                if (dist <= t) ans = max(ans, i - j + 1);
            }
        }
    }
    printf("%d\n", ans);
}