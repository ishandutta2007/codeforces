#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define psi pair <string, int>
using namespace std;

struct Point
{
    long double x, y;
    Point () {}
    Point (long double x, long double y) : x (x), y (y) {}
};

double mult(Point a, Point b, Point c)
{
    return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}

//aa, bb cc, dd true, false
bool intersect(Point aa, Point bb, Point cc, Point dd)
{
    if ( max(aa.x, bb.x)<min(cc.x, dd.x) )
    {
        return false;
    }
    if ( max(aa.y, bb.y)<min(cc.y, dd.y) )
    {
        return false;
    }
    if ( max(cc.x, dd.x)<min(aa.x, bb.x) )
    {
        return false;
    }
    if ( max(cc.y, dd.y)<min(aa.y, bb.y) )
    {
        return false;
    }
    if ( mult(cc, bb, aa)*mult(bb, dd, aa)<0 )
    {
        return false;
    }
    if ( mult(aa, dd, cc)*mult(dd, bb, cc)<0 )
    {
        return false;
    }
    return true;
}
int n, res = 0;
int x[1010], y[1010];

int jug (int p, int q) {
    Point a = Point (x[q], y[q]), b;
    if (x[p] == x[q]) {
        a.y += y[p] < y[q] ? 0.5 : -0.5;
        b = a;
        b.x += 50000;
    } else {
        a.x += x[p] < x[q] ? 0.5 : -0.5;
        b = a;
        b.y += 50000;
    }
    int c = 0;
    for (int i = 1, j = 2; i <= n; i++, j++) {
        if(j > n) j = 1;
        if (intersect (a, b, Point (x[i], y[i]), Point (x[j], y[j]))) c++;
    }
//    cout << p << ' ' << q << ' ' << a.x << ' ' << a.y << ' ' << ' ' << b.x << ' ' << b.y << ' ' << c << endl;
    return c & 1;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n;
//    cin >> x[1] >> y[1];
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &x[i], &y[i]);
    }
    for (int i = 2; i <= n; i++) {
        if (jug (i - 1, i)) res++;
    }
    res += jug (n, 1);
    cout << res;
}