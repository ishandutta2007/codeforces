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

struct pt {
    int x, y;
    pt operator + (pt p) {return {x + p.x, y + p.y};}
    pt operator - (pt p) {return {x - p.x, y - p.y};}
    int operator * (pt p) {return x*p.y - y*p.x;}
    int operator % (pt p) {return x*p.x + y*p.y;}
};

bool half(pt p) {
    return (p.y > 0 || (p.y == 0 && p.x < 0));
}

bool cmpPolar(pt &v, pt &w) {
    return make_tuple(half(v), 0) < make_tuple(half(w), v*w);
}

const int MAXN = 1e4 + 5;
const int MAXK = 105;
const int oo = 1e9 + 7;

int n, trace[MAXN+MAXK][MAXK][2][2], px[MAXN], py[MAXN], signX[MAXN], signY[MAXN];
vector<int> candR;
pt e[MAXN];

void knapsack(int a[], int sign[]) {
    int maxA = *max_element(a, a+n);
    vector<vector<int> > trace(n+1, vector<int>(2*maxA+1, 0));
    trace[0][maxA] = -1;
    fto(i, 0, n-1) {
        fto(j, 0, 2*maxA) {
            if (!trace[i][j]) continue;
            if (j >= a[i]) trace[i+1][j-a[i]] = -1;
            if (j+a[i] <= 2*maxA) trace[i+1][j+a[i]] = 1;
        }
    }

//    fto(i, 0, n) {
//        fto(j, 0, 2*maxA) printf("%d ", trace[i][j]);
//        puts("");
//    }
//    fto(i, 0, n-1) printf("%d ", a[i]);
//    puts("");

    int i = n, j = maxA;
    assert(trace[i][j] != 0);
    while (i > 0) {
        sign[i-1] = trace[i][j];
        j -= a[i-1]*sign[i-1];
        --i;
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    if (n == 3) {
        puts("YES");
        puts("0 0");
        puts("1 0");
        puts("0 2");
        return 0;
    }

    fto(i, 0, MAXN+MAXK-1)
        fto(k, 0, MAXK-1)
            fto(rx, 0, 1)
                fto(ry, 0, 1) trace[i][k][rx][ry] = -1;
    trace[0][0][0][0] = 0;

    int i = 0, k = -1;
    for(int r = 1; ; ++r) {
        vector<int> p;
        fto(x, 0, sqrt(r)) {
            int y2 = r - x*x, y = sqrt(y2);
            if (y*y == y2)
                p.pb(x);
        }
        if (sz(p) == 0) continue;

//        debug(r);
        candR.pb(r);
        fto(k, 0, MAXK-1) {
            fto(rx, 0, 1) {
                fto(ry, 0, 1) {
                    if (trace[i][k][rx][ry] == -1) continue;
                    if (k < MAXK-1) trace[i+1][k+1][rx][ry] = oo;
                    for(int x: p) {
                        int y = sqrt(r - x*x);
                        trace[i+1][k][(rx+x)&1][(ry+y)&1] = x;
                    }
                }
            }
        }

        ++i;
        if (i >= n && trace[i][i-n][0][0] != -1) {
            k = i-n;
            break;
        }
    }

    int rx = 0, ry = 0;
    while (i > 0) {
        if (trace[i][k][rx][ry] == oo) --k;
        else {
            int x = trace[i][k][rx][ry];
            int y = sqrt(candR[i-1] - x*x);
            px[i-k-1] = x; py[i-k-1] = y;
            rx = ((rx-x)%2 + 2)%2;
            ry = ((ry-y)%2 + 2)%2;
        }
        --i;
    }

    knapsack(px, signX);
    knapsack(py, signY);

//    fto(i, 0, n-1) printf("%d %d %d %d\n", px[i], signX[i], py[i], signY[i]);
    fto(i, 0, n-1) e[i] = {px[i]*signX[i], py[i]*signY[i]};

    sort(e, e+n, cmpPolar);

    pt p = {0, 0};
    puts("YES");
    fto(i, 0, n-1) {
        printf("%d %d\n", p.x, p.y);
        p = p+e[i];
    }

    return 0;
}