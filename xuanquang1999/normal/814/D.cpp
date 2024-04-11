//84104971101048411497 - Can you guess what does this mean?
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
#define X real()
#define Y imag()
#define maxN 1005
#define oo 2000000007
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

struct circle {
    int x, y, r;
    double area;
};

bool cmp(const circle &a, const circle &b) {
    return (a.r < b.r);
}

ll sqr(ll x) {return x*x;}

int n, p[maxN];
double f[maxN][2][2];
circle c[maxN];
vector<int> g[maxN];
bool visited[maxN];

void DFS(int u) {
    visited[u] = true;

    fto(l, 0, 1) {
        fto(r, 0, 1) {
            double sumL = (l == 0) ? (-c[u].area) : c[u].area;
            double sumR = (r == 0) ? (-c[u].area) : c[u].area;
            //printf("%d %d %d %.9g %.9g\n", u, l, r, sumL, sumR);
            forit(it, g[u]) {
                int v = *it;
                if (!visited[v]) DFS(v);
                sumL += f[v][1-l][r];
                sumR += f[v][l][1-r];
            }
            f[u][l][r] = max(sumL, sumR);
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        c[i] = {x, y, r, PI*r*r};
    }

    sort(c+1, c+n+1, cmp);

//    fto(i, 1, n) printf("%d %d %d %.9g\n", c[i].x, c[i].y, c[i].r, c[i].area);

    fto(i, 1, n) {
        fto(j, 1, i-1) {
            if (p[j] == 0 && sqr(c[j].x-c[i].x)+sqr(c[j].y-c[i].y) <= sqr(c[i].r)) p[j] = i;
        }
    }

    fto(i, 1, n) {
        if (p[i] != 0) g[p[i]].pb(i);
    }

//    fto(i, 1, n) printf("%d ", p[i]);
//    puts("");

    double ans = 0;
    fto(i, 1, n) {
        if (p[i] == 0) {
            DFS(i);
            ans += f[i][1][1];
        }
    }
//    fto(i, 1, n) {
//        debug(i);
//        fto(l, 0, 1) {
//            fto(r, 0, 1) printf("%.9g ", f[i][l][r]);
//            puts("");
//        }
//    }
    cout << setprecision(10) << ans;

    return 0;
}