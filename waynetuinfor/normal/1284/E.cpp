#include <bits/stdc++.h>
using namespace std;

const int kN = 3000;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    long long operator*(const Point &p) const { return 1LL * x * p.x + 1LL * y * p.y; }
    long long operator%(const Point &p) const { return 1LL * x * p.y - 1LL * y * p.x; }

    bool operator<(const Point &p) const {
        int a = y < 0, b = p.y < 0;
        if (a != b) return a < b;
        return (*this) % p > 0;
    }
};

Point p[kN];

long long Solve(vector<Point> v, int n) {
    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; ++i) v.push_back(v[i]);
    long long ans = 1LL * (n - 1) * (n - 2) * (n - 3) / 6;
    for (int i = 0, j = 0; i < n - 1; ++i) {
        j = max(j, i + 1);
        while (j < i + n - 1 && v[i] % v[j] > 0) ++j;
        ans -= 1LL * (j - i - 1) * (j - i - 2) / 2;
    }
    return ans;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d%d", &p[i].x, &p[i].y);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<Point> v;
        for (int j = 0; j < n; ++j) {
            if (i != j) v.push_back(p[j] - p[i]);
        }
        ans += Solve(v, n);
    }
    printf("%lld\n", ans * (n - 4) / 2);
    return 0;
}