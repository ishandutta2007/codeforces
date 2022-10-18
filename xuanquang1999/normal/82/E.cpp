#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
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
#define sz(a) (int)a.size()
#define left Left
#define right Right

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

struct pt {
    double x, y;
    pt operator + (pt p) {return {x + p.x, y + p.y};}
    pt operator - (pt p) {return {x - p.x, y - p.y};}
    pt operator * (double k) {return {x*k, y*k};}
    pt operator / (double k) {return {x/k, y/k};}
    double operator * (pt p) {return x*p.y - y*p.x;}
    double operator % (pt p) {return x*p.x + y*p.y;}
    friend istream& operator >> (istream& is, pt &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream &os, pt &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

double orient(pt a, pt b, pt c) {
    return (b-a)*(c-a);
}

double area(pt a, pt b, pt c) {
    return abs(orient(a, b, c))/2;
}

pt inter(pt a, pt b, pt c, pt d) {
    double oa = orient(c, d, a), ob = orient(c, d, b);
    return (b*oa - a*ob)/(oa - ob);
}

int n, h, f;
vector<ii> left, right;

double inter(double x, double y) {
    if (x == 0 || y == 0) return 0;
    if (x > y) swap(x, y);

    pt lampT = {0, h+f}, lampB = {0, -h-f};
    pt windT = {x, h}, windB = {y, -h};
    pt p = inter(lampT, windT, lampB, windB);

    double ans = area(lampT, lampB, p) - f*(x+y)/2;
    if (p.y < -h) {
        pt interB = {x*(2*h+f)/f, -h};
        ans += area(p, interB, windB);
    }

//    cout << "inter: " << x << " " << y << endl;
//    debug(lampT);
//    debug(lampB);
//    debug(windT);
//    debug(windB);
//    debug(p);
//    debug(ans);
    return ans;
}

double area(double x) {
    double y = x*(2*h+f)/f;
    return (y*(2*h+f) - x*f)/2;
}

double Solve(vector<ii> seg) {
    double res = 0;
    for(ii p: seg)
        res += 2*(area(p.ss) - area(p.ff));
//    debug(res);

    fto(i, 0, sz(seg)-1) {
        fto(j, 0, sz(seg)-1) {
            res -= inter(seg[i].ss, seg[j].ss) - inter(seg[i].ff, seg[j].ss) - inter(seg[i].ss, seg[j].ff) + inter(seg[i].ff, seg[j].ff);
        }
    }

    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> h >> f;
    f -= h;
    fto(i, 0, n-1) {
        int l, r;
        cin >> l >> r;
        if (r <= 0) {
            left.pb(mp(-r, -l));
        } else if (l >= 0) {
            right.pb(mp(l, r));
        } else {
            left.pb(mp(0, -l));
            right.pb(mp(0, r));
        }
    }

    cout << setprecision(50);
    cout << Solve(left) + Solve(right);

    return 0;
}