#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sz(a) (int)a.size()

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

const double PI = acos(-1.0);
const double EPS = 1e-9;

struct pt {
    double x, y;
    pt operator + (pt p) {return {x + p.x, y + p.y};}
    pt operator - (pt p) {return {x - p.x, y - p.y};}
    pt operator * (double k) {return {x*k, y*k};}
    pt operator / (double k) {return {x/k, y/k};}
    double operator * (pt p) {return x*p.y - y*p.x;}
    double operator % (pt p) {return x*p.x + y*p.y;}
    friend istream& operator >> (istream &is, pt &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream &os, pt &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int sign(double x) {
    return (x > EPS) - (x < -EPS);
}

struct line {
    pt v; double c;
    line(pt p, pt q): v(q-p), c(v*p) {}
    double side(pt p) {return v*p - c;}
    bool contain(pt p) {return sign(side(p)) == 0;}
};

double area(pt po[], int n) {
    double res = 0;
    fto(i, 0, n-1)
        res += po[i]*po[(i+1)%n];
    return abs(res)/2;
}

const int MAXN = 505;

int n;
pt rect[MAXN][4];

enum MarkerType {
    AREA_ABOVE_START,
    AREA_ABOVE_END,
    AREA_BELOW_START,
    AREA_BELOW_END
};

pt inter(line l1, line l2) {
    return (l2.v*l1.c - l1.v*l2.c)/(l1.v*l2.v);
}

vector<pt> inter(pt po[], int n, line l) {
    vector<pt> res;
    fto(i, 0, n-1) {
        pt a = po[i], b = po[(i+1)%n];
        if (l.contain(a))
            res.pb(a);
        else if (sign(l.side(a)) * sign(l.side(b)) < 0)
            res.pb(inter(l, line(a, b)));
    }
    return res;
}

struct Marker {
    pt p;
    MarkerType type;
    bool operator < (const Marker &rhs) const {
        return p.x < rhs.p.x;
    }
};

double trapezoidArea(pt p, pt q) {
    return (q.x - p.x)*(p.y + q.y)/2;
}

double solve(line l) {
    vector<Marker> mark;
    fto(i, 0, n-1) {
        bool onBorder = false;
        fto(j, 0, 3) {
            pt a = rect[i][j], b = rect[i][(j+1)%4];
            if (a.x > b.x)
                swap(a, b);
            if (l.contain(a) && l.contain(b)) {
                onBorder = true;
                if (sign(l.side(rect[i][(j+2)%4])) > 0) {
                    mark.pb({a, AREA_ABOVE_START});
                    mark.pb({b, AREA_ABOVE_END});
                } else {
                    mark.pb({a, AREA_BELOW_START});
                    mark.pb({b, AREA_BELOW_END});
                }
            }
        }
        if (onBorder) continue;

        vector<pt> p = inter(rect[i], 4, l);
        if (sz(p) > 1) {
            if (p[0].x > p[1].x)
                swap(p[0], p[1]);
            mark.pb({p[0], AREA_ABOVE_START});
            mark.pb({p[0], AREA_BELOW_START});
            mark.pb({p[1], AREA_ABOVE_END});
            mark.pb({p[1], AREA_BELOW_END});
        }
    }

    sort(mark.begin(), mark.end());

    double ans = 0;
    int j = 0, cntAbove = 0, cntBelow = 0;
    fto(i, 1, sz(mark)-1) {
        while (j < sz(mark) && mark[j].p.x < mark[i].p.x) {
            switch (mark[j].type) {
                case AREA_ABOVE_START: ++cntAbove; break;
                case AREA_ABOVE_END: --cntAbove; break;
                case AREA_BELOW_START: ++cntBelow; break;
                case AREA_BELOW_END: --cntBelow; break;
            }
            ++j;
        }
        int sgn = (cntBelow > 0) - (cntAbove > 0);
        ans += trapezoidArea(mark[i-1].p, mark[i].p)*sgn;
    }

    return ans;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n;
    fto(i, 0, n-1)
        fto(j, 0, 3)
            cin >> rect[i][j];

    vector<pair<pt, pt> > done;

    double unionArea = 0;
    fto(i, 0, n-1) {
        fto(j, 0, 3) {
            pt s = rect[i][j], t = rect[i][(j+1)%4];
            if (s.x == t.x)
                continue;

            if (s.x > t.x)
                swap(s, t);
            line l(s, t);

            bool solved = false;
            for(auto p: done) {
                if (l.contain(p.ff) && l.contain(p.ss)) {
                    solved = true;
                    break;
                }
            }
            if (solved) continue;

            unionArea += solve(l);
            done.pb(mp(s, t));
        }
    }

    double totalArea = 0;
    fto(i, 0, n-1)
        totalArea += area(rect[i], 4);

//    debug(totalArea);
//    debug(unionArea);

    double ans = totalArea/unionArea;
    cout << setprecision(50) << ans;

    return 0;
}