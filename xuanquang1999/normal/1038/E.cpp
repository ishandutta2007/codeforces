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

const int MAXN = 4;
const int MAXM = 100;
const int oo = 1e9 + 7;

struct Edge {
    int u, v, w;
    bool avail;
};

int n, m, deg[MAXN], sumW, siz, ans;
vector<int> g[MAXM], vtx;
set<int> id, id2;
Edge e[MAXM];
bool visited[MAXN], marked[MAXN];

void DFS(int u) {
    visited[u] = true;
    vtx.pb(u);

    for(int i: g[u]) {
        int v = e[i].u + e[i].v - u;
        id.insert(i);
        if (!visited[v])
            DFS(v);
    }
}

void DFS_Check(int u) {
    marked[u] = true;
    for(int i: g[u]) {
        if (!e[i].avail) continue;
        id2.insert(i);
        int v = e[i].u + e[i].v - u;
        if (!marked[v])
            DFS_Check(v);
    }
}

void Check() {
    memset(marked, false, sizeof marked);
    for(int v: vtx) {
        if (marked[v]) continue;
        id2.clear();
        DFS_Check(v);

        vector<int> deg(n, 0);
        int sumW = 0;
        for(int i: id2) {
            sumW += e[i].w;
            ++deg[e[i].u];
            ++deg[e[i].v];
        }

        int cnt = 0;
        fto(u, 0, n-1)
            if (deg[u]%2 == 1) ++cnt;

        if (cnt <= 2)
            ans = max(ans, sumW);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    n = 4;
    scanf("%d", &m);
    fto(i, 0, m-1) {
        scanf("%d%d%d", &e[i].u, &e[i].w, &e[i].v);
        --e[i].u; --e[i].v;
        e[i].avail = true;
        g[e[i].u].pb(i);
        if (e[i].u != e[i].v)
            g[e[i].v].pb(i);
    }

    fto(u, 0, n-1) {
        if (!visited[u]) {
//            debug(u);
            DFS(u);

            int sumW = 0;
            for(int i: id) {
                sumW += e[i].w;
                ++deg[e[i].u]; ++deg[e[i].v];
            }

            int cnt = 0;
            for(int v: vtx)
                if (deg[v]%2 == 1) ++cnt;

            if (cnt > 2) {
                for(int i: id) {
                    e[i].avail = false;
                    Check();
                    e[i].avail = true;
                }
            } else
                ans = max(ans, sumW);

            id.clear();
            vtx.clear();
        }
    }

    printf("%d", ans);

    return 0;
}