#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 205, MOD = 1000000007;
int n;
int x[N], y[N];

int cross(int x1, int y1, int x2, int y2) {
    long long t = (long long)x1 * y2 - (long long)x2 * y1;
    if (t < 0) {
        return -1;
    } else if (t == 0) {
        return 0;
    } else {
        return 1;
    }
}

bool intersect(int x0, int y0, int x1, int y1, int x2, int y2, int x3, int y3) {
    if (cross(x2 - x0, y2 - y0, x1 - x0, y1 - y0) *
        cross(x3 - x0, y3 - y0, x1 - x0, y1 - y0) == -1 &&
        cross(x1 - x2, y1 - y2, x3 - x2, y3 - y2) *
        cross(x0 - x2, y0 - y2, x3 - x2, y3 - y2) == -1) {
        return true;
    }
    return false;
}

bool g[N][N];
bool vis[N][N];

int f[N][N];

int dp(int i, int j) {
    if (vis[i][j]) {
        return f[i][j];
    }
    vis[i][j] = true;
    if (i < j) {
        if (i + 1 == j) {
            f[i][j] = 1;
        } else {
            for (int k = i + 1; k < j; ++k) {
                if (g[i][k] && g[j][k]) {
                    (f[i][j] += (long long)dp(i, k) * dp(k, j) % MOD) %= MOD;
                }
            }
        }
    } else {
        if (i + 1 == j + n) {
            f[i][j] = 1;
        } else {
            for (int kp = i + 1; kp < j + n; ++kp) {
                int k = kp % n;
                if (g[i][k] && g[j][k]) {
                    (f[i][j] += (long long)dp(i, k) * dp(k, j) % MOD) %= MOD;
                }
            }
        }
    }
    return f[i][j];
}

int inv(int a) {
    return a == 1 ? 1 : (long long)(MOD - MOD / a) * inv(MOD % a) % MOD;
}

int dot(int x, int y, int x1, int y1) {
    int t = x * x1 + y * y1;
    if (t < 0) {
        return -1;
    } else if (t == 0) {
        return 0;
    } else {
        return 1;
    }
}

bool online(int x, int y, int x0, int y0, int x1, int y1) {
    int dx = x1 - x0, dy = y1 - y0;
    if (cross(x - x0, y - y0, dx, dy) != 0) {
        return false;
    }
    return dot(x - x0, y - y0, x - x1, y - y1) == -1;
}

struct Point {
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}

    double Length() {
        return sqrt(x * x + y * y);
    }
};

Point operator - (Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}

int Sign(double x, double eps = 1e-9) {
    return x < -eps ? -1 : x > eps;
}

double Det(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

double Dist(Point a, Point b, Point c) {
    return abs(Det(a - c, b - c) / (a - b).Length());
}

double Dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

bool In_The_Seg(Point a, Point b, Point c) {
    if (Sign(Dist(a, b, c))) {
        return 0;
    }
    return Sign(Dot(a - c, b - c)) <= 0;
}

bool contain(double x, double y) {
    Point A, B, P = Point(x, y);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        A = Point(::x[i], ::y[i]), B = Point(::x[i + 1], ::y[i + 1]);
        if (In_The_Seg(A, B, P)) {
            return 1;
        }
        if (Sign(A.y - B.y) <= 0) {
            swap(A, B);
        }
        if (Sign(P.y - A.y) > 0) {
            continue;
        }
        if (Sign(P.y - B.y) <= 0) {
            continue;
        }
        res += Sign(Det(B - P, A - P)) > 0;
    }
    return res & 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", x + i, y + i);
    }
    x[n] = x[0], y[n] = y[0];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (j == i + 1 || i == 0 && j == n - 1) {
                g[i][j] = g[j][i] = true;
                continue;
            }
            bool flag = true;
            for (int k = 0; k < n; ++k) {
                if (intersect(x[i], y[i], x[j], y[j], x[k], y[k], x[k + 1], y[k + 1])) {
                    flag = false;
                }
                if (k != i && k != j && online(x[k], y[k], x[i], y[i], x[j], y[j])) {
                    flag = false;
                }
            }
            if (flag) {
                double xx = (double)(x[i] + x[j]) / 2,
                       yy = (double)(y[i] + y[j]) / 2;
                if (contain(xx, yy)) {
                    g[j][i] = g[i][j] = true;
                }
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (!g[i][j]) {
                continue;
            }
            for (int k = j + 1; k < n; ++k) {
                if (!g[i][k] || !g[j][k]) {
                    continue;
                }
                (ans += (long long)dp(i, j) * dp(j, k) % MOD * dp(k, i) % MOD) %= MOD;
            }
        }
    }
    printf("%d\n", (int)((long long)ans * inv(n - 2) % MOD));
    return 0;
}