#include <bits/stdc++.h>
using namespace std;

using point = complex<long long>;
#define X real()
#define Y imag()

long long cross(point a, point b) {
    return a.X * b.Y - a.Y * b.X;
}

long long dot(point a, point b) {
    return a.X * b.X + a.Y * b.Y;
}

vector<array<long long, 2>> read(int n) {
    vector<point> polygon(n);
    for (auto &p : polygon) {
        int x, y;
        cin >> x >> y;
        p = point(x, y);
    }

    sort(polygon.begin(), polygon.end(), [&](point a, point b) {
        if (a.X == b.X) {
            return a.Y < b.Y;
        }
        return a.X < b.X;
    });

    vector<point> hull;
    for (int k = 0; k < 2; ++k) {
        vector<point> half;
        for (auto p : polygon) {
            while (half.size() >= 2) {
                point a = half[half.size() - 2];
                point b = half[half.size() - 1];
                if (cross(b - a, p - b) < 0) {
                    break;
                }
                half.pop_back();
            }
            half.push_back(p);
        }

        hull.insert(hull.end(), half.begin() + 1, half.end());
        reverse(polygon.begin(), polygon.end());
    }

    int m = hull.size();
    vector<array<long long, 2>> s(2 * m);
    for (int i = 0; i < (int) m; ++i) {
        int j = (i + 1) % m, k = (i + 2) % m;
        s[i] = s[i + m] = {
            dot(hull[j] - hull[i], hull[j] - hull[i]),
            dot(hull[j] - hull[i], hull[k] - hull[j])
        };
    }

    int i = 0;
    while (i < (int) s.size()) {
        int j = i + 1, k = i;
        while (j < (int) s.size() && s[j] >= s[k]) {
            if (s[j] > s[k]) {
                k = i;
            } else {
                ++k;
            }
            ++j;
        }

        while (i <= k) {
            if (i < m && i + j - k >= m) {
                return vector<array<long long, 2>>(
                    s.begin() + i, 
                    s.begin() + i + m
                );
            }
            i += j - k;
        }
    }

    return {};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<array<long long, 2>> a = read(n), b = read(m);
    cout << (a == b ? "YES" : "NO") << "\n";
}