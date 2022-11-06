#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int inf = 1e9;
const int dx[9] = { 1, 0, -1, 0, 1, 1, -1, -1, 0 };
const int dy[9] = { 0, 1, 0, -1, 1, -1, 1, -1, 0 };
int ax[maxn], ay[maxn], bx[maxn], by[maxn];

struct point {
    int x, y;
    point(int x = 0, int y = 0): x(x), y(y) {}
    point operator+(const point &p) const { return point(x + p.x, y + p.y); }
    point operator-(const point &p) const { return point(x - p.x, y - p.y); }
    long long operator*(const point &p) const { return x * 1ll * p.x + y * 1ll * p.y; }
    long long operator^(const point &p) const { return x * 1ll * p.y - y * 1ll * p.x; }
    bool operator==(const point &p) const { return x == p.x && y == p.y; }
    bool operator<(const point &p) const { return x == p.x ? y < p.y : x < p.x; }
};

int sgn(long long x) {
    if (x == 0) return 0;
    if (x > 0) return 1;
    return -1;
}

bool on(point a, point b, point p) {
    if (a.x == b.x) {
        if (p.x != a.x) return false;
        if (p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y)) return true;
        return false;
    }
    if (((p - a) ^ (p - b)) != 0) return false;
    if (((p - a) ^ (b - a)) != 0) return false;
    if (p.x < min(a.x, b.x) || p.x > max(a.x, b.x)) return false;
    return true;
}

bool on(int i, int x, int y) {
    return on(point(ax[i], ay[i]), point(bx[i], by[i]), point(x, y));
}

bool have(point a, point b, point p, point q) {
    if (((a - b) ^ (p - q)) == 0) return false;
    if (on(a, b, p) || on(a, b, q) || on(p, q, a) || on(p, q, b)) return true;
    point pb = p - b, qb = q - b;
    point pa = p - a, qa = q - a;
    point bp = b - p, ap = a - p;
    point bq = b - q, aq = a - q;
    if (sgn(pb ^ qb) == sgn(pa ^ qa)) return false;
    if (sgn(bp ^ ap) == sgn(bq ^ aq)) return false;
    return true;
}

bool have(int i, int j) {
    return have(point(ax[i], ay[i]), point(bx[i], by[i]),
                point(ax[j], ay[j]), point(bx[j], by[j]));
}

point inter(int i, int j) {
    if (point(ax[i], ay[i]) == point(ax[j], ay[j])) return point(ax[i], ay[i]);
    if (point(ax[i], ay[i]) == point(bx[j], by[j])) return point(ax[i], ay[i]);
    if (point(bx[i], by[i]) == point(ax[j], ay[j])) return point(bx[i], by[i]);
    if (point(bx[i], by[i]) == point(bx[j], by[j])) return point(bx[i], by[i]);
    if (ax[i] == bx[i] && ax[j] == bx[j]) return point(inf, inf);
    if (!have(i, j)) return point(inf, inf);
    double mi = (by[i] - ay[i]) * 1.0 / (bx[i] - ax[i]);
    double mj = (by[j] - ay[j]) * 1.0 / (bx[j] - ax[j]);
    double ki = by[i] - mi * bx[i];
    double kj = by[j] - mj * bx[j];
    if (ax[i] == bx[i]) {
        double x = ax[i];
        double y = mj * x + kj;
        int xf = floor(x), xc = ceil(x);
        int yf = floor(y), yc = ceil(y);
        for (int k = 0; k < 9; ++k) {
            int tx = xf + dx[k];
            int ty = yf + dy[k];
            if (on(i, tx, ty) && on(j, tx, ty)) return point(tx, ty);
            tx = xc + dx[k];
            ty = yc + dy[k];
            if (on(i, tx, ty) && on(j, tx, ty)) return point(tx, ty);
        }
        return point(inf, inf);
    }
    if (ax[j] == bx[j]) {
        double x = ax[j];
        double y = mi * x + ki;
        int xf = floor(x), xc = ceil(x);
        int yf = floor(y), yc = ceil(y);
        for (int k = 0; k < 9; ++k) {
            int tx = xf + dx[k];
            int ty = yf + dy[k];
            if (on(i, tx, ty) && on(j, tx, ty)) return point(tx, ty);
            tx = xc + dx[k];
            ty = yc + dy[k];
            if (on(i, tx, ty) && on(j, tx, ty)) return point(tx, ty);
        }
        return point(inf, inf);
    }
    double x = (kj - ki) / (mi - mj);
    double y = mi * x + ki;
    int xf = floor(x), xc = ceil(x);
    int yf = floor(y), yc = ceil(y);
    for (int k = 0; k < 9; ++k) {
        int tx = xf + dx[k];
        int ty = yf + dy[k];
        if (on(i, tx, ty) && on(j, tx, ty)) return point(tx, ty);
        tx = xc + dx[k];
        ty = yc + dy[k];
        if (on(i, tx, ty) && on(j, tx, ty)) return point(tx, ty);
    }
    return point(inf, inf);
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ax[i] >> ay[i] >> bx[i] >> by[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int dx = abs(ax[i] - bx[i]);
        int dy = abs(ay[i] - by[i]);
        int g = __gcd(dx, dy);
        ans += g + 1;
    }
    set<point> all;
    for (int i = 0; i < n; ++i) {
        set<point> s;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            point p = inter(i, j);
            if (p.x == inf) continue;
            s.insert(p);
            all.insert(p);
        } 
        ans -= s.size();
    }
    ans += all.size();
    cout << ans << endl;
}