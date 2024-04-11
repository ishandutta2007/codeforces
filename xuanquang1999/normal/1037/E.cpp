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

struct Edge {
    int u, v;
    bool avail;
};

const int MAXN = 2e5 + 5;

int n, m, k, deg[MAXN], ans[MAXN], cnt;
vector<int> g[MAXN];
Edge e[MAXN];
bool avail[MAXN];

void del(int s) {
    if (avail[s] == false) return;

    avail[s] = false;
    --cnt;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for(int i: g[u]) {
            if (e[i].avail == false) continue;
            e[i].avail = false;
            int v = e[i].u + e[i].v - u;
            if (avail[v]) {
                --deg[v];
                if (deg[v] < k) {
                    avail[v] = false;
                    --cnt;
                    q.push(v);
                }
            }
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    fto(i, 1, m) {
        scanf("%d%d", &e[i].u, &e[i].v);
        e[i].avail = true;
        g[e[i].u].pb(i); g[e[i].v].pb(i);
    }

    cnt = n;
    fto(u, 1, n) {
        deg[u] = sz(g[u]);
        avail[u] = true;
    }

    fto(u, 1, n) {
        if (deg[u] < k) del(u);
    }

    ans[m] = cnt;
    fdto(i, m, 2) {
        if (e[i].avail) {
            e[i].avail = false;
            int u = e[i].u, v = e[i].v;
            --deg[u]; --deg[v];
            if (deg[u] < k) del(u);
            if (deg[v] < k) del(v);
        }
//        debug(i);
//        fto(u, 1, n) printf("%d %d\n", avail[u], deg[u]);
        ans[i-1] = cnt;
    }

    fto(i, 1, m) printf("%d\n", ans[i]);

    return 0;
}