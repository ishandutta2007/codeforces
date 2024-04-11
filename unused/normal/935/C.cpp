#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;

    if (r * r <= (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
        printf("%lld %lld %lld\n", x1, y1, r);
    else if (x1 == x2 && y1 == y2)
        printf("%.9f %.9f %.9f\n", x1 + r * 0.5, (double)y1, r * 0.5);
    else
    {
        double d1 = x1 - x2, d2 = y1 - y2, len = hypot(d1, d2);
        d1 = d1 / len;
        d2 = d2 / len;

        double c1 = x2 + d1 * (len + r) * 0.5, c2 = y2 + d2 * (len + r) * 0.5;

        printf("%.9f %.9f %.9f\n", c1, c2, (len + r) * 0.5);
    }
}