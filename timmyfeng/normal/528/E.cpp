#include <bits/stdc++.h>
using namespace std;

using point = complex<double>;
#define X real()
#define Y imag()

double cross(point a, point b) {
    return a.X * b.Y - a.Y * b.X;
}

const int N = 3000;

pair<point, double> line[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(4);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        point v = point(-b, a);
        if (v.Y < 0 || (v.Y == 0 && v.X < 0)) {
            v *= -1.0, c *= -1.0;
        }

        line[i] = {v, c};
    }

    sort(line, line + n, [&](pair<point, double> a, pair<point, double> b) {
        return cross(a.first, b.first) > 0;
    });

    double ans = 0.0;
    for (int i = 0; i < n; ++i) {
        auto [vi, ci] = line[i];
        point sum;
        for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
            auto [vj, cj] = line[j];
            point p = (vi * cj - vj * ci) / cross(vi, vj);
            ans += cross(sum, p);
            sum += p;
        }
    }

    ans /= (double) n * (n - 1) * (n - 2) / 3;

    cout << ans << "\n";
}