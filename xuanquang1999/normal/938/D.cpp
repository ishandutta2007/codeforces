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
#define maxN 200005
#define oo 1000000000000000007LL
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

int n, m;
vector<pair<int, ll> > g[maxN];
ll a[maxN], d[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v; ll w;
        scanf("%d%d%lld", &u, &v, &w);
        w *= 2;
        g[u].pb(mp(v, w)); g[v].pb(mp(u, w));
    }
    fto(u, 1, n) scanf("%lld", &a[u]);

    set<pair<ll, int> > s;
    fto(u, 1, n) d[u] = a[u];
    fto(u, 1, n) s.insert(mp(d[u], u));

    while (!s.empty()) {
        int u = s.begin()->ss; s.erase(s.begin());
        fto(i, 0, sz(g[u])-1) {
            int v = g[u][i].ff; ll w = g[u][i].ss;
            if (d[v] > d[u]+w) {
                s.erase(mp(d[v], v));
                d[v] = d[u]+w;
                s.insert(mp(d[v], v));
            }
        }
    }

    fto(u, 1, n) printf("%lld ", d[u]);

    return 0;
}