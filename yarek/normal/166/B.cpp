#include <bits/stdc++.h>
using namespace std;

typedef long long T;

struct Vec
{
    T x, y;
};

inline Vec operator+(const Vec &a, const Vec &b) 
{
    return { a.x + b.x, a.y + b.y }; 
}

inline Vec operator-(const Vec &a, const Vec &b)
{
    return { a.x - b.x, a.y - b.y };
}

inline Vec operator*(const Vec &a, const T &b)
{
    return  { a.x * b, a.y * b };
}

inline Vec operator/(const Vec &a, const T &b)
{
    return  { a.x / b, a.y / b };
}

inline T dot(const Vec &a, const Vec &b)
{
    return a.x * b.x + a.y * b.y;
}

inline T prod(const Vec &a, const Vec &b)
{
    return a.x * b.y - a.y * b.x;
}

inline T len(const Vec &v)
{
    return sqrt(dot(v, v));
}

inline T len2(const Vec &v)
{
    return dot(v, v);
}

inline T alpha(const Vec &v)
{
    return atan2(v.y, v.x);
}

struct ParamLine
{
    Vec p, v;
    ParamLine() = default;
    ParamLine(Vec a, Vec b)
    {
        p = a;
        v = b - a;
    }
};

Vec project(const ParamLine &l, const Vec &u)
{
    return l.p + l.v * dot((u - l.p), l.v) / len2(l.v);
}

T dist(const ParamLine &l, const Vec &u)
{
    return abs(prod(l.v, u - l.p) / len(l.v));
}

struct Line
{
    T A, B, C;
    Line() = default;
    Line(Vec a, Vec b) 
    {
        Vec d = b - a;
        A = -d.y;
        B = d.x;
        C = -(A * a.x + B * a.y);
    }
    Line(ParamLine l) 
    {
        A = -l.v.y;
        B = l.v.x;
        C = -(A * l.p.x + B * l.p.y);
    }
};

Vec intersect(const Line &a, const Line &b)
{
    T norm = a.B * b.A - a.A * b.B;
    return Vec { a.B * b.C - a.C * b.B, a.C * b.A - a.A * b.C } / -norm;
}

T dist(const Line &l, const Vec &v)
{
    return abs(l.A * v.x + l.B * v.y + l.C) / sqrt(l.A * l.A + l.B * l.B);
}

inline int sgn(T x)
{
    const T eps = 1e-9;
    if(abs(x) <= eps) return 0;
    return x > 0 ? 1 : -1;
}

bool operator<(const Vec &a, const Vec &b)
{
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}

//pierwszy element - punkt najmniejszy leksykograficznie, reszta posortowana zgodnie z ruchem wskazowek
vector<Vec> convexHull(vector<Vec> points)
{
    auto it = min_element(points.begin(), points.end());
    auto o = *it;
    points.erase(it);
    sort(points.begin(), points.end(), [o](Vec a, Vec b) {
        int s = sgn(prod(a - o, b - o));
        return s < 0 || (s == 0 && len2(a) < len2(b));
    });
    vector<Vec> ans { o };
    for(auto p: points)
    {
        while(ans.size() > 1)
        {
            auto a = ans[ans.size()-2], b = ans[ans.size()-1];
            if(sgn(prod(p - a, b - a)) > 0) break;
            ans.pop_back();
        }
        ans.push_back(p);
    }
    return ans;
}

//zwraca czy v jest scisle wewnatrz otoczki
bool insideHull(const vector<Vec> &hull, const Vec &v)
{
    auto o = hull[0];
    if(v < o || sgn(prod(hull[1] - o, v - o)) == 0 || sgn(prod(hull.back() - o, v - o)) == 0)
        return false;
    auto it = lower_bound(hull.begin() + 1, hull.end(), v, [o](Vec a, Vec b) {
        return prod(a - o, b - o) < 0;
    });
    if(it == hull.begin() + 1 || it == hull.end()) return false;
    return prod(v - *it, *prev(it) - *it) < 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<Vec> points(n);
    for(auto &p: points)
        scanf("%lld %lld", &p.x, &p.y);
    auto hull = convexHull(points);
    
    //for(auto p: hull)
    //    printf("%lld %lld\n", p.x, p.y);
    
    int m;
    scanf("%d", &m);
    while(m--)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if(!insideHull(hull, { x, y }))
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}