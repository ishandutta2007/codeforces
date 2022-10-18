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
#define maxN 200005
#define MOD 1000
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()
#define EPS 1e-11

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

struct Element {
    int x, id;
    bool inline operator < (const Element &rhs) const {
        return x < rhs.x;
    }
};

int n;
Element a[maxN];
ll d[maxN];
double maxSkew = -1;
int ansR, ansInd;

double getSkew(int i, int r) {
    double skew = 1.0*(d[i]-d[i-r-1] + d[n]-d[n-r])/(2*r+1) - a[i].x;
    if (skew > maxSkew-EPS) {
        maxSkew = skew;
        ansR = r;
        ansInd = i;
    }
//    printf("%d %d %.9g\n", i, r, skew);
    return skew;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        scanf("%d", &a[i].x);
        a[i].id = i;
    }

    sort(a+1, a+n+1);
    fto(i, 1, n) d[i] = d[i-1]+a[i].x;

    maxSkew = -1;
    fto(pos, 1, n) {
        int lo = 0, hi = min(pos-1, n-pos);
        fto(i, 1, 50) {
            int m1 = (2*lo+hi)/3, m2 = (lo+2*hi+2)/3;
//            printf("%d %d %d\n", pos, m1, m2);
            double f1 = getSkew(pos, m1), f2 = getSkew(pos, m2);
            if (f1 > f2-EPS)
                hi = m2;
            if (f2 > f1-EPS)
                lo = m1;
        }
    }

    vector<int> ans;
    ans.pb(a[ansInd].x);
    fto(i, 1, ansR) {
        ans.pb(a[ansInd-i].x);
        ans.pb(a[n-i+1].x);
    }

    printf("%d\n", sz(ans));
    for(int x: ans) printf("%d ", x);


    return 0;
}