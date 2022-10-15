
#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

using T = ll;

struct Point
{
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) { }
    Point operator+=(const Point& rhs) { x += rhs.x, y += rhs.y; return *this; }
    Point operator-=(const Point& rhs) { x -= rhs.x, y -= rhs.y; return *this; }
    Point operator+(const Point& rhs) const { return Point(*this) += rhs; }
    Point operator-(const Point& rhs) const { return Point(*this) -= rhs; }
    bool operator==(const Point& rhs) const { return x == rhs.x && y == rhs.y; }
    friend Point operator*(const T& alpha, const Point& pt)
    {
        return Point(alpha * pt.x, alpha * pt.y);
    }
    friend T operator*(const Point& lhs, const Point& rhs)
    {
        return lhs.x * rhs.x + lhs.y * rhs.y;
    }
    bool operator<(const Point& rhs) const
    {
        return pair(x, y) < pair(rhs.x, rhs.y);
    }
    friend ostream& operator<<(ostream& out, const Point& pt)
    {
        return out << pt.x << " " << pt.y;
    }
};

// determinant of
// [ p.x p.y ]
// [ q.x q.y ]

T det(const Point& p, const Point& q)
{
    return p.x * q.y - q.x * p.y;
}

// checks if p-q-r bends clockwise on q

bool cw(const Point& p, const Point& q, const Point& r)
{
    return det(q - p, r - q) < 0;
}

// checks if p-q-r bends counter-clockwise on q

bool ccw(const Point& p, const Point& q, const Point& r)
{
    return 0 < det(q - p, r - q);
}

// O(n log(n))

vector<Point> convex_hull(vector<Point> pts)
{
    sort(all(pts)), pts.erase(unique(all(pts)), end(pts));

    const int n = size(pts);

    if (n == 1) return pts;

    Point p = pts[0], q = pts[n - 1];

    vector<Point> up(n), down(n); up[0] = down[0] = p;

    int idx = 1, idy = 1;

    for (int i = 1; i < n; ++i)
    {
        if (i == n - 1 || cw(p, pts[i], q))
        {
            while (idx > 1 && not cw(up[idx - 2], up[idx - 1], pts[i])) --idx;
            up[idx++] = pts[i];
        }
        if (i == n - 1 || ccw(p, pts[i], q))
        {
            while (idy > 1 && not ccw(down[idy - 2], down[idy - 1], pts[i])) --idy;
            down[idy++] = pts[i];
        }
    }

    up.resize(--idx), down.resize(idx + idy - 1);
    copy(rbegin(up), prev(rend(up)), begin(down) + idy);

    return down;
}

template<typename T>
vector<int> prefix_function(const vector<T>& s)
{
    int n = size(s);
    vector<int> p(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) ++j;
        p[i] = j;
    }
    return p;
}

int main()
{ _
    int n, m; cin >> n >> m;

    vector<Point> A(n), B(m);

    for (auto& [x, y] : A) cin >> x >> y;
    for (auto& [x, y] : B) cin >> x >> y;

    auto hullA = convex_hull(A), hullB = convex_hull(B);

    int k = size(hullA), l = size(hullB);

    debug(k);
    debug(l);

    string ans = "NO";

    if (k == l)
    {
        vector<ll> strA, strB;

        for (int t = 0; t < 2; ++t)
        {
            for (int i = 0; i < k; ++i)
            {
                Point cur = hullA[(i + 1) % k] - hullA[i];
                Point nxt = hullA[(i + 2) % k] - hullA[(i + 1) % k];
                strA.insert(end(strA), { cur * cur, cur * nxt });
            }
            swap(hullA, hullB);
            swap(strA, strB);
        }

        vector<ll> str(all(strB));
        str.push_back(-LINF);
        str.insert(end(str), all(strA));
        str.insert(end(str), all(strA));

        vector<int> pi = prefix_function(str);

        int L = size(strA);

        for (int x = L + 1; x < size(pi); ++x)
        {
            if (pi[x] == L)
            {
                ans = "YES";
                break;
            }
        }
    }

    cout << ans << endl;

    exit(0);
}