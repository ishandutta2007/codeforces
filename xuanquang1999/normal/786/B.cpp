//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
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
#define oo 1000000000000000007LL
#define maxN 100005
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

int n, q, s;
ll d[9*maxN];
vector<ii> g[9*maxN];

void addITEdge(int id, int l, int r) {
    if (l == r) {
        g[n+id].pb(mp(l, 0));
        g[l].pb(mp(5*n+id, 0));
    } else {
        int m = (l+r)/2;
        g[n+id].pb(mp(n+2*id, 0)); g[n+id].pb(mp(n+2*id+1, 0));
        g[5*n+2*id].pb(mp(5*n+id, 0)); g[5*n+2*id+1].pb(mp(5*n+id, 0));
        addITEdge(2*id, l, m); addITEdge(2*id+1, m+1, r);
    }
}

void getID(int id, int l, int r, int i, int j, vector<int> &res) {
    if (i > r || j < l) return;
    if (i <= l && r <= j) {
        res.pb(id);
        return;
    }
    int m = (l+r)/2;
    getID(2*id, l, m, i, j, res); getID(2*id+1, m+1, r, i, j, res);
}

vector<int> getID(int l, int r) {
    vector<int> res;
    getID(1, 1, n, l, r, res);
    return res;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &q, &s);
    addITEdge(1, 1, n);
    fto(i, 1, q) {
        int t, v, l, r, w;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d%d", &l, &r, &w);
            g[l].pb(mp(r, w));
        } else {
            scanf("%d%d%d%d", &v, &l, &r, &w);
            vector<int> id = getID(l, r);
            forit(it, id) {
                if (t == 2) g[v].pb(mp(n+*it, w));
                else g[5*n+*it].pb(mp(v, w));
            }
        }
    }

    fto(i, 1, 9*n) d[i] = oo;
    d[s] = 0;

//    fto(u, 1, 9*n) {
//        debug(u);
//        forit(it, g[u]) printf("%d %d\n", it->ff, it->ss);
//    }

    set<pair<ll, int> > S;
    S.insert(mp(d[s], s));
    while (!S.empty()) {
        int u = S.begin()->ss; S.erase(S.begin());
        forit(it, g[u]) {
            int v = it->ff, w = it->ss;
            if (d[v] > d[u]+w) {
                S.erase(mp(d[v], v));
                d[v] = d[u]+w;
                S.insert(mp(d[v], v));
            }
        }
    }

    fto(u, 1, n) printf("%lld ", ((d[u] == oo) ? -1 : d[u]));

    return 0;
}