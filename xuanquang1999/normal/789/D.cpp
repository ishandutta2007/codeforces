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
#define maxN 1000005
#define oo 100007
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

int n, m, cntEdge, cntLoop;
bool hasLoop[maxN];
bool visited[maxN];
vector<int> g[maxN];
ii e[maxN];

void DFS(int u) {
    if (hasLoop[u]) ++cntEdge;
    visited[u] = true;
    cntEdge += g[u].size();
    forit(it, g[u]) {
        int v = *it;
        if (!visited[v]) DFS(v);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v; scanf("%d%d", &u, &v);

        if (v != u) {
            g[u].pb(v);
            g[v].pb(u);
        } else {
            ++cntLoop;
            hasLoop[u] = true;
        }

        e[i] = mp(u, v);
    }

    int validComp = 0;
    fto(u, 1, n) {
        if (!visited[u]) {
            cntEdge = 0;
            DFS(u);
            if (cntEdge > 0) ++validComp;
        }
    }

    if (validComp > 1) {
        puts("0");
        return 0;
    }

    ll ans = 0;
    fto(i, 1, m) {
        int u = e[i].ff, v = e[i].ss;
        if (u == v) ans += m-1;
        else ans += g[u].size()+g[v].size()-2+cntLoop;
    }

    cout << ans/2;


    return 0;
}