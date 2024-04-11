#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define y1 abacaba

using namespace std;

long long m, h1, a1, x1, y1, h2, a2, x2, y2;

void solve(long long h, long long a, long long x, long long y, long long &u, long long &v) {
    u = v = -1;
    for (int i = 1; i <= 3 * m; i++) {
        h = (h * 1LL * x + y) % m;
        if (h == a) {
            if (u < 0) u = i; else {
                v = i - u;
                return;
            }
        }
    }
}

void go(long long a, long long b, long long c, long long &x, long long &y) {
    //ax - by = c
    if (b == 0) {
        if (abs(c) % abs(a) != 0) {
            puts("-1");
            exit(0);
        }
        x = c / a;
        y = 0;
        return;
    }
    long long x2, y2;
    long long q = a / b;
    go(b, a - b * q, c, x2, y2);
    x = -y2;
    y = -x2 - q * y2;
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> m;
    cin >> h1 >> a1;
    cin >> x1 >> y1;
    cin >> h2 >> a2;
    cin >> x2 >> y2;
    long long u1, v1, u2, v2;
    solve(h1, a1, x1, y1, u1, v1);
    // cerr << u1 << " " << v1 << endl;
    if (u1 < 0) { puts("-1"); return 0;}
    solve(h2, a2, x2, y2, u2, v2); 
    // cerr << u2 << " " << v2 << endl;
    if (u2 < 0) { puts("-1"); return 0;}
    if ((v1 < 0) && (v2 < 0)) {puts("-1"); return 0;}
    if (v1 < 0) {
        swap(v1, v2);
        swap(u1, u2);
    }
    if (v2 < 0) {
        if ((u2 < u1) || ((u2 - u1) % v1 != 0)) u2 = -1;
        cout << u2 << endl;
        return 0;
    }
    long long p, q;
    long long l = __gcd(__gcd(abs(v1), abs(v2)), abs(u2 - u1));
    go(v1 / l, v2 / l, (u2 - u1) / l, p, q);
    // cerr << p << " " << q << endl;
    // cerr << v1 * p - v2 * q << " " << u2 - u1 << endl;
    long long k;
    // cerr << p / v2 << endl;
    // cerr << q / v1 << endl;
    if (p < 0) {
        k = (0 - p + v2 / l - 1) / (v2 / l);
        // p - 1 >= - v2 * x
    } else {
        // p - v2 * x >= 1
        k = -(p - 0) / (v2 / l);
    }
    if (q < 0) {
        k = max(k, (0 - q + (v1 / l) - 1) / (v1 / l));
    } else {
        k = max(k, -(q - 0) / (v1 / l));
    }
    // cerr << k << endl;
    // cerr  << k << endl;
    p += v2 * k / l;
    q += v1 * k / l;
    // cout << p << " " << q << endl;
    // cerr << v1 * p - v2 * q << " " << u2 - u1 << endl;
    cout << v1 * p + u1 << endl;
}

// 0, 3, 4, 1, 0