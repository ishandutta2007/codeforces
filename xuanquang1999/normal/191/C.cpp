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
#define sz(a) (int)a.size()
#define maxN 100005
#define maxK 20
#define oo 1000000000000000007LL
#define MOD 1000000007
#define EPS 1e-9

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

int n, k, q, p[maxN], d[maxN], first[maxN], ans[maxN], f[maxN];
vector<int> tour, b[maxK];
vector<ii> g[maxN];

void DFS(int u) {
    first[u] = sz(tour);
    tour.pb(u);
    forit(it, g[u]) {
        int v = it->ff;
        if (v != p[u]) {
            p[v] = u;
            d[v] = d[u]+1;
            DFS(v);
            tour.pb(u);
        }
    }
}

int comp(int x, int y) {
    return (d[tour[x]] < d[tour[y]]) ? x : y;
}

int query(int l, int r) {
    int i = log2(r-l+1);
    return comp(b[i][l], b[i][r-(1<<i)+1]);
}

int LCA(int x, int y) {
    if (first[x] > first[y]) swap(x, y);
    return tour[query(first[x], first[y])];
}

void DFS2(int u) {
    forit(it, g[u]) {
        int v = it->ff, id = it->ss;
        if (v != p[u]) {
            DFS2(v);
            f[u] += f[v];
            ans[id] = f[v];
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(mp(v, i)); g[v].pb(mp(u, i));
    }

    DFS(1);
//    forit(it, tour) printf("%d ", *it);
//    puts("");
    k = log2(sz(tour));
    fto(i, 0, k) b[i].resize(sz(tour));

    fto(j, 0, sz(tour)-1) b[0][j] = j;
    fto(i, 1, k)
        fto(j, 0, sz(tour)-(1<<i))
            b[i][j] = comp(b[i-1][j], b[i-1][j+(1<<(i-1))]);


//    fto(i, 0, k) {
//        fto(j, 0, sz(tour)-(1<<i)) printf("%d ", b[i][j]);
//        puts("");
//    }



    scanf("%d", &q);
    fto(i, 1, q) {
        int u, v;
        scanf("%d%d", &u, &v);
        int a = LCA(u, v);
//        printf("%d %d %d\n", u, v, a);
        ++f[u]; ++f[v];
        f[a] -= 2;
    }

    DFS2(1);

    fto(i, 1, n-1) printf("%d ", ans[i]);

    return 0;
}