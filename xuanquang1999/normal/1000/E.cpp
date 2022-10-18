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
#define MOD 998244353
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
    int u, v;
    bool avail;
};

int n, m, low[maxN], num[maxN], dfsCnt, nComp, d[maxN];
vector<int> g[maxN], bridge, t[maxN];
Edge e[maxN];

void DFS1(int u, int p) {
    low[u] = num[u] = ++dfsCnt;
    for(int i: g[u]) {
        int v = e[i].u+e[i].v-u;
        if (v == p)
            continue;

        if (!num[v]) {
            DFS1(v, u);
            if (low[v] > num[u])
                bridge.pb(i);
            low[u] = min(low[u], low[v]);
        } else
            low[u] = min(low[u], num[v]);
    }
}

void DFS2(int u) {
    for(int i: g[u]) {
        if (!e[i].avail) continue;
        int v = e[i].u+e[i].v-u;
        if (!num[v]) {
            num[v] = num[u];
            DFS2(v);
        }
    }
}

void DFS3(int u, int p) {
    for(int v: t[u]) {
        if (v == p) continue;
        d[v] = d[u]+1;
        DFS3(v, u);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        scanf("%d%d", &e[i].u, &e[i].v);
        g[e[i].u].pb(i); g[e[i].v].pb(i);
        e[i].avail = true;
    }

    DFS1(1, -1);

    for(int i: bridge) e[i].avail = false;

//    for(int i: bridge) printf("%d ", i);
//    puts("");

    memset(num, 0, sizeof num);
    fto(u, 1, n) {
        if (!num[u]) {
            num[u] = ++nComp;
            DFS2(u);
        }
    }

//    fto(u, 1, n) printf("%d ", num[u]);
//    puts("");

    for(int i: bridge) {
        int p = num[e[i].u], q = num[e[i].v];
        t[p].pb(q); t[q].pb(p);
    }

    int root = 1;
    fto(iter, 1, 2) {
        d[root] = 0;
        DFS3(root, -1);
        root = max_element(d+1, d+nComp+1)-d;
    }

    printf("%d", d[root]);

    return 0;
}