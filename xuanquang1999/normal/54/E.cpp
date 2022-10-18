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
    pt operator * (double k) {return {x * k, y * k};}
    pt operator / (double k) {return {x / k, y / k};}
    double operator * (pt p) {return x*p.y - y*p.x;}
    double operator % (pt p) {return x*p.x + y*p.y;}
    friend istream& operator >> (istream& is, pt &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream& os, pt &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

pt perp(pt v) {return {-v.y, v.x};}

double sq(pt v) {return v.x*v.x + v.y*v.y;}

struct line {
    pt v; double c;
    line(pt p, pt q): v(q-p), c(v*p) {}
    double side(pt p) {return v*p - c;}
    pt proj(pt p) {return p - perp(v)*side(p)/sq(v);}
    bool cmpProj(pt p, pt q) {return v%p < v%q;}
};

double orient(pt a, pt b, pt c) {
    return (b-a)*(c-a);
}

double area(vector<pt> p) {
    double res = 0; int n = sz(p);
    fto(i, 0, n-1)
        res += p[i]*p[(i+1)%n];
    return abs(res)/2;
}

const int MAXN = 4e4 + 5;
const double oo = 1e18 + 7;

int n;
pt p[MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);
    cin >> n;
    fto(i, 0, n-1) cin >> p[i];

    double ans = oo;
    fto(iter, 0, 1) {
        double sum = 0;
        pt O = p[0];

        int cur = 0, nxt = 1;
        fto(i, 0, n-1) {
            line l(p[i], p[(i+1)%n]);
            while (l.cmpProj(p[cur], p[nxt])) {
                sum += area({O, p[cur], p[nxt]});
                cur = nxt; nxt = (nxt+1)%n;
            }

    //        printf("%d %d\n", i, cur);

            pt H = l.proj(p[cur]);
            double quad = area({O, p[i], H, p[cur]});
            ans = min(ans, quad - sum);

            sum -= area({O, p[i], p[(i+1)%n]});
        }

        reverse(p, p+n);
    }

//    fto(i, 0, n-1)
//        cout << p[i] << endl;


    cout << setprecision(69) << ans;

    return 0;
}