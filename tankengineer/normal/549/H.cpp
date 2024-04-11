#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

long double a, b, c, d;

pair<long double, long double> cal(long double l1, long double r1, long double l2, long double r2) {
    long double m1 = l1 * l2, m2 = l1 * r2, m3 = r1 * l2, m4 = r1 * r2;
    return make_pair(min(min(m1, m2), min(m3, m4)), max(max(m1, m2), max(m3, m4)));
}

bool intersect(pair<long double, long double> p1, pair<long double, long double> p2) {
    return max(p1.first, p2.first) < min(p1.second, p2.second);
}

bool check(long double bar) {
    long double la = a - bar, ra = a + bar,
           lb = b - bar, rb = b + bar,
           lc = c - bar, rc = c + bar,
           ld = d - bar, rd = d + bar;
    return intersect(cal(la, ra, ld, rd), cal(lb, rb, lc, rc));
}

int main() {
    cin >> a >> b >> c >> d;
    long double l = 0, r = 1e10;
    for (int i = 0; i < 100; ++i) {
        long double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.10f\n", (double)l);
    return 0;
}