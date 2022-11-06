#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int l[maxn], r[maxn];
long long ln[maxn];

double calc(int l, int r, double u, double d) {
    if (r < l) return 0.0;
    double t = ln[r] - (l == 0 ? 0 : ln[l - 1]);
    return t / u * (u - d);
}

double get(double x, double y, double g, double p) {
    return g - (g - x) / y * p;
}

double inter(double l, double r, double x, double y) {
    double tl = max(l, x);
    double tr = min(r, y);
    if (tl > tr) return 0.0;
    return tr - tl;
}

double uni(vector<pair<double, double>> v, double l, double r) {
    vector<pair<double, double>> e; 
    for (int i = 0; i < v.size(); ++i) {
        e.emplace_back(v[i].first, 1);
        e.emplace_back(v[i].second, -1);
    }
    sort(e.begin(), e.end());
    double last = 0.0, ans = 0.0;
    int cnt = 0;
    for (int i = 0; i < e.size(); ++i) {
        if (e[i].second == 1) {
            if (cnt == 0) last = e[i].first;
            ++cnt;
        } else {
            --cnt;
            if (cnt == 0) ans += inter(last, e[i].first, l, r); 
        }
    }
    return ans;
}

int main() {
    int sy, a, b; scanf("%d %d %d", &sy, &a, &b); 
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d %d", &l[i], &r[i]);
    ln[0] = r[0] - l[0];
    for (int i = 1; i < n; ++i) ln[i] = ln[i - 1] + r[i] - l[i];
    int q; scanf("%d", &q);
    int d = -1;
    while (q--) {
        int x, y; scanf("%d %d", &x, &y);
        int lt = n; d = 20;
        while (d--) if (lt - (1 << d) >= 0) {
            int to = lt - (1 << d);
            if (l[to] * 1ll * y - (l[to] - x) * 1ll * sy >= a * 1ll * y)
                lt = to;
        }
        int rg = -1; d = 20;
        while (d--) if (rg + (1 << d) < n) {
            int to = rg + (1 << d);
            if (r[to] * 1ll * y - (r[to] - x) * 1ll * sy <= b * 1ll * y)
                rg = to;
        }
        // printf("lt = %d rg = %d\n", lt, rg);
        double ans = calc(lt, rg, y, sy);
        vector<pair<double, double>> v;
        if (lt >= 1) {
            double t = get(x, y, r[lt - 1], sy);
            double s = get(x, y, l[lt - 1], sy);
            v.emplace_back(s, t);
        }
        if (rg < n - 1) {
            double s = get(x, y, l[rg + 1], sy);
            double t = get(x, y, r[rg + 1], sy);
            v.emplace_back(s, t);
            // printf("s = %.5lf\n", s);
        }
        ans += uni(v, a, b);
        printf("%.20lf\n", ans);
    }
    return 0;
}