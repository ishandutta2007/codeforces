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
#define maxK 17
#define maxX 10000005
#define MOD 1000000007
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

int power(int x, int n) {
    if (n == 0) return 1;
    if (n&1) return (1LL*x*power(x, n-1))%MOD;
    int p = power(x, n/2);
    return (1LL*p*p)%MOD;
}

int GCD(int a, int b) {return (b == 0) ? a : GCD(b, a%b);}

int sqr(int x) {return (1LL*x*x)%MOD;}

struct Query {
    int x, id, cof;
};

int n, k, q, a[maxN], nxt[maxX], dist[maxN], b[maxK][maxN], inv[maxX], prod[maxX], ans[maxN];
vector<int> g[maxN];
vector<Query> Q[maxN];

void sieve() {
    fto(i, 2, maxX-1) {
        if (nxt[i]) continue;
        nxt[i] = i;

        if (i > maxX/i) continue;
        for(int j = i*i; j < maxX; j += i) {
            if (!nxt[j]) nxt[j] = i;
        }
    }
}

void DFS(int u, int p) {
    b[0][u] = p;
    for(int v: g[u]) {
        if (v == p) continue;
        dist[v] = dist[u]+1;
        DFS(v, u);
    }
}

int getLCA(int u, int v) {
    if (dist[u] < dist[v]) swap(u, v);
    int t = dist[u]-dist[v];
    fto(i, 0, k) {
        if ((t>>i)&1) u = b[i][u];
    }

    fdto(i, k, 0) {
        if (b[i][u] != b[i][v]) {
            u = b[i][u];
            v = b[i][v];
        }
    }
    if (u == v) return u;
    fto(i, 0, k) {
        if (b[i][u] == b[i][v]) return b[i][u];
    }
}

void add(int x) {
    while (x > 1) {
        int p = nxt[x], cur = 1;
        while (nxt[x] == p) {
            cur *= p;
            prod[cur] = (1LL*prod[cur]*p)%MOD;
            x /= p;
        }
    }
}

void remove(int x) {
    while (x > 1) {
        int p = nxt[x], cur = 1;
        while (nxt[x] == p) {
            cur *= p;
            prod[cur] = (1LL*prod[cur]*inv[p])%MOD;
            x /= p;
        }
    }
}

int getProd(int x) {
    int res = 1;
    while (x > 1) {
        int p = nxt[x], cur = 1;
        while (nxt[x] == p) {
            cur *= p;
            res = (1LL*res*prod[cur])%MOD;
            x /= p;
        }
    }
    return res;
}

void Solve(int u, int p) {
    add(a[u]);
//    debug(u);
//    fto(i, 1, 10) printf("%d ", prod[i]);
//    puts("");
    for(Query q: Q[u]) {
        int res = getProd(q.x);
//        printf("%d %d %d %d\n", q.x, q.id, q.cof, res);
        if (q.cof == 1) ans[q.id] = (1LL*ans[q.id]*res)%MOD;
        else ans[q.id] = (1LL*ans[q.id]*power(sqr(res), MOD-2))%MOD;
    }
    for(int v: g[u]) {
        if (v == p) continue;
        Solve(v, u);
    }
    remove(a[u]);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    sieve();

    fto(i, 2, maxX-1) {
        if (nxt[i] == i) inv[i] = power(i, MOD-2);
    }

    scanf("%d", &n);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(v); g[v].pb(u);
    }
    fto(i, 1, n) scanf("%d", &a[i]);

    DFS(1, 0);

    k = log2(n);
    fto(i, 1, k) {
        fto(u, 1, n) b[i][u] = b[i-1][b[i-1][u]];
    }

//    fto(i, 0, k) {
//        fto(u, 1, n) printf("%d ", b[i][u]);
//        puts("");
//    }

    scanf("%d", &q);
    fto(i, 1, q) {
        int u, v, x;
        scanf("%d%d%d", &u, &v, &x);

        int w = getLCA(u, v);
        Q[u].pb({x, i, 1});
        Q[v].pb({x, i, 1});
        Q[w].pb({x, i, -2});
        ans[i] = GCD(x, a[w]);
    }

//    fto(i, 1, 20) printf("%d ", nxt[i]);
//    puts("");

    fto(x, 1, maxX-1) prod[x] = 1;
    Solve(1, 0);

    fto(i, 1, q) printf("%d\n", ans[i]);

    return 0;
}