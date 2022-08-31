#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const double eps = 1e-9;
bool eq(double x, double y)
{
    return fabs(x - y) < eps;
}
bool ls(double x, double y)
{
    return x < y && !eq(x, y);
}
bool lseq(double x, double y)
{
    return x < y || eq(x, y);
}

struct Point
{
    double x, y;

    Point() : x(), y() {}
    Point(double _x, double _y) : x(_x), y(_y) {}
    
    void scan()
    {
        scanf("%lf%lf", &x, &y);
    }

    Point operator - (const Point &a) const
    {
        return Point(x - a.x, y - a.y);
    }
    double operator * (const Point &a) const
    {
        return x * a.y - y * a.x;
    }
    double operator % (const Point &a) const
    {
        return x * a.x + y * a.y;
    }
    double sqrLen() const
    {
        return *this % *this;
    }
    double len() const
    {
        return sqrt(sqrLen());
    }
};

const int N = 1010;
int n;
Point a[N];

double solve(Point A, Point B, Point C)
{
    double S = fabs((A - B) * (A - C));
    double L = max((A - B).len(), max((A - C).len(), (B - C).len()));
    return S / (2 * L);
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        a[i].scan();
    double ans = 1e20;
    for (int i = 0; i < n; i++)
        ans = min(ans, solve(a[i], a[(i + 1) % n], a[(i + 2) % n]));
    printf("%.13lf\n", ans);

    return 0;
}