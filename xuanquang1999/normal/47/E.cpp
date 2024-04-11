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
const int MAXN = 1e4 + 5;
const int MAXM = 1e5 + 5;
const double g = 9.8;
const double EPS = 1e-10;

struct Query {
    double angle; int id;
    bool operator < (const Query &rhs) const {
        return angle < rhs.angle;
    }
};

struct Wall {
    double x, y;
    bool operator < (const Wall &rhs) const {
        return x < rhs.x;
    }
};

int n, V, m;
double ansX[MAXN], ansY[MAXN];
Query q[MAXN];
Wall w[MAXM];

double sq(double x) {return x*x;}

bool toLeft(double alpha, double x, double y) {
    double vx = V*cos(alpha), vy = V*sin(alpha);
    double t = x/vx;
    double ansY = vy*t - g*sq(t)/2;
    return (ansY > y+EPS);
}

void getDest(double alpha, int i, double &ansX, double &ansY) {
    double vx = V*cos(alpha), vy = V*sin(alpha);
    double t;
    if (i < m) {
        double x = w[i].x, y = w[i].y;
        t = x/vx;
        ansY = vy*t - g*sq(t)/2;
        if (-EPS < ansY && ansY < y+EPS) {
            ansX = x;
            return;
        }
    }

    t = 2*vy/g;
    ansX = vx*t;
    ansY = 0;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &V);
    fto(i, 0, n-1) {
        scanf("%lf", &q[i].angle);
        q[i].id = i;
    }
    scanf("%d", &m);
    fto(i, 0, m-1)
        scanf("%lf%lf", &w[i].x, &w[i].y);

    sort(q, q+n);
    sort(w, w+m);

    int j = 0;
    fto(i, 0, n-1) {
        while (j < m && toLeft(q[i].angle, w[j].x, w[j].y))
            ++j;
//        printf("%d %d\n", i, j);
        getDest(q[i].angle, j, ansX[q[i].id], ansY[q[i].id]);
    }

    fto(i, 0, n-1)
        printf("%.15f %.15f\n", ansX[i], ansY[i]);

    return 0;
}