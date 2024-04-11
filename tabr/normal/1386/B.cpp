#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

struct point {
    long long x;
    long long y;
    point(long long _x = 0LL, long long _y = 0LL) : x(_x), y(_y) {}
    void norm() {
        long long g = __gcd(abs(x), abs(y));
        if (g != 0LL) {
            x /= g;
            y /= g;
        }
    }
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
    point &operator*=(long long other) {
        x *= other;
        y *= other;
        return *this;
    }
    point operator-() { return point(*this) *= -1LL; }
    point operator+(point rhs) { return point(*this) += rhs; }
    point operator-(point rhs) { return point(*this) -= rhs; }
    point operator*(long long rhs) { return point(*this) *= rhs; }
    bool operator==(point rhs) { return (x == rhs.x && y == rhs.y); }
    bool operator!=(point rhs) { return (x != rhs.x || y != rhs.y); }
};
bool operator<(point a, point b) {
    // return (a.x == b.x ? a.y < b.y : a.x < b.x);
    return (atan2l(a.x, a.y) < atan2l(b.x, b.y));
}
string to_string(point a) {
    return "(" + to_string(a.x) + ", " + to_string(a.y) + ")";
}
long long dot(point a, point b) {
    return a.x * b.x + a.y * b.y;
}
long long cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}
long long dist2(point a, point b) {
    return dot(a - b, a - b);
}
long double arg(point a) {
    return atan2l(a.x, a.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<ll> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    int n;
    cin >> n;
    vector<point> v;
    multiset<point> st;
    int same = 0;
    ll d = 0;
    long double pi = acosl(-1);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'A') {
            vector<ll> t(3);
            for (int i = 0; i < 3; i++) {
                cin >> t[i];
            }
            point p((a[1] + a[2]) * t[0] - (t[1] + t[2]) * a[0], (a[0] + a[2]) * t[1] - (t[0] + t[2]) * a[1]);
            p.norm();
            v.emplace_back(p);
            if (p == point()) {
                same++;
            } else {
                st.emplace(p);
                d += st.count(-p);
            }
        } else {
            int r;
            cin >> r;
            r--;
            if (v[r] == point()) {
                same--;
            } else {
                d -= st.count(-v[r]);
                st.erase(st.find(v[r]));
            }
        }
        if (same) {
            cout << 1 << '\n';
        } else if (d) {
            cout << 2 << '\n';
        } else {
            if (st.empty()) {
                cout << 0 << '\n';
                continue;
            }
            point p = *st.rbegin(), q = *st.begin();
            if (arg(q) - arg(p) + pi > 0) {
                cout << 0 << '\n';
                continue;
            }
            p = *st.lower_bound(point());
            q = *prev(st.lower_bound(point()));
            if (arg(p) - arg(q) > pi) {
                cout << 0 << '\n';
                continue;
            }
            cout << 3 << '\n';
        }
    }
    return 0;
}