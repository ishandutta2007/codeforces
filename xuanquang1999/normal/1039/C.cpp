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

const int MAXN = 500005;
const int MOD = 1e9 + 7;

int n, m, k, cc;
ll a[MAXN], e2[MAXN];
map<ll, vector<ii> > ma;
vector<int> g[MAXN], save;
bool visited[MAXN];

void DFS(int u) {
    visited[u] = true;
    for(int v: g[u]) {
        if (!visited[v]) DFS(v);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    fto(u, 1, n) scanf("%lld", &a[u]);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        ma[a[u]^a[v]].pb(mp(u, v));
    }

    e2[0] = 1;
    fto(u, 1, MAXN-1) e2[u] = (e2[u-1]*2)%MOD;

    ll cnt = (1LL<<k);

    int ans = 0;
    forit(it, ma) {
        --cnt;
        vector<ii> e = it->ss;
        for(ii p: e) {
            int u = p.ff, v = p.ss;
            g[u].pb(v);
            g[v].pb(u);
            if (!visited[u]) {
                visited[u] = true;
                save.pb(u);
            }
            if (!visited[v]) {
                visited[v] = true;
                save.pb(v);
            }
        }

        for(int u: save) visited[u] = false;

        cc = n - sz(save);
        for(int u: save) {
            if (!visited[u]) {
                ++cc;
                DFS(u);
            }
        }

        ans = (ans + e2[cc])%MOD;

        for(int u: save) {
            visited[u] = false;
            g[u].clear();
        }
        save.clear();
//        printf("%lld %d\n", it->ff, cc);
    }

    cnt %= MOD;
    ans = (ans + e2[n]*cnt)%MOD;

    printf("%d", ans);

    return 0;
}