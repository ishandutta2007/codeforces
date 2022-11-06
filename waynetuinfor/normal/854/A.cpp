#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    double ans = 0.0;
    int ansa = -1, ansb = -1;
    for (int a = 1; a <= n; ++a) {
        int b = n - a;
        if (__gcd(a, b) != 1) continue;
        if (a > b) continue;
        double t = (double)a / (double)b;
        if (t > ans) ans = t, ansa = a, ansb = b;
    }
    cout << ansa << ' ' << ansb  << endl;
}