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

int n, m, k, d[maxN], p[maxN], pp[maxN], color[maxN], index[maxN];
vector<int> g[maxN];
vector<ii> be;
map<ii, int> e;
bool ok[maxN];

void DFS(int u) {
    color[u] = 1;
    for(int v: g[u]) {
        if (v == p[u]) continue;
        if (color[v] == 0) {
            p[v] = u;
            d[v] = d[u]+1;
            DFS(v);
        } else if (color[v] == 1) {
            be.pb(mp(u, v));
        }
    }
    color[u] = 2;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        e[mp(u, v)] = e[mp(v, u)] = i;
        g[u].pb(v); g[v].pb(u);
    }

    fto(u, 1, n) {
        if (color[u] == 0) DFS(u);
    }

//    for(ii p: be) printf("%d %d\n", p.ff, p.ss);

    k = sz(be);
    fto(u, 1, n) pp[u] = p[u];

    fill(begin(index), end(index), -1);
    fill(begin(ok), end(ok), true);

    fto(i, 0, k-1) {
        vector<int> path;
        for(int u = be[i].ff; d[u] > d[be[i].ss]; u = p[u]) {
            if (index[u] == -1)
                index[u] = i;
            else
                ok[i] = ok[index[u]] = false;
            path.pb(u);
        }
        for(int u: path)
            p[u] = be[i].ss;
    }

    set<int> ans;
    fto(i, 0, k-1) {
        if (ok[i]) {
            ans.insert(e[be[i]]);
            for(int u = be[i].ff; u != be[i].ss; u = pp[u])
                ans.insert(e[mp(u, pp[u])]);
        }
    }

    printf("%d\n", sz(ans));
    for(int u: ans) printf("%d ", u);

    return 0;
}