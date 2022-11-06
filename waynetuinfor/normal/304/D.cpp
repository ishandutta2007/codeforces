#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x, y, a, b; cin >> n >> m >> x >> y >> a >> b;
    int g = __gcd(a, b); a /= g; b /= g;
    int mul = min(n / a, m / b); a *= mul; b *= mul;
    int cx = x, cy = y, la = a - a / 2, ra = a / 2, ub = b / 2, lb = b - b / 2;
    if (n - x < ra) cx = x - (ra - (n - x));
    else if (x < la) cx = la;
    if (cx - la < 0 || cx + ra > n) swap(la, ra), cx = x;
    if (n - x < ra) cx = x - (ra - (n - x));
    else if (x < la) cx = la;
    if (m - y < ub) cy = y - (ub - (m - y));
    else if (y < lb) cy = lb;
    if (cy - lb < 0 || cy + ub > m) swap(lb, ub), cy = y;
    if (m - y < ub) cy = y - (ub - (m - y));
    else if (y < lb) cy = lb;
    cout << cx - la << ' ' << cy - lb << ' ' << cx + ra << ' ' << cy + ub << endl;
    return 0;
}