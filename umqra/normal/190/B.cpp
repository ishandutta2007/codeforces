#include <iostream>
#include <cmath>
using namespace std;
double r(double x1, double y1, double x2, double y2)
{
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double d = r(x1, y1, x2, y2);
    if ( r1 + r2 < d )
        printf("%.10f", (d - r1 - r2) / 2);
    else if ( min(r1, r2) + d >= max(r1, r2) )
        printf("%.10f", 0);
    else
        printf("%.10f", (max(r1, r2) - d - min(r1, r2)) / 2);
    return 0;
}