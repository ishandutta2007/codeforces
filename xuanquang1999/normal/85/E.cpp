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
#define left Left
#define right Right

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

struct DSU {
    vector<int> pset, opp;
    int comp;

    DSU(int n) {
        comp = n;
        pset.resize(n+1);
        fto(i, 1, n)
            pset[i] = i;
        opp.assign(n+1, -1);
    }

    int findSet(int i) {
        return (pset[i] == i) ? i : pset[i] = findSet(pset[i]);
    }

    bool unionSet(int u, int v) {
        int p = findSet(u), q = findSet(v);
        if (p == q) return false;

        if (opp[p] != q) {
            pset[opp[p]] = q;
            pset[opp[q]] = p;
            opp[p] = q;
            opp[q] = p;
            --comp;
        }
        return true;
    }
};

const int MAXN = 5005;
const int MAXX = 10005;
const int MOD = 1000000007;

int n, x[MAXN], y[MAXN];
vector<ii> e[MAXX];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(u, 1, n) scanf("%d%d", &x[u], &y[u]);

    fto(u, 1, n)
        fto(v, u, n)
            e[abs(x[u]-x[v]) + abs(y[u]-y[v])].pb(mp(u, v));

    DSU s(n);

    int curComp = s.comp;
    fdto(x, MAXX-1, 0) {
        bool ok = true;
        for(ii p: e[x]) {
            int u = p.ff, v = p.ss;
            if (!s.unionSet(u, v))
                ok = false;
        }

        if (!ok) {
            printf("%d\n", x);
            int cnt = 1;
            fto(i, 1, curComp)
                cnt = (cnt*2)%MOD;
            printf("%d\n", cnt);
            break;
        } else {
            curComp = s.comp;
        }
    }

    return 0;
}