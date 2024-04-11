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

struct line {
    pt v; T c;
    //ax + by = c;
    line(T a, T b, T c): v({b, -a}), c(c) {}
    T side(pt p) {return cross(v, p) - c;}
};

int sgn(T x) {return (x > 0) - (x < 0);}

void read(pt &p) {
    int x, y;
    scanf("%d%d", &x, &y);
    p = {x, y};
}

pt p1, p2;
int n;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    read(p1);
    read(p2);

    scanf("%d", &n);
    int ans = 0;
    fto(i, 1, n) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        line l(a, b, -c);
        if (sgn(l.side(p1))*sgn(l.side(p2)) < 0) ++ans;
    }

    printf("%d", ans);

    return 0;
}