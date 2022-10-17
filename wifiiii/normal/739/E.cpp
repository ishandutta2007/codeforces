#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define double long double
const double eps = 1e-12;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    vector<vector<double>> a(2, vector<double>(n));
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int cnt1, cnt2; double dp;
    auto chk = [&](double m1, double m2) {
        cnt1 = 0, cnt2 = 0, dp = 0;
        for(int k = 0; k < n; ++k) {
            double best = 0; int mask = 0;
            if(a[0][k] - m1 > best + eps) {
                // use 0
                best = a[0][k] - m1;
                mask = 1;
            }
            if(a[1][k] - m2 > best + eps) {
                // use 1
                best = a[1][k] - m2;
                mask = 2;
            }
            if(a[0][k] + a[1][k] - a[0][k] * a[1][k] - m1 - m2 > best + eps) {
                // use both
                best = a[0][k] + a[1][k] - a[0][k] * a[1][k] - m1 - m2;
                mask = 3;
            }
            if(mask >> 0 & 1) cnt1++;
            if(mask >> 1 & 1) cnt2++;
            dp += best;
        }
    };
    double lo = 0, hi = 1, ans = 0, m1, m2;
    for(int i = 0; i < 90; ++i) {
        double mid = (lo + hi) / 2;
        double lo2 = 0, hi2 = 1;
        for(int j = 0; j < 90; ++j) {
            double mid2 = (lo2 + hi2) / 2;
            chk(mid, mid2);
            if(cnt2 >= y) lo2 = mid2;
            else hi2 = mid2;
        }
        chk(mid, lo2);
        if(cnt1 >= x) lo = mid;
        else hi = mid;
        m1 = mid, m2 = lo2;
    }
    chk(lo, m2);
    cout << fixed << setprecision(3) << dp + x * m1 + y * m2 << '\n';
}