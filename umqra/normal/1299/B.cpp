#include <bits/stdc++.h>

using namespace std;

using ll = long long;

struct Point {
    ll x, y;
    Point() : x(), y() {}
    Point(ll _x, ll _y) : x(_x), y(_y) {}
    Point operator - (const Point &a) const {
        return Point(x - a.x, y - a.y);
    }
    ll operator * (const Point &a) const {
        return y * a.x - x * a.y;
    }
    ll length() const {
        return x * x + y * y;
    }
    void scan() {
        scanf("%lld%lld", &x, &y);
    }
    bool operator < (const Point &a) const {
        return x < a.x || (x == a.x && y < a.y);
    }
};

const int N = (int)1e5 + 10;
Point p[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        p[i].scan();
    }
    p[n] = p[0];
    int delta = n / 2;
    for (int i = 0; i < n; i++) {
        auto a = p[i + 1] - p[i];
        auto b = p[(i + delta + 1) % n] - p[(i + delta) % n];
        if (a * b != 0 || a.length() != b.length()) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");

    return 0;
}