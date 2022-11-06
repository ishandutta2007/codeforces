#include <bits/stdc++.h>
using namespace std;

const int maxn = 300 + 10;

typedef pair<double, double> pt;
#define x first
#define y second

double cross(const pt& o, const pt& a, const pt& b) {
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

pt operator-(const pt& a, const pt& b) { return make_pair(a.x - b.x, a.y - b.y); }

vector<pt> convex_hull(vector<pt> p) {
    sort(p.begin(), p.end());
    int m = 0;
    vector<pt> ret(2 * p.size());
    for (int i = 0; i < p.size(); ++i) {
        while (m >= 2 && cross(ret[m - 2], ret[m - 1], p[i]) < 0) --m;
        ret[m++] = p[i];
    }
    for (int i = p.size() - 2, t = m + 1; i >= 0; --i) {
        while (m >= t && cross(ret[m - 2], ret[m - 1], p[i]) < 0) --m;
        ret[m++] = p[i];
    }
    ret.resize(m - 1);
    return ret;
}

double cs(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}

double area(pt a, pt b, pt c, pt d) {
    return 0.5 * fabs(cs(a, b) + cs(b, c) + cs(c, d) + cs(d, a));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pt> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
    vector<pt> ch = convex_hull(p);
    if (ch.size() < 4) {
        double ans = 0.0;
        for (int i = 0; i < n; ++i) if (p[i] != ch[0] && p[i] != ch[1] && p[i] != ch[2]) ans = max(ans, area(ch[0], ch[1], ch[2], p[i]));
        cout << fixed << setprecision(20) << ans << endl;
        return 0;
    }
    // cout << "ch.size() = " << ch.size() << endl;
    // for (auto i : ch) cout << i.x << ' ' << i.y << endl;
    double ans = 0.0;
    for (int i = 0; i < ch.size(); ++i) {
        for (int j = i + 1; j < ch.size(); ++j) {
            for (int k = j + 1; k < ch.size(); ++k) {
                for (int l = k + 1; l < ch.size(); ++l) ans = max(ans, area(ch[i], ch[j], ch[k], ch[l]));
            }
        }
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}