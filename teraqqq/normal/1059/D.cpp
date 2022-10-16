#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
const double EPS = 1e-8;

double l, r;
int n, x[N], y[N];
bool area, ok = true;

double get_r(double cx) {
    double r = 0;
    for(int i = 0; i < n; ++i) {
        double dx = cx - x[i]; dx *= dx;
        double dy = abs(y[i]);
        r = max(r, dx/dy+dy);
    }
    return r / 2.0;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        if(i == 0) {
            l = r = x[i];
            area = y[i] > 0;
        }

        if(area != y[i] > 0) {
            cout << -1;
            return 0;
        }

        l = min(l, (double)x[i]);
        r = max(r, (double)x[i]);
    }

    while(r - l > EPS) {
        double m1 = l + (r-l)/3;
        double m2 = r - (r-l)/3;

        if(get_r(m1) > get_r(m2))
            l = m1;
        else
            r = m2;
    }

    cout.precision(9);
    cout << get_r(l);
}