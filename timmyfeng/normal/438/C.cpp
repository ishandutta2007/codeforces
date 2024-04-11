#include <bits/stdc++.h>
using namespace std;

using point = complex<long long>;
#define X real()
#define Y imag()

const int N = 200, M = 1000000007;

int ways[N][N];
point p[N];

long long cross(point a, point b) {
    return a.X * b.Y - a.Y * b.X;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        p[i] = point(x, y);
    }

    long long area = 0;
    for (int i = 0; i < n; ++i) {
        area += cross(p[i], p[(i + 1) % n]);
    }

    if (area < 0) {
        reverse(p, p + n);
    }

    for (int i = n - 2; i >= 0; --i) {
        ways[i][i + 1] = 1;
        for (int j = i + 2; j < n; ++j) {
            for (int k = i + 1; k < j; ++k) {
                if (cross(p[i], p[k]) + cross(p[k], p[j]) + cross(p[j], p[i]) > 0) {
                    ways[i][j] = (ways[i][j] + (long long) ways[i][k] * ways[k][j]) % M;
                }
            }
        }
    }

    cout << ways[0][n - 1] << "\n";
}