#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

const long double eps = 1e-12L;
const long double pi = acosl(-1);

struct point {
    long double x;
    long double y;
    point(long double _x = 0, long double _y = 0) : x(_x), y(_y) {}
    point &operator+=(point other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    point &operator-=(point other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    point &operator*=(long double other) {
        x *= other;
        y *= other;
        return *this;
    }
    point &operator/=(long double other) {
        x /= other;
        y /= other;
        return *this;
    }
    point operator-() { return point(*this) *= -1; }
    point operator+(point rhs) { return point(*this) += rhs; }
    point operator-(point rhs) { return point(*this) -= rhs; }
    point operator*(long double rhs) { return point(*this) *= rhs; }
    point operator/(long double rhs) { return point(*this) /= rhs; }
    bool operator==(point rhs) { return (abs(x - rhs.x) < eps && abs(y - rhs.y) < eps); }
    bool operator!=(point rhs) { return (abs(x - rhs.x) > eps || abs(y - rhs.y) > eps); }
};
// bool operator<(point a, point b) {
//     return (abs(a.x - b.x) < eps ? a.y < b.y : a.x < b.x);
//     return (atan2l(a.y, a.x) < atan2l(b.y, b.x));
// }
string to_string(point a) {
    return "(" + to_string(a.x) + ", " + to_string(a.y) + ")";
}
long double dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}
long double cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}
long double dist2(point a, point b) {
    return dot(a - b, a - b);
}
long double dist(point a, point b) {
    return sqrtl(dist2(a, b));
}
long double norm(point a) {
    return sqrtl(dot(a, a));
}
long double arg(point a) {
    return atan2l(a.y, a.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<point> p;
    for (int i = 0; i < n; i++) {
        point q;
        cin >> q.x >> q.y;
        if (abs(q.x) < eps && abs(q.y) < eps) {
            k--;
        } else {
            p.emplace_back(q);
        }
    }
    n = (int) p.size();
    if (k <= 0) {
        cout << 0 << '\n';
        return 0;
    }
    long double lo = 0, hi = 2e5;
    while (hi - lo > 1e-6) {
        long double mid = (hi + lo) / 2;
        vector<long double> add, remove, all;
        int now = 0;
        for (int i = 0; i < n; i++) {
            long double d = norm(p[i]) / 2;
            if (d > mid) {
                continue;
            }
            long double a = sqrtl(mid * mid - d * d);
            long double t = atanl(a / d);
            long double f = atan2l(p[i].y, p[i].x);
            long double beg = f - t;
            long double end = f + t;
            if (beg < -pi) {
                beg += 2 * pi;
            }
            if (end > pi) {
                end -= 2 * pi;
            }
            if (end < beg) {
                now++;
            }
            add.emplace_back(beg);
            remove.emplace_back(end);
            all.emplace_back(beg);
            all.emplace_back(end);
        }
        debug(mid, add, remove);
        sort(add.begin(), add.end());
        sort(remove.begin(), remove.end());
        sort(all.begin(), all.end());
        all.resize(unique(all.begin(), all.end()) - all.begin());
        int ok = 0;
        int it1 = 0, it2 = 0;
        if (now >= k) {
            ok = 1;
        }
        for (auto v : all) {
            while (it1 < (int) add.size() && abs(add[it1] - v) < eps) {
                now++;
                it1++;
            }
            while (it2 < (int) remove.size() && abs(remove[it2] - v) < eps) {
                now--;
                it2++;
            }
            if (now >= k) {
                ok = 1;
            }
        }
        if (ok) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << fixed << setprecision(12);
    cout << hi << '\n';
    return 0;
}