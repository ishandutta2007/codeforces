#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

const double eps = 1e-12;
const double pi = acos(-1);

template <typename T>
struct Tpoint {
    T x;
    T y;
    Tpoint(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    Tpoint &operator+=(Tpoint other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    Tpoint &operator-=(Tpoint other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    Tpoint &operator*=(T other) {
        x *= other;
        y *= other;
        return *this;
    }
    Tpoint &operator/=(T other) {
        x /= other;
        y /= other;
        return *this;
    }
    Tpoint operator-() { return Tpoint(*this) *= -1; }
    Tpoint operator+(Tpoint rhs) { return Tpoint(*this) += rhs; }
    Tpoint operator-(Tpoint rhs) { return Tpoint(*this) -= rhs; }
    Tpoint operator*(T rhs) { return Tpoint(*this) *= rhs; }
    Tpoint operator/(T rhs) { return Tpoint(*this) /= rhs; }
    bool operator==(Tpoint rhs) { return (abs(x - rhs.x) < eps && abs(y - rhs.y) < eps); }
    bool operator!=(Tpoint rhs) { return (abs(x - rhs.x) > eps || abs(y - rhs.y) > eps); }
};
// template <typename T>
// bool operator<(Tpoint<T> a, Tpoint<T> b) {
//     return (abs(a.x - b.x) < eps ? a.y < b.y : a.x < b.x);
//     return (atan2l(a.y, a.x) < atan2l(b.y, b.x));
// }
template <typename T>
string to_string(Tpoint<T> a) {
    return "(" + to_string(a.x) + ", " + to_string(a.y) + ")";
}
template <typename T>
T dot(Tpoint<T> a, Tpoint<T> b) {
    return a.x * b.x + a.y * b.y;
}
template <typename T>
T cross(Tpoint<T> a, Tpoint<T> b) {
    return a.x * b.y - a.y * b.x;
}
template <typename T>
T dist2(Tpoint<T> a, Tpoint<T> b) {
    return dot(a - b, a - b);
}
template <typename T>
double dist(Tpoint<T> a, Tpoint<T> b) {
    return sqrt(dist2(a, b));
}
template <typename T>
double norm(Tpoint<T> a) {
    return sqrt(dot(a, a));
}
template <typename T>
double arg(Tpoint<T> a) {
    return atan2(a.y, a.x);
}

// using point = Tpoint<long long>;
using point = Tpoint<double>;

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

int rand_int(int a, int b) {  // [a, b]
    return uniform_int_distribution<int>(a, b)(rng);
}

double rand_real(double a, double b) {
    return uniform_real_distribution<double>(a, b)(rng);
}

point intersect(point a, point b, point c, point d) {
    double num = (c.x - a.x) * (d.y - c.y) - (c.y - a.y) * (d.x - c.x);
    double den = (b.x - a.x) * (d.y - c.y) - (b.y - a.y) * (d.x - c.x);
    if (abs(den) < eps) {
        assert(false);
        return point(1e19, 1e19);
    }
    point e = a + (b - a) * num / den;
    return e;
}

point rotate(point a, double theta, point center = point(0, 0)) {
    a -= center;
    return point(a.x * cos(theta) - a.y * sin(theta), a.x * sin(theta) + a.y * cos(theta)) + center;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<point> p(3);
    for (int i = 0; i < 3; i++) {
        cin >> p[i].x >> p[i].y;
    }
    auto Check = [&](point a, point b) {
        a /= norm(a);
        b /= norm(b);
        return (dot(a, b) < -0.5);
    };
    auto GetOne = [&](point a, point b, point c) {
        point d;
        if (Check(b - a, c - a)) {
            d = a;
        } else if (Check(a - b, c - b)) {
            d = b;
        } else if (Check(a - c, b - c)) {
            d = c;
        } else {
            point bx = rotate(b, pi / 3, a);
            point by = rotate(b, -pi / 3, a);
            point cx = rotate(c, pi / 3, a);
            point cy = rotate(c, -pi / 3, a);
            if (dist(b, cx) < dist(b, cy)) {
                swap(cx, cy);
            }
            if (dist(c, bx) < dist(c, by)) {
                swap(bx, by);
            }
            d = intersect(cx, b, bx, c);
        }
        return dist(a, d) + dist(b, d) + dist(c, d);
    };
    auto Get = [&](point q) {
        return max({GetOne(q, p[0], p[1]), GetOne(q, p[1], p[2]), GetOne(q, p[2], p[0])});
    };
    point q = (p[0] + p[1] + p[2]) / 3;
    double best = Get(q);
    for (double c : {1.0, 0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001}) {
        for (int it = 0; it < 100000; it++) {
            double t = rand_real(0, 6.283184);
            point nq = q + point(cos(t), sin(t)) * c;
            t = Get(nq);
            if (t < best) {
                best = t;
                q = nq;
            }
        }
    }
    cout << fixed << setprecision(12);
    cout << Get(q) << '\n';
    return 0;
}