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

int power(int x, int n) {
    if (n == 0) return 1;
    if (n&1) return (1LL*x*power(x, n-1))%MOD;
    int p = power(x, n/2);
    return (1LL*p*p)%MOD;
}

int inv(int x) {return power(x, MOD-2);}

struct Node {
    int prod, sum, val;
};

struct IT {
private: vector<Node> t; int n;
    void propagate(int id) {
        int x = t[id].val;
        if (t[id].val != 1) {
            fto(i, 0, 1) {
                t[2*id+i].prod = (1LL*t[2*id+i].prod*x)%MOD;
                t[2*id+i].sum = (1LL*t[2*id+i].sum*x)%MOD;
                t[2*id+i].val = (1LL*t[2*id+i].val*x)%MOD;
            }
            t[id].val = 1;
        }
    }
    void mul(int id, int l, int r, int i, int j, int x) {
        if (l > j || r < i) return;
        if (i <= l && r <= j) {
            t[id].prod = (1LL*t[id].prod*x)%MOD;
            t[id].sum = (1LL*t[id].sum*x)%MOD;
            t[id].val = (1LL*t[id].val*x)%MOD;
            return;
        }
        propagate(id);
        int m = (l+r)/2;
        mul(2*id, l, m, i, j, x); mul(2*id+1, m+1, r, i, j, x);
        t[id].sum = (t[2*id].sum+t[2*id+1].sum)%MOD;
    }
    void add(int id, int l, int r, int p, int x) {
        if (l > p || r < p) return;
        if (l == p && r == p) {
            t[id].sum = (t[id].sum+1LL*x*t[id].prod)%MOD;
            return;
        }
        propagate(id);
        int m = (l+r)/2;
        add(2*id, l, m, p, x); add(2*id+1, m+1, r, p, x);
        t[id].sum = (t[2*id].sum + t[2*id+1].sum)%MOD;
    }
    int querySum(int id, int l, int r, int i, int j) {
        if (l > j || r < i) return 0;
        if (i <= l && r <= j) return t[id].sum;
        propagate(id);
        int m = (l+r)/2;
        return (querySum(2*id, l, m, i, j)+querySum(2*id+1, m+1, r, i, j))%MOD;
    }
    int queryProd(int id, int l, int r, int p) {
        if (l == p && r == p) return t[id].prod;
        propagate(id);
        int m = (l+r)/2;
        if (p <= m) return queryProd(2*id, l, m, p);
        return queryProd(2*id+1, m+1, r, p);
    }
public:
    IT(int n): n(n) {t.assign(4*n+1, {1, 0, 1});}
    void add(int p, int x) {add(1, 1, n, p, x);}
    void mul(int l, int r, int x) {mul(1, 1, n, l, r, x);}
    int querySum(int l, int r) {return querySum(1, 1, n, l, r);}
    int queryProd(int p) {return queryProd(1, 1, n, p);}
};

int n, q, type[maxN], vtx[maxN], val[maxN];
int dfsCnt, in[maxN], out[maxN], par[maxN], siz[maxN];
vector<int> g[maxN];

void DFS(int u) {
    in[u] = ++dfsCnt;
    for(int v: g[u]) DFS(v);
    out[u] = dfsCnt;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &val[++n], &q);
    fto(i, 1, q) {
        scanf("%d", &type[i]);
        if (type[i] == 1) {
            scanf("%d%d", &par[n], &val[++n]);
            vtx[i] = n;
            g[par[n]].pb(n);
        } else scanf("%d", &vtx[i]);
    }

    DFS(1);

    IT t(n);

    siz[1] = 1;
    t.add(in[1], val[1]);

    fto(i, 1, q) {
        int u = vtx[i];
        if (type[i] == 1) {
            int p = par[u];
            int toMul = (1LL*(siz[p]+1)*inv(siz[p]))%MOD;
            t.mul(in[p], out[p], toMul);
            t.add(in[u], val[u]);
            ++siz[p]; ++siz[u];
        } else {
            int ans = t.querySum(in[u], out[u]);
            int prefProd = (u == 1) ? 1 : t.queryProd(in[par[u]]);
            ans = (1LL*ans*inv(prefProd))%MOD;
            printf("%d\n", ans);
        }
    }

    return 0;
}