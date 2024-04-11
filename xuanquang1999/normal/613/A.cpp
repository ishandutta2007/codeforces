#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double T;
typedef complex<T> pt;
#define X real()
#define Y imag()
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
#define maxN 100005
#define MOD 1000
#define oo 1000000007
#define sz(a) (int)a.size()
#define y1 ejkbaefbkj

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

T cross(pt a, pt b) {return (conj(a)*b).Y;}

T dot(pt a, pt b) {return (conj(a)*b).X;}

struct line {
    pt v; T c;
    line(pt a, pt b): v(b-a), c(cross(v, a)) {}
    bool cmpProj(pt a, pt b) {return dot(v, a) < dot(v, b);}
    T side(pt p) {return cross(v, p) - c;}
    T dist(pt p) {return abs(side(p))/abs(v);}
};

double dist(pt a, pt b, pt p) {
    if (a != b) {
        line l(a, b);
        if (l.cmpProj(a, p) && l.cmpProj(p, b))
            return l.dist(p);
    }
    return min(abs(a-p), abs(b-p));
}

void read(pt &p) {
    int x, y;
    scanf("%d%d", &x, &y);
    p = {x, y};
}

int n;
pt p, po[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    read(p);
    fto(i, 0, n-1) read(po[i]);

    double rmax = 0, rmin = oo;
    fto(i, 0, n-1) rmax = max(rmax, abs(po[i]-p));
    fto(i, 0, n-1) rmin = min(rmin, dist(po[i], po[(i+1)%n], p));

    printf("%.15g", PI*(rmax*rmax - rmin*rmin));



    return 0;
}