#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    int t1 = t * (ceil((double)n / (double)k));
    int tend = ceil((double)d / (double)t) * t, td = d;
    int l = n - tend / t * k;
    while (l) {
        td += t; l -= k;
        if (l <= 0) break;
        tend += t; l -= k;
        if (l <= 0) break;
    }
    if (t1 <= max(tend, td)) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}