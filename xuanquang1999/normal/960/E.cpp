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
#define MOD 1000000007
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

ll add(ll &a, ll b) {
    a = ((a+b)%MOD + MOD)%MOD;
}

int n, v[maxN], dp[2][maxN];
ll f[maxN];
vector<int> g[maxN];

void preDFS(int u, int p, int col) {
    dp[col][u] = 1;
    for(int v: g[u]) {
        if (v == p) continue;
        preDFS(v, u, 1-col);
        fto(c, 0, 1) dp[c][u] += dp[c][v];
    }
}

void DFS(int u, int p, int col) {
    vector<int> cnt[2];

    for(int v: g[u]) {
        if (v == p) continue;
        DFS(v, u, 1-col);
        fto(c, 0, 1) cnt[c].pb(dp[c][v]);
    }

    fto(c, 0, 1) cnt[c].pb(dp[c][1]-dp[c][u]);

    add(f[u], n);
    fto(i, 0, sz(cnt[col])-1) {
        int x2 = n-(cnt[0][i]+cnt[1][i]);
        add(f[u], 1LL*cnt[col][i]*x2);
        add(f[u], -1LL*cnt[1-col][i]*x2);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &v[i]);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    preDFS(1, -1, 1);

    DFS(1, -1, 1);

    ll ans = 0;
    fto(u, 1, n) add(ans, v[u]*f[u]);
    cout << ans;

    return 0;
}