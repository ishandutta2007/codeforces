using namespace std;
#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 100005
#define oo 100000000000000

int m, n, ansX, ansY;
double a, b, y[maxN], l[maxN], minL;
vector<double> x;

double sqr(double x) {
    return (x*x);
}

double EDist(double x1, double y1, double x2, double y2) {
    return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

void Update(int iX, int iY) {
    double d = EDist(0, 0, a, x[iX])+EDist(a, x[iX], b, y[iY])+l[iY];
    if (d < minL) {
        minL = d;
        ansX = iX;
        ansY = iY;
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%lf%lf", &m, &n, &a, &b);
    fto(i, 0, m-1) {
        double t;
        scanf("%lf", &t);
        x.pb(t);
    }

    fto(i, 0, n-1) scanf("%lf", &y[i]);
    fto(i, 0, n-1) scanf("%lf", &l[i]);

    //fto(i, 0, x.size()-1) debug(x[i]);

    minL = oo;
    fto(i, 0, n-1) {
        double yP = y[i]*(a/b);
        int p = upper_bound(x.begin(), x.end(), yP)-x.begin();
        if (p == m) p = 0;
        if (p > 1) Update(p-2, i);
        if (p > 0) Update(p-1, i);
        Update(p, i);
        if (p < m-1) Update(p+1, i);
    }

    printf("%d %d\n", ansX+1, ansY+1);

    return 0;
}