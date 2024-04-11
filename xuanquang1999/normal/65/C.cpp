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
#define double long double

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
    double x, y, z;
    pt operator + (pt p) {return {x + p.x, y + p.y, z + p.z};}
    pt operator - (pt p) {return {x - p.x, y - p.y, z - p.z};}
    pt operator * (double k) {return {x*k, y*k, z*k};}
    pt operator / (double k) {return {x/k, y/k, z/k};}

    friend istream& operator >> (istream& is, pt &p) {
        is >> p.x >> p.y >> p.z;
        return is;
    }
    friend ostream& operator << (ostream& os, const pt &p) {
        os << p.x << " " << p.y << " " << p.z;
        return os;
    }
};

double mag(pt v) {return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);}

const int MAXN = 1e4 + 5;
const double oo = 1e9 + 7;
const double EPS = 1e-9;

int n;
pt s[MAXN], p, ans;
double vp, vs, len[MAXN], sumT;

bool Check(double x) {
    double curX = x;
    pt posS = s[n];
    fto(i, 0, n-1) {
        double t = len[i]/vs;
        if (t < curX)
            curX -= t;
        else {
            posS = s[i] + (s[i+1] - s[i])*curX/t;
            break;
        }
    }

//    debug(x);
//    debug(posS);

    if (mag(posS - p) < x*vp + EPS) {
        ans = posS;
        return true;
    }
    return false;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n;
    fto(i, 0, n) cin >> s[i];

    cin >> vp >> vs;
    cin >> p;

    fto(i, 0, n-1) {
        len[i] = mag(s[i] - s[i+1]);
        sumT += len[i]/vs;
    }

    double lo = 0, hi = sumT, res = oo;
//    debug(hi);
    fto(iter, 0, 100) {
        double mid = (lo+hi)/2;
        if (Check(mid))

            res = hi = mid;
        else
            lo = mid;
    }

    if (res == oo)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        cout << setprecision(69) << res << endl;
        cout << ans << endl;
    }

    return 0;
}