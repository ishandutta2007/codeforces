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
#define MOD 1000
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

struct Edge {
    int u, v, w;
};

int n, q, f[maxN];
Edge e[maxN];
vector<int> g[maxN], st;
ll down[2][maxN], up[maxN], d[maxN], l;


void CalcDown(int u, int p) {
    if (sz(g[u]) == 1)
        down[0][u] = 0;

    for(int i: g[u]) {
        int v = e[i].u+e[i].v-u, w = e[i].w;
        if (v == p)
            continue;
        CalcDown(v, u);

        ll x = down[0][v]+w;
        if (x > down[0][u]) {
            down[1][u] = down[0][u];
            down[0][u] = x;
        } else
            down[1][u] = max(down[1][u], x);
    }
}

void CalcUp(int u, int p) {
    for(int i: g[u]) {
        int v = e[i].u+e[i].v-u, w = e[i].w;
        if (v == p)
            continue;

        ll maxDown = (down[0][u] == down[0][v]+w) ? down[1][u] : down[0][u];
        up[v] = max(up[u], maxDown) + w;
        CalcUp(v, u);
    }
}

void DFS(int u, int p) {
    st.pb(u);

    ++f[u];
    int lo = 0, hi = sz(st)-1, res = -1;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (d[u]-d[st[mid]] > l) {
            res = mid;
            lo = mid+1;
        } else
            hi = mid-1;
    }
    if (res != -1)
        --f[st[res]];

    for(int i: g[u]) {
        int v = e[i].u+e[i].v-u;
        if (v == p)
            continue;
        DFS(v, u);
        f[u] += f[v];
    }

    st.pop_back();
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n-1) {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        g[e[i].u].pb(i);
        g[e[i].v].pb(i);
    }

    fto(u, 1, n)
        up[u] = down[0][u] = down[1][u] = -oo;
    CalcDown(1, -1);
    CalcUp(1, -1);

    fto(u, 1, n)
        d[u] = max(up[u], down[0][u]);
    int root = min_element(d+1, d+n+1)-d;

//    fto(u, 1, n) printf("%lld %lld %lld\n", up[u], down[0][u], down[1][u]);

//    debug(root);

    scanf("%d", &q);
    fto(i, 1, q) {
        scanf("%lld", &l);
        memset(f, 0, sizeof f);
        DFS(root, -1);

        int ans = *max_element(f+1, f+n+1);
        printf("%d\n", ans);
    }

    return 0;
}