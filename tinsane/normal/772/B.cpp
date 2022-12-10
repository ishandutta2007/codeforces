#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define print_var(x) cerr << #x << " = " << x << endl
#define print_array(arr, len) {cerr << #arr << " = "; for (int i = 0; i < len; i++) cerr << arr[i] << " "; cerr << endl;}
#define print_iterable(it) {cerr << #it << " = "; for (const auto &e : it) cerr << e << " "; cerr << endl;}
#else
#define eprintf(...) (void)0
#define print_var(x) (void)0
#define print_array(arr, len) (void)0
#define print_iterable(it) (void)0
#endif

typedef long long ll;
const int N = 1005;

struct Point
{
    double x, y;
    Point(): x(), y() {}
    Point(double _x, double _y): x(_x), y(_y) {}
    void scan()
    {
        scanf("%lf%lf", &x, &y);
    }
    Point operator-(Point p) const
    {
        return Point(x - p.x, y - p.y);
    }
    double len() const
    {
        return sqrt(x * x + y * y);
    }
    double operator*(Point p) const
    {
        return x * p.y - y * p.x;
    }
    double height(Point A, Point B) const
    {
        Point C = *this;
        double s = abs((B - A) * (C - A));
        double b = (B - A).len();
        return s / b;
    }
};

int n;
Point pts[N];

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        pts[i].scan();

    double res = 1e20;
    for (int i = 0; i < n; i++)
    {
        Point A = pts[(i - 1 + n) % n];
        Point B = pts[i];
        Point C = pts[(i + 1) % n];
        res = min(res, B.height(A, C) / 2);
    }

    printf("%.10lf\n", res);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}