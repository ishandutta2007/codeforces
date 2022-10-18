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
#define maxN 100005
#define oo 2000000007
#define EPS 1e-9
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

int n, k, f[2][maxN];
vector<ii> g[maxN];
bool inVF[maxN];

void DFS(int u, int p, int wUV) {
    vector<ii> vf;
    forit(it, g[u]) {
        int v = it->ff, w = it->ss;
        if (v != p) {
            DFS(v, u, w);
            vf.pb(mp(f[0][v], v));
        }
    }
    sort(vf.rbegin(), vf.rend());

    int sum = 0;
    fto(i, 0, min(k-2, sz(vf)-1)) {
        sum += vf[i].ff;
        inVF[vf[i].ss] = true;
    }
    f[1][u] = f[0][u] = sum;

    forit(it, g[u]) {
        int v = it->ff, w = it->ss;
        if (v != p) {
            int nSum = sum + f[1][v];
            if (inVF[v]) {
                nSum -= f[0][v];
                if (vf.size() >= k) nSum += vf[k-1].ff;
            }
            f[1][u] = max(f[1][u], nSum);
        }
    }

    fto(i, 0, min(k-2, sz(vf)-1)) inVF[vf[i].ss] = false;

    fto(i, 0, 1) f[i][u] += wUV;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, n-1) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g[u].pb(mp(v, w)); g[v].pb(mp(u, w));
    }

    DFS(0, -1, 0);

    printf("%d", f[1][0]);

    return 0;
}