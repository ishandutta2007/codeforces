#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;

struct point {
    int x, y;
    point(int x = 0, int y = 0): x(x), y(y) {}
    point operator+(const point &p) const { return point(x + p.x, y + p.y); }
    point operator-(const point &p) const { return point(x - p.x, y - p.y); }
    point operator-() const { return point(-x, -y); }
    long long operator*(const point &p) const { return x * 1ll * p.x + y * 1ll * p.y; }
    long long operator^(const point &p) const { return x * 1ll * p.y - y * 1ll * p.x; }
    bool operator<(const point &p) const { return x == p.x ? y < p.y : x < p.x; }
    long long operator()() const { return x * 1ll * x + y * 1ll * y; }
    double len() const { return hypot(x, y); }
};

long long cross(point o, point a, point b) {
    return (a - o) ^ (b - o);
}

vector<point> convex(vector<point> p) {
    vector<point> ch;
    sort(p.begin(), p.end());
    for (int i = 0; i < p.size(); ++i) {
        while (ch.size() >= 2 && cross(ch[ch.size() - 2], ch[ch.size() - 1], p[i]) <= 0) ch.pop_back();
        ch.push_back(p[i]);
    }
    int m = ch.size();
    for (int i = p.size() - 2; i >= 0; --i) {
        while (ch.size() >= m + 1 && cross(ch[ch.size() - 2], ch[ch.size() - 1], p[i]) <= 0) ch.pop_back();
        ch.push_back(p[i]);
    }
    return ch;
}

bool equal(pair<long long, double> a, pair<long long, double> b) {
    return a.first == b.first && fabs(a.second - b.second) < 1e-9;
}

bool match(const vector<pair<long long, double>> &a, const vector<pair<long long, double>> &b) {
    vector<int> f(a.size());
    f[0] = -1, f[1] = 0;
    for (int i = 1, j = 0; i < b.size() - 1; f[++i] = ++j) {
        if (equal(b[i], b[j])) f[i] = f[j];
        while (j != -1 && !equal(b[i], b[j])) j = f[j];
    }
    for (int i = 0, j = 0; i - j + b.size() <= a.size(); ++i, ++j) {
        while (j != -1 && !equal(a[i], b[j])) j = f[j];
        if (j == b.size() - 1) return true;
    }
    return false;
}

bool check(const vector<point> &a, const vector<point> &b) {
    if (a.size() != b.size()) return false;
    int n = a.size() - 1;
    vector<pair<long long, double>> va(n), vb(n);
    for (int i = 0; i < n; ++i) {
        long long l = (a[i] - a[i + 1]) * (a[i] - a[i + 1]);
        point x = a[i] - a[i + 1], y = a[i + 1] - a[(i + 2) % n];
        double ang = 1.0 * (x * y) / x.len() / y.len();
        va[i] = make_pair(l, ang);
    } 
    for (int i = 0; i < n; ++i) {
        long long l = (b[i] - b[i + 1]) * (b[i] - b[i + 1]);
        point x = b[i] - b[i + 1], y = b[i + 1] - b[(i + 2) % n];
        double ang = 1.0 * (x * y) / x.len() / y.len();
        vb[i] = make_pair(l, ang);
    } 
    for (int i = 0; i < n; ++i) va.push_back(va[i]);
    return match(va, vb);
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    vector<point> a, b;
    for (int i = 0; i < n; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        a.emplace_back(x, y);
    }
    for (int i = 0; i < m; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        b.emplace_back(x, y);
    }
    a = convex(a), b = convex(b);
    bool ans = check(a, b);
    if (ans) puts("YES");
    else puts("NO");
    return 0;
}