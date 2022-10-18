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

struct Node {
    ll sum, val;
};

struct IT {
private:
    vector<Node> t; int n;
    void propagate(int id, int l, int r) {
        ll x = t[id].val;
        if (x != 0) {
            int m = (l+r)/2;
            t[2*id].sum += x*(m-l+1);
            t[2*id].val += x;
            t[2*id+1].sum += x*(r-m);
            t[2*id+1].val += x;
            t[id].val = 0;
        }
    }
    void update(int id, int l, int r, int i, int j, int x) {
        if (j < l || i > r) return;
        if (i <= l && r <= j) {
            t[id].sum += 1LL*x*(r-l+1);
            t[id].val += x;
            return;
        }
        propagate(id, l, r);
        int m = (l+r)/2;
        update(2*id, l, m, i, j, x); update(2*id+1, m+1, r, i, j, x);
        t[id].sum = t[2*id].sum + t[2*id+1].sum;
    }
    ll query(int id, int l, int r, int i, int j) {
        if (j < l || i > r) return 0;
        if (i <= l && r <= j) return t[id].sum;
        propagate(id, l, r);
        int m = (l+r)/2;
        return query(2*id, l, m, i, j)+query(2*id+1, m+1, r, i, j);
    }
public:
    IT(int n): n(n) {t.assign(4*n+1, {0, 0});}
    void update(int l, int r, int x) {update(1, 1, n, l, r, x);}
    ll query(int l, int r) {return query(1, 1, n, l, r);}
};

int n, q, k, dfsCnt, d[maxN], a[maxN], in[maxN], out[maxN], b[20][maxN];
vector<int> g[maxN];

int up(int u, int len) {
    fto(i, 0, k) {
        if ((len>>i)&1) u = b[i][u];
    }
    return u;
}

int lca(int u, int v) {
    if (d[u] < d[v]) swap(u, v);
    u = up(u, d[u]-d[v]);
    fdto(i, k, 0) {
        if (b[i][u] != b[i][v]) {
            u = b[i][u]; v = b[i][v];
        }
    }
    if (u == v) return u;
    fto(i, 0, k) {
        if (b[i][u] == b[i][v]) return b[i][u];
    }
}

int go(int s, int t, int len) {
    int a = lca(s, t);
    int x;
    if (d[s]-d[a] > len) x = up(s, len);
    else x = up(t, d[s]+d[t]-2*d[a]-len);
    return x;
}

int dist(int u, int v) {
    return d[u]+d[v]-2*d[lca(u, v)];
}

int lca(int r, int u, int v) {
    int x = dist(u, r), y = dist(v, r);
    if (x > y) u = go(u, r, x-y);
    else if (x < y) v = go(v, r, y-x);

    fdto(i, k, 0) {
        x = go(u, r, (1<<i));
        y = go(v, r, (1<<i));
        if (x != y) {
            u = x;
            v = y;
        }
    }

    if (u == v) return u;
    fto(i, 0, k) {
        x = go(u, r, (1<<i));
        y = go(v, r, (1<<i));
        if (x == y) return x;
    }
}

void DFS(int u) {
    in[u] = ++dfsCnt;
    for(int v: g[u]) {
        if (v == b[0][u]) continue;
        b[0][v] = u;
        d[v] = d[u]+1;
        DFS(v);
    }
    out[u] = dfsCnt;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    k = log2(n);
    fto(i, 1, n) scanf("%d", &a[i]);

    fto(i, 1, n-1) {
        int u, v; scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }

    DFS(1);

    fto(i, 1, k)
        fto(u, 1, n) b[i][u] = b[i-1][b[i-1][u]];

    IT t(n);
    fto(u, 1, n) t.update(in[u], in[u], a[u]);
    int root = 1;

    fto(i, 1, q) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int u; scanf("%d", &u);
            root = u;
        } else if (type == 2) {
            int u, v, x; scanf("%d%d%d", &u, &v, &x);
            int a = lca(root, u, v);
            if (in[a] <= in[root] && out[root] <= out[a]) {
                t.update(1, n, x);
                if (a != root) {
                    int nxt = up(root, d[root]-d[a]-1);
                    t.update(in[nxt], out[nxt], -x);
                }
            } else t.update(in[a], out[a], x);
        } else {
            int u; scanf("%d", &u);

            ll ans;
            if (in[u] <= in[root] && out[root] <= out[u]) {
                ans = t.query(1, n);
                if (u != root) {
                    int nxt = up(root, d[root]-d[u]-1);
                    ans -= t.query(in[nxt], out[nxt]);
                }
            } else ans = t.query(in[u], out[u]);
            printf("%lld\n", ans);
        }
    }

    return 0;
}