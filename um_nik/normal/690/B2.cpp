#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

struct Point
{
    int x, y;
    Point () : x(), y() {}
    Point (int _x, int _y) : x(_x), y(_y) {}
    Point operator- (const Point& p) const
    {
        return Point(x - p.x, y - p.y);
    }
    Point operator+ (const Point& p) const
    {
        return Point(x + p.x, y + p.y);
    }
    int operator* (const Point& p) const
    {
        return x * p.y - y * p.x;
    }
    void print()
    {
        printf("%d %d\n", x, y);
    }
    int len2() const
    {
        return x * x + y * y;
    }
};

const int N = 510;
int n;
char a[N][N];
bool inside[N][N];
vector<Point> pts, hull;

bool solve()
{
    scanf("%d", &n);
    if (n == 0)
        return false;
    for(int i = 0; i < n; ++i)
    {
        scanf("%s", a[i]);
        for(int j = 0; j < n; ++j)
            a[i][j] -= '0';
    }

    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            inside[i][j] = false;
    for(int i = 1; i < n; ++i)
        for(int j = 1; j < n; ++j)
            inside[i][j] = a[i - 1][j - 1] && a[i][j - 1] && a[i - 1][j] && a[i][j];
    
    /*for(int i = 1; i < n - 1; ++i)
    {
        a[0][i] -= inside[1][i];
        a[0][i] -= inside[1][i + 1];
        a[n - 1][i] -= inside[n - 1][i];
        a[n - 1][i] -= inside[n - 1][i + 1];
        a[i][0] -= inside[i][1];
        a[i][0] -= inside[i + 1][1];
        a[i][n - 1] -= inside[i][n - 1];
        a[i][n - 1] -= inside[i + 1][n - 1];
    }
    
    for(int i = 2; i < n - 1; ++i)
    {
        inside[0][i] = a[0][i - 1] && a[0][i];
        inside[i][0] = a[i - 1][0] && a[i][0];
        inside[n][i] = a[n - 1][i - 1] && a[n - 1][i];
        inside[i][n] = a[i - 1][n - 1] && a[i][n - 1];
    }
    
    a[0][1] -= inside[0][2];
    a[1][0] -= inside[2][0];
    a[0][n - 2] -= inside[0][n - 2];
    a[n - 2][0] -= inside[n - 2][0];
    a[n - 1][1] -= inside[n][2];
    a[1][n - 1] -= inside[2][n];
    a[n - 1][n - 2] -= inside[n][n - 2];
    a[n - 2][n - 1] -= inside[n - 2][n];
    
    inside[0][1] = a[0][1];
    inside[1][0] = a[1][0];
    inside[0][n - 1] = a[0][n - 2];
    inside[n - 1][0] = a[n - 2][0];
    inside[n][1] = a[n - 1][1];
    inside[1][n] = a[1][n - 1];
    inside[n][n - 1] = a[n - 1][n - 2];
    inside[n - 1][n] = a[n - 2][n - 1];

    a[0][0] -= inside[0][1];
    a[0][0] -= inside[1][0];
    a[n - 1][0] -= inside[n - 1][0];
    a[n - 1][0] -= inside[n][1];
    a[0][n - 1] -= inside[0][n - 1];
    a[0][n - 1] -= inside[1][n];
    a[n - 1][n - 1] -= inside[n - 1][n];
    a[n - 1][n - 1] -= inside[n][n - 1];

    inside[0][0] = a[0][0];
    inside[n][0] = a[n - 1][0];
    inside[0][n] = a[0][n - 1];
    inside[n][n] = a[n - 1][n - 1];*/

    pts.clear();
    hull.clear();
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j <= n; ++j)
            if (inside[i][j])
                pts.emplace_back(i, j);
    auto O = pts[0];
    for(auto& p : pts)
        p = p - O;
    sort(pts.begin() + 1, pts.end(), [] (const Point& f, const Point& s) { return f * s == 0 ? f.len2() < s.len2() : f * s > 0; });
    pts.emplace_back();
    for(auto p : pts)
    {
        for(; hull.size() > 1 && (hull.back() - hull[hull.size() - 2]) * (p - hull[hull.size() - 2]) <= 0; hull.pop_back());
        hull.push_back(p);
    }
    hull.pop_back();
    reverse(hull.begin() + 1, hull.end());
    for(auto &p : hull)
    {
        p = O + p;
        swap(p.x, p.y);
        p.y = n - p.y;
    }
    int b = 0;
    for(int i = 1; i < (int)hull.size(); ++i)
        if (hull[i].x < hull[b].x || (hull[i].x == hull[b].x && hull[i].y < hull[b].y))
            b = i;
    printf("%d\n", (int)hull.size());
    for(int i = b; i < (int)hull.size(); ++i)
        hull[i].print();
    for(int i = 0; i < b; ++i)
        hull[i].print();
    
    /*for(int i = 0; i <= n; ++i, printf("\n"))
        for(int j = 0; j <= n; ++j)
            printf(inside[i][j] ? "1" : "0");*/

    return true;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    while(solve());

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}