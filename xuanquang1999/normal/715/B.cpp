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
#define maxN 100005
#define oo 1000000000000000007LL

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

bool cmp(const point &a, const point &b) {
    return a.X < b.X;
}

struct edge {int u, v, w, var;};

int n, m, L, st, en, need;
edge e[maxN];
ll d1[maxN], d2[maxN];
vector<int> g[maxN];

void dijkstra(ll d[], bool secTime) {
    set<pair<ll, int> > s;
    fto(u, 0, n-1) d[u] = oo;
    d[st] = 0;
    s.insert(mp(d[st], st));
    while (!s.empty()) {
        int u = s.begin()->ss; s.erase(s.begin());
        forit(it, g[u]) {
            int i = *it, v = e[i].u + e[i].v - u;
            if (d[v] > d[u]+e[i].w && secTime && e[i].var && d[u]+e[i].w < d1[v]+need)
                e[i].w = d1[v]+need-d[u];
            if (d[v] > d[u]+e[i].w) {
                s.erase(mp(d[v], v));
                d[v] = d[u]+e[i].w;
                s.insert(mp(d[v], v));
            }
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d%d%d", &n, &m, &L, &st, &en);
    fto(i, 0, m-1) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        if (!e[i].w) e[i].w = 1, e[i].var = true;
        g[e[i].u].pb(i); g[e[i].v].pb(i);
    }

    dijkstra(d1, false);
    if (d1[en] > L) {puts("NO"); return 0;}
    need = L-d1[en];
//    fto(u, 0, n-1) printf("%lld ", d1[u]);
//    puts("");

    dijkstra(d2, true);
//    fto(u, 0, n-1) printf("%lld ", d2[u]);
//    puts("");
    if (d2[en] < L) {puts("NO"); return 0;}

    puts("YES");
    fto(i, 0, m-1) printf("%d %d %d\n", e[i].u, e[i].v, e[i].w);

    return 0;
}