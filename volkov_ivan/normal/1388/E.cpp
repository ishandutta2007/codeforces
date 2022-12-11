#include <bits/stdc++.h>

using namespace std;

struct query{
    double c;
    short int p1, p2;
    char bal;
    query() {}
    query(long double c, int p1, int p2, int bal): c(c), p1(p1), p2(p2), bal(bal) {}
};

const long double INF = 1e18, eps = 1e-7;
const int N = 2e3 + 7;
long double v1 = INF, v2 = -INF;
long double xl[N], xr[N], y[N];

bool cmp(query a, query b) {
    if (abs(a.c - b.c) < eps) return (a.bal > b.bal);
    return (a.c < b.c);
}

long double f(pair <long double, long double> v, long double c) {
    return v.first + v.second * c;
}


signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << sizeof(query) << endl;
    //freopen("Desktop/input.txt", "r", stdin);
    cout.precision(20);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int xll, xrr, yy;
        cin >> xll >> xrr >> yy;
        xl[i] = xll;
        xr[i] = xrr;
        y[i] = yy;
    }
    vector <query> all;
    pair <long double, long double> mn(xl[0], y[0]), mx(xl[0], y[0]);
    for (int i = 0; i < n; i++) {
        if (y[i] > mn.second || (y[i] == mn.second && xl[i] < mn.first)) mn = {xl[i], y[i]};
        if (y[i] < mx.second || (y[i] == mx.second && xr[i] > mx.first)) mx = {xr[i], y[i]};
        for (int j = 0; j < n; j++) {
            if (y[i] <= y[j]) continue;
            v2 = (xl[i] - xr[j]) / (y[j] - y[i]);
            v1 = (xr[i] - xl[j]) / (y[j] - y[i]);
            all.push_back(query(v2, 2 * i, 2 * j + 1, 1));
            all.push_back(query(v1, 2 * i + 1, 2 * j, -1));
            v2 = (xl[i] - xl[j]) / (y[j] - y[i]);
            v1 = (xr[i] - xr[j]) / (y[j] - y[i]);
            all.push_back(query(v2, 2 * i, 2 * j, 0));
            all.push_back(query(v1, 2 * i + 1, 2 * j + 1, 0));
        }
    }
    long double best = INF;
    sort(all.begin(), all.end(), cmp);
    if (all.empty()) best = f(mx, 0) - f(mn, 0);
    int cur = n;
    for (auto elem : all) {
        //cout << mn.first << ' ' << mn.second << ' ' << mx.first << ' ' << mx.second << endl;
        int x1 = (elem.p1 % 2 == 0 ? xl[elem.p1 / 2] : xr[elem.p1 / 2]);
        int x2 = (elem.p2 % 2 == 0 ? xl[elem.p2 / 2] : xr[elem.p2 / 2]);
        int y1 = y[elem.p1 / 2], y2 = y[elem.p2 / 2];
        if (cur == n) {
            best = min(best, f(mx, elem.c) - f(mn, elem.c));      
        }
        cur += elem.bal;
        //if (cur > 0) cout << cur << ' ' << elem.c << endl;
        if (abs(f({x1, y1}, elem.c) - f(mn, elem.c)) < eps && f({x1, y1}, elem.c + 10) < f(mn, elem.c + 10)) mn = {x1, y1};
        if (abs(f({x2, y2}, elem.c) - f(mn, elem.c)) < eps && f({x2, y2}, elem.c + 10) < f(mn, elem.c + 10)) mn = {x2, y2};
        if (abs(f({x1, y1}, elem.c) - f(mx, elem.c)) < eps && f({x1, y1}, elem.c + 10) > f(mx, elem.c + 10)) mx = {x1, y1};
        if (abs(f({x2, y2}, elem.c) - f(mx, elem.c)) < eps && f({x2, y2}, elem.c + 10) > f(mx, elem.c + 10)) mx = {x2, y2};
        if (cur == n) {
            best = min(best, f(mx, elem.c) - f(mn, elem.c));      
        }
    }
    cout << fixed << best << endl;
    return 0;
}