#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, t;
    double p;
    cin >> n >> p >> t;
    double ans = 0;
    for (int i = 0; i <= t; i++) {
        double x = 1;
        for (int j = 0; j < i; j++) {
            x *= (double) (t - j) / (i - j);
        }
        for (int j = 0; j < i; j++) {
            x *= p;
        }
        for (int j = 0; j < t - i; j++) {
            x *= 1 - p;
        }
        ans += x * min(i, n);
    }
    cout.precision(9);
    cout << fixed << ans << endl;
    return 0;
}