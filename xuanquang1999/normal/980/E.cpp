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
#define maxN 1000005
#define MOD 1000
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()
#define maxX 100000000

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

int n, m, k, p[maxN], d[maxN], master, cnt;
vector<int> g[maxN];
vector<vector<int> > b;
bool marked[maxN];

void DFS(int u) {
    for(int v: g[u]) {
        if (p[u] == v) continue;
        p[v] = u;
        d[v] = d[u]+1;
        DFS(v);
    }
}

void init() {
    k = log2(n);
    b.assign(k+1, vector<int>(n+1, 0));
    fto(u, 1, n) b[0][u] = p[u];
    fto(i, 1, k)
        fto(u, 1, n) b[i][u] = b[i-1][b[i-1][u]];
}

int query(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    int t = d[u]-d[v];
    fto(i, 0, k)
        if ((t>>i)&1) u = b[i][u];

    fdto(i, k, 0) {
        if (b[i][u] != b[i][v]) {
            u = b[i][u]; v = b[i][v];
        }
    }

    if (u == v) return u;
    fto(i, 0, k)
        if (b[i][u] == b[i][v]) return b[i][u];
}

int near(int u) {
    fdto(i, k, 0) {
        if (b[i][u] != 0 && d[b[i][u]] >= d[master] && !marked[b[i][u]]) u = b[i][u];
    }
    fto(i, 0, k)
        if (marked[b[i][u]]) return b[i][u];
}

void mark(int u) {
    while (!marked[u]) {
        marked[u] = true;
        ++cnt;
        u = p[u];
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    m = n-m;
    fto(i, 1, n-1) {
        int u, v; scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    DFS(1);
    init();

    marked[n] = true;
    master = n;

    cnt = 1;
    fdto(u, n-1, 1) {
        if (!marked[u]) {
            int a = query(u, master);
//            printf("%d %d %d\n", master, u, a);
            if (a == master) {
                a = near(u);
//                debug(a);
                if (cnt+d[u]-d[a] <= m) mark(u);
            } else {
                if (cnt+d[u]+d[master]-2*d[a] <= m) {
                    marked[a] = true;
                    ++cnt;
                    mark(u);
                    mark(p[master]);
                    master = a;
                }
            }
        }
    }

    vector<int> ans;
    fto(u, 1, n) {
        if (!marked[u]) ans.pb(u);
    }

    for(int u: ans) printf("%d ", u);


    return 0;
}