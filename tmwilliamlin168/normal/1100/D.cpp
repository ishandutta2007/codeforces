#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

#define PI 3.14159265

using namespace std;

int M = 333;

int kx, ky, rx[1000], ry[1000];

bool read_move() {
    int k, x, y;
    cin >> k >> x >> y;
    if (k == -1 && x == -1 && y == -1) return true;
    if (k == 0 && x == 0 && y == 0) exit(0);
    rx[k] = x;
    ry[k] = y;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    // freopen("a.in", "r", stdin);
    cin >> kx >> ky;
    for (int i = 1; i <= 2*M; i++) {
        cin >> rx[i] >> ry[i];
    }
    int mid = 3*M/2+1;
    while (kx != mid || ky != mid) {
        if (kx > mid) kx--;
        else if (kx < mid) kx++;
        else if (ky > mid) ky--;
        else if (ky < mid) ky++;
        cout << kx << " " << ky << endl;
        if (read_move()) return 0;
    }
    int a11 = 0, a12 = 0, a21 = 0, a22 = 0;
    for (int i = 1; i <= 2*M; i++) {
        if (rx[i] < mid && ry[i] < mid) a11++;
        else if (rx[i] < mid && ry[i] > mid) a12++;
        else if (rx[i] > mid && ry[i] < mid) a21++;
        else if (rx[i] > mid && ry[i] > mid) a22++;
    }
    int mn = min(a11, min(a12, min(a21, a22)));
    int dx, dy;
    if (mn == a11) {
        dx = 1; dy = 1;
    } else if (mn == a12) {
        dx = 1; dy = -1;
    } else if (mn == a21) {
        dx = -1; dy = 1;
    } else if (mn == a22) {
        dx = -1; dy = -1;
    }
    while (true) {
        int dkx = kx+dx, dky = ky+dy;
        bool ok = true;
        for (int i = 1; i <= 2*M; i++) {
            if (rx[i] == dkx && ry[i] == dky) {
                ok = false;
                break;
            }
        }
        if (ok) {
            kx += dx; ky += dy;
        } else {
            kx += dx;
        }
        cout << kx << " " << ky << endl;
        if (read_move()) return 0;
    }
    return 0;
}