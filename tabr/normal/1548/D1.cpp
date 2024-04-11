#include <bits/stdc++.h>
using namespace std;
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
bool cmp_cord(point a, point b) {
    return (a.x == b.x ? a.y < b.y : a.x < b.x);
}
bool cmp_arg(point a, point b) {
    int ac = (a.y < 0 ? -1 : (a.y == 0 && a.x >= 0 ? 0 : 1));
    int bc = (b.y < 0 ? -1 : (b.y == 0 && b.x >= 0 ? 0 : 1));
    return (ac == bc ? a.x * b.y - a.y * b.x > 0 : ac < bc);
}
// bool operator<(point a, point b) {
//     return cmp_cord(a, b);
//     return cmp_arg(a, b);
// }
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
long double norm(point a) {
    return sqrtl(dot(a, a));
}
long double arg(point a) {
    return atan2l(a.y, a.x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    // vector<vector<int>> a(2, vector<int>(2));
    vector<int> a(4);
    for (int i = 0; i < n; i++) {
        a[p[i].x % 4 + p[i].y % 4 / 2]++;
    }
    long long ans = 0;
    vector<point> q(4);
    q[0] = point(0, 0);
    q[1] = point(0, 2);
    q[2] = point(2, 0);
    q[3] = point(2, 2);
    vector<vector<int>> b(4, vector<int>(4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            point r = q[i] - q[j];
            int dx = (int) abs(r.x);
            int dy = (int) abs(r.y);
            b[i][j] = (__gcd(dx, dy) + 3) % 4;
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            for (int k = j; k < 4; k++) {
                long long t = -1;
                if (i == k) {
                    t = 1LL * a[i] * (a[i] - 1) * (a[i] - 2) / 6;
                } else if (i == j) {
                    t = 1LL * a[i] * (a[i] - 1) / 2 * a[k];
                } else if (j == k) {
                    t = 1LL * a[j] * (a[j] - 1) / 2 * a[i];
                } else {
                    t = 1LL * a[i] * a[j] * a[k];
                }
                int c = b[i][j] + b[j][k] + b[k][i];
                if (c % 4 == 1) {
                    ans += t;
                }
            }
        }
    }
    cout << ans << '\n';
    /*
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            point q = p[i] - p[j];
            int dx = (int) abs(q.x);
            int dy = (int) abs(q.y);
            a[i][j] = a[j][i] = (__gcd(dx, dy) + 3) % 4;
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if ((a[i][j] + a[j][k] + a[k][i]) % 4 == 1) {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
    */
    return 0;
}