#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define maxN 12
#define maxK 100
#define MOD 1000
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct point {
    int x, y;
    point(int x, int y): x(x), y(y) {}
    point operator - (point p) {return {x-p.x, y-p.y};}
};

bool operator == (point a, point b) {return a.x == b.x && a.y == b.y;}

ll sq(ll x) {return 1LL*x*x;}

ll sq(point a, point b) {return sq(b.x-a.x) + sq(b.y-a.y);}

ll cross(point a, point b) {return 1LL*a.x*b.y - 1LL*a.y*b.x;}

int CCW(point a, point b, point c) {
    ll x = cross(b-a, c-a);
    if (x > 0) return 1;
    if (x < 0) return -1;
    return 0;
}

bool cmp(const point &a, const point &b) {
    return (a.y < b.y || (a.y == b.y && a.x < b.x));
}

vector<point> convexPath(const vector<point> &po) {
    vector<point> s;
    fto(i, 0, 1) s.pb(po[i]);
    fto(i, 2, sz(po)-1) {
        while (sz(s) > 1 && CCW(s[sz(s)-2], s[sz(s)-1], po[i]) <= 0) s.pop_back();
        s.pb(po[i]);
    }
    return s;
}

vector<point> convexHull(const vector<point> &po) {
    point A = *min_element(po.begin(), po.end(), cmp);
    point B = *max_element(po.begin(), po.end(), cmp);
    vector<point> P, Q;
    for(point p: po) {
        int x = CCW(A, p, B);
        if (x <= 0) P.pb(p);
        if (x >= 0) Q.pb(p);
    }

    sort(P.begin(), P.end(), cmp);
    reverse(P.begin(), P.end());
    P = convexPath(P);

    sort(Q.begin(), Q.end(), cmp);
    Q = convexPath(Q);

    vector<point> ans;
    fto(i, 0, sz(Q)-2) ans.pb(Q[i]);
    fto(i, 0, sz(P)-2) ans.pb(P[i]);
    if (sq(*ans.begin(), *ans.rbegin()) == 0) ans.pop_back();
    return ans;
}

void getEngine(vector<point> &p, int &n) {
    fto(i, 1, n) {
        int x, y;
        scanf("%d%d", &x, &y);
        p.pb({x, y});
    }

//    debug(n);
//    fto(i, 0, n-1) printf("%d %d\n", p[i].x, p[i].y);
    p = convexHull(p);
    n = sz(p);
//    debug(n);
//    fto(i, 0, n-1) printf("%d %d\n", p[i].x, p[i].y);
}

int n, m;
vector<point> p1, p2;

point rot90(point p) {
    return {-p.y, p.x};
}

void simplify(vector<point> &p) {
    int minX = p[0].x, minY = p[0].y;
    fto(i, 0, sz(p)-1) {
        minX = min(minX, p[i].x);
        minY = min(minY, p[i].y);
    }
    fto(i, 0, sz(p)-1) {
        p[i].x -= minX;
        p[i].y -= minY;
    }
}

int getMinimumRotation(const vector<point> &p) {
    int n = sz(p);
    vector<ll> s(n);
    fto(i, 0, n-1)
        s[i] = 1LL*p[i].x*100000001 + p[i].y;

    fto(i, 0, n-1) s.pb(s[i]);
    n *= 2;

    vector<int> f(n, -1);
    int k = 0;
    fto(j, 1, n-1) {
        ll sj = s[j];
        int i = f[j-k-1];
        while (i != -1 && sj != s[k+i+1]) {
            if (sj < s[k+i+1])
                k = j-i-1;
            i = f[i];
        }
        if (sj != s[k+i+1]) {
            if (sj < s[k])
                k = j;
            f[j-k] = -1;
        } else
            f[j-k] = i+1;
    }

    return k;
}

bool isEqual(const vector<point> &p1, const vector<point> &p2) {
    int n = sz(p1);
    int k1 = getMinimumRotation(p1), k2 = getMinimumRotation(p2);
    fto(i, 0, n-1)
        if (!(p1[(i+k1)%n] == p2[(i+k2)%n])) return false;
    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    getEngine(p1, n);
    getEngine(p2, m);

    if (n != m) {
        puts("NO");
        return 0;
    }

    bool ans = false;
    if (n == 2) {
        ans = (sq(p1[0], p1[1]) == sq(p2[0], p2[1]));
    } else {
        simplify(p1);
        fto(dir, 0, 3) {
            fto(i, 0, n-1)
                p2[i] = rot90(p2[i]);
            simplify(p2);

            if (isEqual(p1, p2))
                ans = true;
        }
    }

    puts((ans) ? "YES" : "NO");

    return 0;
}