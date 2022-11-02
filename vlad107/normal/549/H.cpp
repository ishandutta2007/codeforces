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

using namespace std;

const double EPS = 1e-11;

pair<long double, long double> get(long double l1, long double r1, long double l2, long double r2) {
    return make_pair(min(min(l1*l2, l1*r2), min(r1*l2, r1*r2)),
                     max(max(l1*l2, l1*r2), max(r1*l2, r1*r2)));
}

bool ok(long double l, long double r, long double x) {
    return (l <= x) && (x <= r);
} 

int main() {
    // freopen("input.txt", "r", stdin);
    long double a, b, c, d;
    cin >> a >> b >> c >> d;
    long double l = 0, r = 1e18;
    for (int it = 0; it < 10000; it++) {
        long double mid = (l + r) * 0.5;
        pair<long double, long double> u = get(a - mid, a + mid, d - mid, d + mid);
        pair<long double, long double> v = get(b - mid, b + mid, c - mid, c + mid);
        if (ok(u.first, u.second, v.first) || ok(u.first, u.second, v.second) || 
            ok(v.first, v.second, u.first) || ok(v.first, v.second, u.second)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf("%.12lf\n",(double)l);
}