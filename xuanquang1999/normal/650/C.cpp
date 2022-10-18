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
#define maxN 100005
#define oo 1000000007
#define sz(a) (int)a.size()
#define next abcxyz

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

struct UFDS {
private: vector<int> pset; int n;
public:
    UFDS(int n): n(n) {
        pset.resize(n);
        fto(i, 0, n-1) pset[i] = i;
    }
    int findSet(int i) {return (pset[i] == i) ? i : pset[i] = findSet(pset[i]);}
    bool unionSet(int i, int j) {
        int p = findSet(i), q = findSet(j);
        if (p == q) return false;
        pset[p] = q;
        return true;
    }
};

int n, m;
int toInd(int r, int c) {return r*m+c;}

int Solve(int u, int d[], const vector<int> g[]) {
    if (d[u] != -1) return d[u];

    int res = 1;
    for(int v: g[u]) res = max(res, Solve(v, d, g)+1);

    return d[u] = res;
}

int main () {
    scanf("%d%d", &n, &m);
    int a[n][m];
    fto(i, 0, n-1) {
        fto(j, 0, m-1) scanf("%d", &a[i][j]);
    }

    UFDS s(n*m);
    fto(i, 0, n-1) {
        ii p[m];
        fto(j, 0, m-1) p[j] = mp(a[i][j], j);
        sort(p, p+m);
        fto(j, 1, m-1) {
            int cur = toInd(i, p[j-1].ss), next = toInd(i, p[j].ss);
            if (p[j-1].ff == p[j].ff) s.unionSet(cur, next);
        }
    }
    fto(j, 0, m-1) {
        ii p[n];
        fto(i, 0, n-1) p[i] = mp(a[i][j], i);
        sort(p, p+n);
        fto(i, 1, n-1) {
            int cur = toInd(p[i-1].ss, j), next = toInd(p[i].ss, j);
            if (p[i-1].ff == p[i].ff) s.unionSet(cur, next);
        }
    }


    vector<int> g[n*m];
    fto(i, 0, n-1) {
        ii p[m];
        fto(j, 0, m-1) p[j] = mp(a[i][j], j);
        sort(p, p+m);
        fto(j, 1, m-1) {
            int cur = s.findSet(toInd(i, p[j-1].ss)), next = s.findSet(toInd(i, p[j].ss));
            if (p[j-1].ff < p[j].ff) g[next].pb(cur);
        }
    }
    fto(j, 0, m-1) {
        ii p[n];
        fto(i, 0, n-1) p[i] = mp(a[i][j], i);
        sort(p, p+n);
        fto(i, 1, n-1) {
            int cur = s.findSet(toInd(p[i-1].ss, j)), next = s.findSet(toInd(p[i].ss, j));
            if (p[i-1].ff < p[i].ff) g[next].pb(cur);
        }
    }

    int d[n*m];
    fto(i, 0, n*m-1) d[i] = -1;
    fto(i, 0, n*m-1) Solve(i, d, g);

    int ans[n][m];
    fto(i, 0, n*m-1) ans[i/m][i%m] = d[s.findSet(i)];

    fto(i, 0, n-1) {
        fto(j, 0, m-1) printf("%d ", ans[i][j]);
        puts("");
    }

    return 0;
}