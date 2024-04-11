#include <iostream>
#define int long long 

using namespace std;

struct point{
    int x, y;
    point() {}
    point(int x, int y): x(x), y(y) {}
    void init() {
        cin >> x >> y;
    }
};

int len(point a, point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

const int INF = 3e16, N = 107;
int dst[N][N];
point p[N];
int ax, ay, bx, by, t;

int init() {
    int n = 1;
    while (1) {
        p[n] = point(p[n - 1].x * ax + bx, p[n - 1].y * ay + by);
        if (p[n].x > INF || p[n].y > INF) break;
        n++;
    }
    return n;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    p[0].init(); 
    cin >> ax >> ay >> bx >> by;
    point s;
    s.init();
    cin >> t;
    int n = init();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            dst[i][j] = INF;
        }
        dst[i][0] = 0;
        for (int l = 0; l <= i; l++) {
            for (int r = i; r < n; r++) {
                dst[i][i - l + 1] = min(dst[i][i - l + 1], len(p[i], p[l]));
                dst[i][r - i + 1] = min(dst[i][r - i + 1], len(p[i], p[r]));
                dst[i][r - l + 1] = min(dst[i][r - l + 1], len(p[i], p[l]) + len(p[i], p[r]) + min(len(p[i], p[l]), len(p[i], p[r])));
            }
        }
    }
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int curt = t - len(s, p[i]);
        if (curt < 0) continue;
        for (int j = 1; j <= n; j++) {
            if (dst[i][j] <= curt) maxi = max(maxi, j);
        }
    }
    cout << maxi << endl;
    return 0;
    return 0;
}