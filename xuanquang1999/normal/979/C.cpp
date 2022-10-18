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
#define maxN 300005
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

int n, x, y, par[maxN];
vector<int> g[maxN];
bool blocked[maxN];

void DFS(int u) {
    for(int v: g[u]) {
        if (v == par[u]) continue;
        par[v] = u;
        DFS(v);
    }
}

void DFS2(int u, int p, int &cnt) {
    ++cnt;
    for(int v: g[u]) {
        if (v == p) continue;
        if (!blocked[v]) DFS2(v, u, cnt);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &x, &y);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    DFS(x);

    for(int v = y; v != x; v = par[v]) blocked[v] = true;
    blocked[x] = true;

    int cntX = 0, cntY = 0;
    DFS2(x, -1, cntX);
    DFS2(y, -1, cntY);

    ll ans = 1LL*n*(n-1) - 1LL*cntX*cntY;
    cout << ans;

    return 0;
}